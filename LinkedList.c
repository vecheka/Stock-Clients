#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"



/**
 * Initialize empty Linked List.
 */
List create() {
  List list = malloc(sizeof(List));
  if( list != NULL) {
    list->front = NULL;
    list->size = 0;
  }
  return list;
}



/**
* Add new data to linked list.
* @param theList pointer of the List
* @param theData data to add the list
*/
void add(List theList, void *theData) {
  if (theData == NULL) return;
  struct Node * front = theList->front;
  struct Node * newNode;
  if (front == NULL) {
    // free(front);
    newNode = (struct Node *) malloc(sizeof(struct Node *));
    newNode->data = theData;
    newNode->next = NULL;
    front = newNode;
    theList->front = front;
    theList->size++;
  } else {
    struct Node * current = front;
    while (current->next != NULL) {
      current = current->next;
    }
    newNode = (struct Node *) malloc(sizeof(struct Node *));
    newNode->data = theData;
    newNode->next = NULL;
    current->next = newNode;
    theList->size++;
  }
}

/**
* Remove a specified data from the Linked List.
* @param theData data to remove from the list if exists.
*/
void del(List theList, void *theData) {
  if (theList->size == 0 || theData == NULL) {
    printf("List is empty!");
    return;
  }
  if (theList->front->data == theData) {
    free(theList->front->data);
    theList->front = theList->front->next;
    
  }
  else {
    struct Node * current = theList->front;
    while (current->next != NULL) {
      if (current->next->data == theData) {
        free(current->next);
        current->next = current->next->next;
        break;
      }
      current = current->next;
    }
  }
  theList->size--;
}


/**
* Remove element from the Linked List at a specified index.
* @param theList pointer of the List
* @param theIndex of element to remove.
*/
void deleteAtIndex(List theList, int theIndex) {
  if (theList->size == 0) {
    printf("Empty List!\n");
    return;
  }
   
    
  if (theIndex == 0) {
    theList->size--;
    free(theList->front->data);
    theList->front = theList->front->next;
     
  } else if (theIndex < theList->size && theIndex > 0) {
    struct Node * current = theList->front;
    int i;
    for (i = 0; i < theIndex - 1; i++) current = current->next;
    free(current->next);
    current->next = current->next->next;
    theList->size--;
  } else {
    printf("Index out of bound!\n");
    return;
  }
}

/**
* Check if the Linked List contains a specified element
* @param theList pointer of the List
* @param theData data to check for
* @return 1 if the specified data is found, else 0.
*/
int contains(List theList, void *theData) {
  if (theList->size == 0 || theData == NULL) return 0;
  struct Node *current = theList->front;
  while (current != NULL) {
    if (current->data == theData) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

/**
* Get element at a specified index in the Linked List.
* @param theList pointer of the List
* @param theIndex to find the element
* @return the element at that index.
*/
void *get(List theList, int theIndex) {
  struct Node * front = theList->front;
  
  if(theList->size == 0) {
    printf("Empty List!\n");
    return NULL;
  }
  if (theIndex == 0) {
   
    return front->data;
  } else if (theIndex < theList->size && theIndex > 0) {
    struct Node *current = front;
    int i;
    for (i = 0; i < theIndex; i++) {
      current = current->next;
    }
    return current->data;
  } else {
    printf("Index out of bound!\n");
    return NULL;
  }
}

/**
* Destroy the Linked List, and the memory allocations.
* @param theList pointer of the List
*/
void destroy(List theList) {
  
  theList->size = 0;
  struct Node * current= theList->front;
  while (current != NULL) {
    free(current->data);
    current = current->next;
  }
  free(theList);
}

/**
* Get the size of the Linked List.
* @param front pointer of the List
* @return size of the Linked List.
*/
int getSize(List theList) {
  return theList->size;
}

/**
* Display Linked List in string representation.
* @param theList pointer of the List
*/
void toString(List theList) {
  if (theList->size == 0) {
    printf("List is empty!\n"); 
  } else {
    struct Node * current = theList->front;
    printf("[%d", current->data);
    current = current->next;
    while (current != NULL) {
      printf(", %d", current->data);
      current = current->next;
    }
    printf("]\n");
  }
}
