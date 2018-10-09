#include "Stock.h"
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"


/**
 * Read stock's symbols and prices from a file and store to a list.
 * @param fileName name of the file to be read
 * @param theList list to be store in.
 */
void readStocksInfo(char *fileName, List theList) {
  FILE *inFile = fopen(fileName, "r");
  
   // skip the first line of the file
  fscanf(inFile, "%*[^\n]\n", NULL);
  Stock_Class stock_info;
  stock_info = (Stock_Class) malloc(sizeof(struct Stock));
  while (fscanf(inFile, "%[^,],%lf",&stock_info->symbol, &stock_info->price) == 2) {
    add(theList, (void *) stock_info);
    stock_info = (Stock_Class) malloc(sizeof(struct Stock));
  }
  free(stock_info);
  fclose(inFile);
}


/**
 * Get the price of the given stock symbol from the list.
 * @param theList list to find the stock symbol and its price
 * @param theSymbol stock's symbol
 * @return the given stock's symbol price.
 */
double getStockPrice(List theList, char theSymbol[]) {
  int i;
  double price = 0.0;
  // Stock_Class stock_info = (Stock_Class)malloc(sizeof(struct Stock));
  for (i = 0; i < getSize(theList); i++) {
    Stock_Class stock_info = get(theList, i);
    char temp2[6] = {0};
    getSymbol(stock_info->symbol, temp2, 6);
    if (strcmp(theSymbol, temp2) == 0) {
      price = stock_info->price;
      break;
    }
  }
  
  // free(stock_info);
  return price;
}


/**
 * Get the correct symbol string.
 * @param theSymbol character array to manipulate
 * @param theNewSymbol new character array that represents the symbol
 * @param theSize size of the string.
 */
void getSymbol(char theSymbol[], char theNewSymbol[], int theSize) {
  int index = 0;
  int i;
  for (i = 0; i <= theSize; i++) {
      if((theSymbol[i] >= 'a' && theSymbol[i] <= 'z')
      || (theSymbol[i] >= 'A' && theSymbol[i] <= 'Z')) {
        // printf("%c", stock_info->symbol[i]);
        theNewSymbol[index] = theSymbol[i];
        index++;
      }

  }
}