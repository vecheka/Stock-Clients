#include<stdio.h>
#include "LinkedList.h"

#ifndef STOCK_H
#define STOCK_H

/**
 * A structure to store Stock's symbols and prices.
 */
struct Stock {
  char symbol[6];
  double price;
};

typedef struct Stock *Stock_Class;


/** Function Declaration*/
void readStocksInfo(char *, List);
double getStockPrice(List, char[]);
void getSymbol(char [], char[], int);

#endif
