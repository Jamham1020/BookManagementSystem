/**
 * Filename: Group5_FinalProjectTest3.cpp
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
#include "book.h"
#include "screens.h"

using namespace std;

int main()
{
  const int MAX_SIZE = 100;
  int size = 0;
  int choice;
  book books[MAX_SIZE];

  // if you guys want, we can change the title to something else.
  // I really don't have the creativity to think of a cool name right now.
  cout << "****** Chaffey Library/BookStore Management System ******\n";
  do
  {

    cout << "1: Read inventory from file" << endl;
    cout << "2: Display Library" << endl;
    cout << "3: Update an entry" << endl;
    cout << "4: Add an entry" << endl;
    cout << "5: Sort inventory" << endl;
    cout << "6: Delete an entry" << endl;
    cout << "7: Write inventory to file and exit" << endl;
    //cout << "8: Notes" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      choice1(books, size, MAX_SIZE);
      break;
    case 2:
      choice2(books, size);
      break;
    case 3:
      choice3(books, size);
      break;
    case 4:
      choice4(books, size, MAX_SIZE);
      break;
    case 5:
      choice5(books, size);
      break;
    case 6:
      choice6(books, size);
      break;
    case 7:
      choice7(books, size);
      cout << "Thank you and have a nice day!" << endl;
      break;
    default:
      cout << "Invalid choice!" << endl;
    }
    cout << endl;
  } while (choice != 7);

  system("pause");
  return 0;
}
