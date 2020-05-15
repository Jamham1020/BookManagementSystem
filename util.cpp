/**
 * Filename: util.cpp
 *
 * Description: utility functions implementation.
 *
 * Authors: Janet Pham, Yong Gyun Kim, Erika Meza, Marwa Naghmouchi, Vernon Neilly
 *
 * Class: COMPSCI-1
 *
 * Date: May 15, 2020
 */
#include <iostream>
#include <string>
#include <thread>
#include "util.h"

using namespace std;

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

/**
 * Find the given string and replace it
 * 
 * Reference: https://thispointer.com/find-and-replace-all-occurrences-of-a-sub-string-in-c/
 *
 * @param data main string
 * @param toSearch search keyword
 * @param replaceStr replacing keyword
 * @return string
 */
string FindAndReplaceAll(string data, string toSearch, string replaceStr)
{
  // Get the first occurrence
  size_t pos = data.find(toSearch);
  // Repeat till end is reached
  while (pos != string::npos)
  {
    // Replace this occurrence of Sub String
    data.replace(pos, toSearch.size(), replaceStr);
    // Get the next occurrence from the current position
    pos = data.find(toSearch, pos + replaceStr.size());
  }

  return data;
}
