/**
 * Filename: System.cpp
 *
 * Description: System implementation. The class handles load/save the file and
 *    hold the list of the books so that the screen can manipulate the data.
 *
 * Authors: Janet Pham, Yong Gyun Kim, Erika Meza, Marwa Naghmouchi, Vernon Neilly
 *
 * Class: COMPSCI-1
 *
 * Date: May 14, 2020
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "System.h"

using namespace std;

const char SEPARATOR = '|';
const int FIELDS_COUNT = 6;
const string FILE_HEADER = "ISBN|Author|Title|Quantity|Price|Notes";

/**
 * Save File implementation
 * 
 * @param filepath
 * @return true when it saves successfully, otherwise, false.
 */
bool System::SaveFile(string filepath)
{
  if (filepath == "")
  {
    filepath = currentFilePath;
  }
  ofstream outFile(filepath);

  outFile << FILE_HEADER << endl;

  for (int i = 0; i < books.size(); ++i)
  {
    book &b = books[i];

    outFile
        << b.ISBN << SEPARATOR
        << b.Author << SEPARATOR
        << b.Title << SEPARATOR
        << b.Quantity << SEPARATOR
        << b.Price << SEPARATOR
        << b.Notes
        << endl;
  }

  outFile.close();
  return true;
}

/**
 * Load File implementation
 * 
 * @param filepath
 * @return true when it saves successfully, otherwise, false.
 */
bool System::LoadFile(string filepath)
{
  if (filepath == "")
  {
    filepath = currentFilePath;
  }
  ifstream inFile(filepath);
  vector<book> newBooks;
  bool validated = false;
  string row;
  string cell;

  if (inFile.is_open())
  {
    while (!inFile.eof())
    {
      if (validated == false)
      {
        getline(inFile, row);

        // sometimes it loads slowly because it is a stream
        // so it skips when it is a empty row
        if (row == "")
        {
          continue;
        }
        else if (row != FILE_HEADER)
        {
          cout << "FILE FORMAT INVALID" << endl;
          break;
        }
        else
        {
          validated = true;
          continue;
        }
      }

      getline(inFile, row);
      if (row == "")
      {
        break;
      }

      stringstream rowStream(row);
      vector<string> bookData;
      int quantity;
      double price;

      while (getline(rowStream, cell, SEPARATOR))
      {
        bookData.push_back(cell);
      }

      if (!rowStream && cell.empty())
      {
        bookData.push_back("");
      }

      // consider the row as corrupted
      if (bookData.size() < FIELDS_COUNT)
      {
        continue;
      }

      // load the book as a struct and add it to the new book list
      quantity = static_cast<int>(stoi(bookData.at(3)));
      price = static_cast<double>(stod(bookData.at(4)));

      book newBook = {
          .ISBN = bookData.at(0),
          .Author = bookData.at(1),
          .Title = bookData.at(2),
          .Quantity = quantity,
          .Price = price,
          .Notes = bookData.at(5),
      };

      newBooks.push_back(newBook);
    }
  }
  else
  {
    return false;
  }

  inFile.close();

  if (validated == false)
  {
    return false;
  }

  // Set the new book list into system and clean up
  books = newBooks;
  currentFilePath = filepath;
  cout << books.size() << " books loaded from " << filepath << "." << endl;
  return true;
}

/**
 * Return current file path
 * 
 * @return string
 */
string System::GetCurrentFilePath()
{
  return currentFilePath;
}
