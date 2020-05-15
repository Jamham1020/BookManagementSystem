/**
 * Filename: screens.cpp
 *
 * Description: Screen implementation for each options of the system.
 *
 * Authors: Janet Pham, Yong Gyun Kim, Erika Meza, Marwa Naghmouchi, Vernon Neilly
 *
 * Class: COMPSCI-1
 *
 * Date: May 14, 2020
 */
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <iomanip>
#include "book.h"
#include "screens.h"

using namespace std;

/**
 * Table display related constraints
 */
const string TABLE_CELL_SEPARATOR = " | ";
const int TABLE_WIDTH_NO = 3;
const int TABLE_WIDTH_ISBN = 15;
const int TABLE_WIDTH_AUTHOR = 16;
const int TABLE_WIDTH_TITLE = 40;
const int TABLE_WIDTH_QTY = 10;
const int TABLE_WIDTH_PRICE = 10;
const int TABLE_WIDTH_NOTES = 20;
const int TABLE_WIDTH = (TABLE_CELL_SEPARATOR.length() * 8) + TABLE_WIDTH_NO + TABLE_WIDTH_ISBN + TABLE_WIDTH_AUTHOR + TABLE_WIDTH_TITLE + TABLE_WIDTH_QTY + TABLE_WIDTH_PRICE + TABLE_WIDTH_NOTES;
const string TABLE_ROW_SEPARTOR = string(TABLE_WIDTH, '-');

/**
 * Load Inventory Screen Implementation
 *
 * @param system
 */
void LoadInventory(System &system)
{
  string input;
  bool isFileValid = false;

  do
  {
    cout << "Type the name of inventory file (current: " << system.GetCurrentFilePath() << "): ";
    cin.ignore();

    getline(cin, input);

    // if the input is empty, cancel the load file and back to the menu.
    if (input == "")
    {
      cout << "Cancel the load. Back to the menu." << endl
           << endl;
      break;
    }

    isFileValid = system.LoadFile(input);
    if (isFileValid == false)
    {
      cout << endl
           << "The file (" << input << ") cannot find. Please check the filename." << endl;
    }
  } while (cin.fail() || (isFileValid == false));

  return;
}

/**
 * Show Book List Screen Implementation
 *
 * @param system
 */
void ShowBookList(System &system)
{
  if (system.books.size() == 0)
  {
    cout << "The list is empty." << endl;
    return;
  }

  // Print header of the table
  cout << TABLE_ROW_SEPARTOR << endl;

  cout << left << TABLE_CELL_SEPARATOR
       << setw(TABLE_WIDTH_NO) << "No." << TABLE_CELL_SEPARATOR
       << setw(TABLE_WIDTH_ISBN) << "ISBN" << TABLE_CELL_SEPARATOR
       << setw(TABLE_WIDTH_AUTHOR) << "Author" << TABLE_CELL_SEPARATOR
       << setw(TABLE_WIDTH_TITLE) << "Title" << TABLE_CELL_SEPARATOR
       << setw(TABLE_WIDTH_QTY) << "Qty" << TABLE_CELL_SEPARATOR
       << setw(TABLE_WIDTH_PRICE) << "Price ($)" << TABLE_CELL_SEPARATOR
       << setw(TABLE_WIDTH_NOTES) << "Notes" << TABLE_CELL_SEPARATOR
       << endl;

  cout << TABLE_ROW_SEPARTOR << endl;

  // Print each books as a row
  for (int i = 0; i < system.books.size(); i++)
  {
    cout << TABLE_CELL_SEPARATOR

         << right << setw(TABLE_WIDTH_NO) << (i + 1) << TABLE_CELL_SEPARATOR

         << left << setw(TABLE_WIDTH_ISBN)
         << truncate(system.books[i].ISBN, TABLE_WIDTH_ISBN) << TABLE_CELL_SEPARATOR

         << setw(TABLE_WIDTH_AUTHOR)
         << truncate(system.books[i].Author, TABLE_WIDTH_AUTHOR) << TABLE_CELL_SEPARATOR

         << setw(TABLE_WIDTH_TITLE)
         << truncate(system.books[i].Title, TABLE_WIDTH_TITLE) << TABLE_CELL_SEPARATOR

         << right << setw(TABLE_WIDTH_QTY)
         << system.books[i].Quantity << TABLE_CELL_SEPARATOR

         << right << setw(TABLE_WIDTH_PRICE)
         << system.books[i].Price << TABLE_CELL_SEPARATOR

         << left << setw(TABLE_WIDTH_NOTES)
         << truncate(system.books[i].Notes, TABLE_WIDTH_NOTES) << TABLE_CELL_SEPARATOR
         << endl;
  }

  cout << TABLE_ROW_SEPARTOR << endl;
  cout << "Total " << system.books.size() << " books listed." << endl;
  return;
}

/**
 * Update Book Screen Implementation
 *
 * @param system
 */
void UpdateBook(System &system)
{
  if (system.books.size() == 0)
  {
    cout << "The list is empty." << endl;
    return;
  }

  string isbn;
  int idx = -1, qty, option;
  string notes;

  do
  {
    ClearInput();
    cout << "\nEnter the ISBN of the book or the book number: ";
    cin >> isbn;

    // find the book using isbn
    for (int i = 0; i < system.books.size(); i++)
    {
      if (system.books[i].ISBN == isbn)
      {
        idx = i;
      }
    }

    // if the book is not existing, check input as book number
    if (idx == -1)
    {
      idx = static_cast<int>(stoi(isbn)) - 1;
      if (idx >= 0 && (system.books.size() <= idx))
      {
        idx = -1;
      }
    }
  } while (cin.fail() || (idx == -1));

  do
  {
    ClearInput();
    cout << "  1. Increment Quantity" << endl;
    cout << "  2. Decrement Quantity" << endl;
    cout << "  3. Add New Quantity" << endl;
    cout << "  4. Edit Notes" << endl
         << endl;

    cout << "Enter your option: ";
    cin >> option;
  } while (cin.fail() || (option >= 5) || (option <= 0));

  // accept input if changing quantity required
  if (option != 4)
  {
    do
    {
      ClearInput();
      cout << "Enter the quantity: ";
      cin >> qty;
    } while (cin.fail());
  }

  // Adjust the quantity of the book.
  if (option == 1)
  {
    system.books[idx].Quantity += qty;
  }
  else if (option == 2)
  {
    system.books[idx].Quantity -= qty;

    if (system.books[idx].Quantity < 0)
    {
      system.books[idx].Quantity = 0;
    }
  }
  else if (option == 3)
  {
    system.books[idx].Quantity = qty;
  }
  else if (option == 4)
  {
    cin.ignore();
    cout << "Enter the note: ";
    getline(cin, system.books[idx].Notes);
  }

  cout << system.books[idx].Title << " updated." << endl;
  return;
}

/**
 * Add new book Screen Implementation
 *
 * @param system
 */
void AddNewBook(System &system)
{
  // create new book as a new information container
  book newBook;
  string input;

  cin.ignore();
  cout << "Enter the book ISBN: ";
  getline(cin, newBook.ISBN);

  cout << "Enter the author name: ";
  getline(cin, newBook.Author);

  cout << "Enter the book title: ";
  getline(cin, newBook.Title);

  do
  {
    if (cin.fail())
    {
      ClearInput();
    }
    cout << "Enter the books quantity: ";
    cin >> newBook.Quantity;
  } while (cin.fail());

  do
  {
    if (cin.fail())
    {
      ClearInput();
    }
    cout << "Enter the book price: $";
    cin >> newBook.Price;
  } while (cin.fail());

  cout << "Notes: ";
  cin.ignore();
  getline(cin, newBook.Notes);
  ClearInput();

  // insert the new book into the list of the book
  system.books.push_back(newBook);

  cout << "You have successfully inserted an entry." << endl;
  return;
}

/**
 * Sort books Screen Implementation
 *
 * @param system
 */
void SortBooks(System &system)
{
  if (system.books.size() == 0)
  {
    cout << "The list is empty." << endl;
    return;
  }

  int option;

  do
  {
    ClearInput();
    cout << "  1. Sort by Title" << endl;
    cout << "  2. Sort by Author" << endl;
    cout << "  3. Sort by Price" << endl;
    cout << "  4. Sort by Quantity" << endl
         << endl;

    cout << "Enter your option: ";
    cin >> option;
  } while (cin.fail() || (option >= 5) || (option <= 0));

  vector<book> books = system.books;

  // sort the book by comapring the previous book
  for (int i = 1; i < books.size(); ++i)
  {
    book current = books.at(i);
    int j = i;
    if (option == 1)
    {
      while (j > 0 && (books[j - 1].Title).compare(current.Title) > 0)
      {
        books[j] = books[j - 1];
        j--;
      }
    }
    else if (option == 2)
    {
      while (j > 0 && (books[j - 1].Author).compare(current.Author) > 0)
      {
        books[j] = books[j - 1];
        j--;
      }
    }
    else if (option == 3)
    {
      while (j > 0 && (books[j - 1].Price < current.Price))
      {
        books[j] = books[j - 1];
        j--;
      }
    }
    else if (option == 4)
    {
      while (j > 0 && (books[j - 1].Quantity < current.Quantity))
      {
        books[j] = books[j - 1];
        j--;
      }
    }
    books[j] = current;
  }
  system.books = books;

  cout << "You have successfully sorted the library." << endl;
  return;
}

/**
 * Delete book Screen Implementation
 *
 * @param system
 */
void DeleteBook(System &system)
{
  if (system.books.size() == 0)
  {
    cout << "The list is empty." << endl;
    return;
  }

  string isbn;
  int idx = -1;
  string notes;

  do
  {
    if (cin.fail())
    {
      ClearInput();
    }
    cout << "\nEnter the ISBN of the book or the book number: ";
    cin >> isbn;

    // find the book using isbn
    for (int i = 0; i < system.books.size(); i++)
    {
      if (system.books[i].ISBN == isbn)
      {
        idx = i;
      }
    }

    // if the book is not existing, check input as book number
    if (idx == -1)
    {
      idx = static_cast<int>(stoi(isbn)) - 1;
      if (idx >= 0 && (system.books.size() <= idx))
      {
        idx = -1;
      }
    }
  } while (cin.fail() || (idx == -1));

  system.books.erase(system.books.begin() + idx);
  cout << "You have successfully deleted an entry." << endl;
  return;
}

/**
 * Save System Screen Implementation
 *
 * @param system
 */
void SaveAndQuit(System &system)
{
  system.SaveFile();
  cout << "You have successfully saved all the data into the library." << endl;
  return;
}

/**
 * Truncate the string by given width
 * 
 * @param str given string
 * @param width substring of the length
 * @return string if the string is longer than the given width, it returns with ellipses.
 */
string truncate(string str, int width)
{
  if (str.length() > width)
  {
    return str.substr(0, width - 3) + "...";
  }
  else
  {
    return str;
  }
}

/**
 * Clear Input for cin stream and getline
 *
 * @return void
 */
void ClearInput()
{
  // reference: https://en.cppreference.com/w/cpp/io/basic_istream/ignore
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return;
}
