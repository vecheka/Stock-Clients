#include "Client.h"
#include <stdlib.h>
#include "LinkedList.h"

/**
 * Read clients' informations from a file and store to a list.
 * @param fileName name of the file to be read
 * @param theList list to be store in.
 */
void readClientInfo(char *fileName, List theList) {
  FILE *inFile = fopen(fileName, "r");
  
  Client_Class client_info;
	client_info = (Client_Class) malloc(sizeof(struct Client));
	while(fscanf(inFile, "%d %[a-zA-Z ] %s %s", &client_info->ID, &client_info->name, &client_info->phone_number, &client_info->email) == 4) {
	  
	  add(theList, (void *) client_info);
	  client_info = (Client_Class) malloc(sizeof(struct Client));
	}
  // free(client_info);
  fclose(inFile);
}


/**
 * Get a client's information with the given ID.
 * @param theList list to search for
 * @param theID of the client to search for in the client list
 * @return a client's information (name, ID, email & phone_number)
 */
Client_Class getClientInfo(List theList, int theID) {
  
  int i;
  for(i = 0; getSize(theList); i++) {
    Client_Class client_info = get(theList, i);
    if (client_info->ID == theID) {
      return client_info;
    }
  }
  return NULL;
}