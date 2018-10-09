#include "Client.h"
#include "LinkedList.h"
#include "Stock.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * I have tested both on the server, and on the virtual machine.
 * Note: For this project, I used a generic Linked List implementation to store information
 * instead of a generic array list.
 */

/** Function Declarations.*/
void writeToFile(List, List);

int main(void) {
	char *clientFile = "clients.txt";
	char *stockCSV = "stocks.csv";

	List client_list = create(); // to store client informations
	List stock_list = create();  // to store stock's symbols and prices

	readClientInfo(clientFile, client_list);
	readStocksInfo(stockCSV, stock_list);

	// Read clients' stock shares, and compute total value to write to output
	// file.
	writeToFile(client_list, stock_list);


	// for testing.
	//   int i;
	//   Stock_Class client_info = (Stock_Class) malloc(sizeof(struct Stock));
	//   for (i = 0; i < getSize(stock_list); i++) {
	//     client_info = get(stock_list, i);
	//     printf("%s\n", client_info->symbol);
	//   }
	// 	free(client_info);

	printf("Done!\n");

	destroy(client_list);
	destroy(stock_list);
}

/**
 * Write clients' information, and stock values to a file.
 * @param client_list list of clients' information
 * @param stock_list list of stock's symbols and prices
 */
void writeToFile(List client_list, List stock_list) {
	FILE *inFile = fopen("stock_client.txt", "r");
	FILE *outFile = fopen("summary.csv", "w");
	int id, number_stocks, number_shares;
	double stock_price, total_value = 0.0;
	char stockSymbol[6] = {0};
	Client_Class client_info;
	while (fscanf(inFile, "%d %d", &id, &number_stocks) == 2) {
		client_info = getClientInfo(client_list, id);
		fprintf(
			outFile,
			"%d, %s, %s, %s",
			id,
			client_info->name,
			client_info->phone_number,
			client_info->email);
		while (number_stocks > 0) {
			if (fscanf(inFile, "%s %d", &stockSymbol, &number_shares) == 2) {
				stock_price = getStockPrice(stock_list, stockSymbol);
				total_value += (stock_price * number_shares);
				fprintf(
					outFile,
					"\n%s, %d, %lf ",
					stockSymbol,
					number_shares,
					stock_price);
			}
			number_stocks--;
		}
		fprintf(outFile, "\n%lf", total_value);
		total_value = 0;
		fprintf(outFile, "\n\n");
		free(client_info);
	}

	fclose(inFile);
	fclose(outFile);
}