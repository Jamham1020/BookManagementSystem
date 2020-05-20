/**
 * Filename: account.h
 *
 * Description: account struct definition.
 *
 * Authors: Janet Pham, Yong Gyun Kim, Erika Meza, Marwa Naghmouchi, Vernon Neilly
 *
 * Class: COMPSCI-1
 *
 * Date: May 14, 2020
 */
#pragma once

using namespace std;

struct Account{
  double balance = 10;
  double getBalance(){
    return balance;
  };
};