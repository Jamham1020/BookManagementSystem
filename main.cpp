/**
 * Filename: main.cpp
 *
 * Description: A simple book management program that add, edit, removes books,
 *   shows the lists of books, add a note for book log, mark reading status, etc.
 *
 * Authors: Janet Pham, Yong Gyun Kim, Erika Meza, Marwa Naghmouchi, Vernon Neilly
 *
 * Class: COMPSCI-1
 *
 * Date: May 13, 2020
 */
#include <iostream>
#ifdef _WIN32
#include <cstdlib> // for windows pause
#endif

#include "System.h"
#include "screens.h"
#include "util.h"

using namespace std;

int main()
{
  System system;
  int choice;

  // Print program information as a title of the program
  ClearScreen();
  PrintProgramInfo();

  // if the program loads the default file
  system.LoadFile();

  do
  {
    cout << endl << "Select options" << endl;
    cout << "  1: Read inventory from file" << endl;
    cout << "  2: Display Library" << endl;
    cout << "  3: Update an entry" << endl;
    cout << "  4: Add an entry" << endl;
    cout << "  5: Sort inventory" << endl;
    cout << "  6: Delete an entry" << endl;
    cout << "  7: Checkout" << endl;

    cout << endl << "  0: Write inventory to file and exit" << endl;

    cout << endl
         << "Enter your choice: ";
    
    // If the input stream has a failed status, clean up for preventing
    // infinity loop.
    if (cin.fail()) {
      ClearInput();
    }

    cin >> choice;

    // restart the loop if the input is invalid
    if (cin.fail()) {
      continue;
    }

    switch (choice)
    {
    case 1:
      LoadInventory(system);
      break;
    case 2:
      ShowBookList(system);
      break;
    case 3:
      UpdateBook(system);
      break;
    case 4:
      AddNewBook(system);
      break;
    case 5:
      SortBooks(system);
      break;
    case 6:
      DeleteBook(system);
      break;
    case 7:
      CheckoutBooks(system);
      break;
    case 0:
      SaveAndQuit(system);
      cout << "Thank you and have a nice day!" << endl;
      break;
    default:
      cout << endl << "Invalid choice!" << endl;
    }
    cout << endl;
  } while (cin.fail() || choice != 0);

#ifdef _WIN32
  // For Windows
  system("pause");
#endif
  return 0;
}
