/**
 * Filename: util.h
 *
 * Description: utility header declaration. utility provides various useful function
 *  so that the system handles the data easily.
 *
 * Authors: Janet Pham, Yong Gyun Kim, Erika Meza, Marwa Naghmouchi, Vernon Neilly
 *
 * Class: COMPSCI-1
 *
 * Date: May 15, 2020
 */
#pragma once
#include <string>

using namespace std;

/**
 * Truncate the string by given width
 * 
 * @param str given string
 * @param width substring of the length
 * @return string if the string is longer than the given width, it
 *  returns with ellipses.
 */
string truncate(string str, int width);

/**
 * Clear Input for cin stream and getline
 *
 * @return void
 */
void ClearInput();

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
string FindAndReplaceAll(string data, string toSearch, string replaceStr);
