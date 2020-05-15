/**
 * Filename: screens.h
 *
 * Description: Screen header. It defines the screens of the system.
 *
 * Authors: Janet Pham, Yong Gyun Kim, Erika Meza, Marwa Naghmouchi, Vernon Neilly
 *
 * Class: COMPSCI-1
 *
 * Date: May 14, 2020
 */
#pragma once
#include "System.h"
#include "cartItem.h"

/**
 * Print program information
 * 
 * Print the program name at the beginning of the program.
 *
 * @return void
 */
void PrintProgramInfo();

/**
 * Load Inventory Screen
 * 
 * Load book list from the given file name. The default file name is
 * `books.csv`, however, the user can load any other file name.
 *
 * @param system
 * @return void
 */
void LoadInventory(System &system);

/**
 * Show Book List Screen
 * 
 * Display the current book list as a table format in the system.
 *
 * @param system
 * @return void
 */
void ShowBookList(System &system);

/**
 * Update Book Screen
 *
 * Update book by given user input such as book number or ISBN from
 * the list. The screen helps to maintain information of the system.
 *
 * @param system
 * @return void
 */
void UpdateBook(System &system);

/**
 * Add New Book Screen
 *
 * Add new book information to the system. The user can type each
 * information by following the prompt.
 *
 * @param system
 * @return void
 */
void AddNewBook(System &system);

/**
 * Sort Book Screen
 *
 * Sort the books from the list by given options. The user can sort the
 * list by book's attributes such as title.
 *
 * @param system
 * @return void
 */
void SortBooks(System &system);

/**
 * Delete Book Screen
 *
 * Delete the book from the system by book number or given ISBN.
 *
 * @param system
 * @return void
 */
void DeleteBook(System &system);

/**
 * Checkout Screen
 *
 * Select the books and checkout for the customer who want to purchase the books.
 *
 * @param system
 * @return void
 */
void CheckoutBooks(System &system);


/**
 * Save And Quit Screen
 *
 * Save the current list into the file and prompt the quit message
 * of the system.
 *
 * @param system
 * @return void
 */
void SaveAndQuit(System &system);

/**
 * Print book information
 * 
 * Display detail of the given book on the screen.
 * 
 * @param book
 * @return void
 */
void PrintBook(book &book);

/**
 * Print the current cart detail
 *
 * Display the current cart items using system.
 *
 * @param carts
 * @param system
 * @return void
 */
void PrintCart(vector<cartItem> &carts, System &system);
