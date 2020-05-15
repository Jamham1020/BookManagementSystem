/**
 * Filename: System.h
 *
 * Description: System header. It defines System class.
 *
 * Authors: Janet Pham, Yong Gyun Kim, Erika Meza, Marwa Naghmouchi, Vernon Neilly
 *
 * Class: COMPSCI-1
 *
 * Date: May 14, 2020
 */
#pragma once
#include <vector>
#include <string>
#include "book.h"

using namespace std;

/**
 * System Class
 * 
 * It holds book information and helps to handle and manage the information.
 */
class System
{
private:
  // stores current file path so that the system can save into the same file
  // when the system terminated.
  string currentFilePath = "books.csv";

public:
  /**
   * The list of the books
   * 
   * It holds current list of the books in the system.
   */
  vector<book> books;

  /**
   * Save the system as a file
   * 
   * Parse the current books as a csv file and save to the given file path.
   *
   * @param filepath
   * @return true when it saves successfully, otherwise, false.
   */
  bool SaveFile(string filepath = "");

  /**
   * Load the file to the current system
   * 
   * Parse the given csv file and import the books into the system.
   *
   * @param filepath
   * @return true when it saves successfully, otherwise, false.
   */
  bool LoadFile(string filepath = "");

  /**
   * Return current file path
   *
   * @return string current file path
   */
  string GetCurrentFilePath();
};
