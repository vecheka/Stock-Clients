#include<stdio.h>

#ifndef LISTADT_H

#define LISTADT_H

/**

 * A structure that create nodes to store a generic data 

 * in a linked list.

 */

struct Node {

  void *data;

  struct Node *next;

  // int size;

};



/**

 * A structure to implement the LinkedList class using pointer as reference

 * to the next data in the list.

 */

struct LinkedList {

  struct Node *front;

  int size;

};





// typedef struct Node *LinkedList;

typedef struct LinkedList *List;





/** Functions Declaration.*/

List create();

void add(List, void *);

void del(List, void *);

void deleteAtIndex(List, int);

int contains(List, void *);

void toString(List);

void* get(List, int );

void destroy(List);

int getSize(List);



#endif



