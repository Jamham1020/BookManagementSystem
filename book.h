/**
 * Filename: book.h
 *
 * Description: book struct definition.
 *
 * Authors: Janet Pham, Yong Gyun Kim, Erika Meza, Marwa Naghmouchi, Vernon Neilly
 *
 * Class: COMPSCI-1
 *
 * Date: May 14, 2020
 */
#pragma once
#include <string>

using namespace std;

/**
 * Book struct
 * 
 * The data type that contains book related information
 */
struct book
{
  string ISBN;
  string Author;
  string Title;
  int Quantity;
  double Price;
  string Notes;
};
