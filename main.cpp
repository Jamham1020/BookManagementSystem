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

using namespace std;

int main()
{
  System system;

  // if the program loads the default file
  system.LoadFile();

  int choice;

  // if you guys want, we can change the title to something else.
  // I really don't have the creativity to think of a cool name right now.
  cout << "****** Chaffey Library/BookStore Management System ******" << endl
       << endl;

  do
  {
    cout << "  1: Read inventory from file" << endl;
    cout << "  2: Display Library" << endl;
    cout << "  3: Update an entry" << endl;
    cout << "  4: Add an entry" << endl;
    cout << "  5: Sort inventory" << endl;
    cout << "  6: Delete an entry" << endl;
    cout << "  7: Write inventory to file and exit" << endl;
    //cout << "8: Notes" << endl;

    cout << endl
         << "Enter your choice: ";
    cin >> choice;

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
      SaveAndQuit(system);
      cout << "Thank you and have a nice day!" << endl;
      break;
    default:
      cout << "Invalid choice!" << endl;
    }
    cout << endl;
  } while (choice != 7);

#ifdef _WIN32
  // For Windows
  system("pause");
#endif
  return 0;
}
