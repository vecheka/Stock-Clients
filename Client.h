#include<stdio.h>
#include "LinkedList.h"
#ifndef CLIENT_H
#define CLIENT_H


/**
 * A structure to store Client's informations.
 */
struct Client {
	int ID;
	char name[50];
	char phone_number[20];
	char email[20];
};

typedef struct Client * Client_Class;

/** Function Declaration*/
void readClientInfo(char *, List);
Client_Class getClientInfo(List, int);

#endif
