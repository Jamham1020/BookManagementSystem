#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "book.h"
#include "screens.h"

using namespace std;

// choice 1: read the files
void choice1(book books[], int &size, int MAX_SIZE)
{
  ifstream inFile;
  inFile.open("library.dat"); //save data into one file
  string str;

  while (inFile && size < MAX_SIZE)
  {
    getline(inFile, str);
    books[size].ISBN = atoi(str.c_str());

    getline(inFile, books[size].Author);

    getline(inFile, books[size].Title);

    getline(inFile, str);
    books[size].Quantity = atoi(str.c_str());

    getline(inFile, str);
    books[size].price = atoi(str.c_str());

    getline(inFile, str);
    size++;
  }

  cout << "You have successfully read the file." << endl;
  inFile.close();
}
// choice 2: display the library
void choice2(book books[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << endl;
    cout << "Book Number: " << (i + 1) << endl;
    cout << "ISBN: " << books[i].ISBN << endl;
    cout << "Author: " << books[i].Author << endl;
    cout << "Title: " << books[i].Title << endl;
    cout << "Quantity: " << books[i].Quantity << endl;
    cout << "Price: $" << books[i].price << endl;
    cout << "Notes: " << books[i].notes << endl;
  }

  if (size != 0)
    cout << "You have successfully printed the array." << endl;
  else
    cout << "Array is empty. Read the file first." << endl;
}
// choice 3: Update the library entry
void choice3(book books[], int size)
{
  if (size == 0)
    cout << "There is nothing in the inventory at this time. Please enter an entry." << endl;
  else
  {
    int isbn;
    int option;
    int qty;
    string notes;

    cout << "\nEnter the ISBN of the book: ";
    cin >> isbn;

    cout << "1. Increment" << endl;
    cout << "2. Decrement" << endl;
    cout << "3. Add New Quantity" << endl;
    cout << "4. Edit Notes" << endl;
    cout << "Enter your option: ";
    cin >> option;

    cout << "Enter the quantity: ";
    cin >> qty;

    for (int i = 0; i < size; i++)
    {
      if (books[i].ISBN == isbn)
      {
        if (option == 1)
          books[i].Quantity += qty;
        else if (option == 2)
        {
          books[i].Quantity -= qty;

          if (books[i].Quantity)
            books[i].Quantity = 0;
        }
        else if (option == 3)
          books[i].Quantity = qty;

        break;
      }
    }

    cout << "You have successfully updated the array." << endl;
  }
}
//choice 4: Add another book for the library/ bookstore
void choice4(book books[], int &size, int MAX_SIZE)
{
  if (size < MAX_SIZE)
  {
    string str;

    cout << "\nEnter the book ISBN: ";
    cin >> books[size].ISBN;

    cout << "Enter the author name: ";
    cin >> books[size].Author;

    cout << "Enter the book title: ";
    cin >> books[size].Title;
    cin.get();
    //cout << endl;

    cout << "Enter the books quantity: ";
    cin >> books[size].Quantity;

    cout << "Enter the book price: $";
    cin >> books[size].price;

    cout << "Notes: ";
    cin >> books[size].notes;

    size++;
    cout << "You have successfully inserted an entry." << endl;
  }
}
// choice 5: sort the library
void choice5(book books[], int size)
{
  for (int i = 1; i < size; i++)
  {
    book current = books[i];
    int j = i;
    while (j > 0 && (books[j - 1].Title).compare(current.Title) > 0)
    {
      books[j] = books[j - 1];
      j--;
    }
    books[j] = current;
  }

  if (size != 0)
    cout << "You have successfully sorted the library." << endl;
  else
    cout << "Library is empty. Please enter an entry first." << endl;
}
// choice 6:
void choice6(book books[], int &size)
{
  if (size == 0)
    cout << "Array is empty. Read the data first." << endl;
  else
  {
    int isbn;

    cout << "\nEnter the ISBN of the book: ";
    cin >> isbn;

    for (int i = 0; i < size; i++)
    {
      if (books[i].ISBN == isbn)
      {
        int j = i;
        while (j < size - 1)
        {
          books[j] = books[j + 1];
          j++;
        }

        size--;
        break;
      }
    }

    cout << "You have successfully deleted an entry." << endl;
  }
}

void choice7(book books[], int size)
{
  ofstream outFile;
  outFile.open("finalLibrary.dat"); // record every single data into a final file

  for (int i = 0; i < size; i++)
  {
    outFile << "Book Number: " << (i + 1) << endl;
    outFile << "ISBN: " << books[i].ISBN << endl;
    outFile << "Author: " << books[i].Author << endl;
    outFile << "Title: " << books[i].Title << endl;
    outFile << "Quantity: " << books[i].Quantity << endl;
    outFile << "Price: $" << books[i].price << endl
            << endl;
  }

  if (size != 0)
    cout << "You have successfully printed all the data into the library." << endl;
  else
    cout << "Array is empty. Read the file first." << endl;

  outFile.close();
}
