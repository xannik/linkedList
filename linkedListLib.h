#ifndef LINKEDLISTLIB_H
#define LINKEDLISTLIB_H
//------------------type declarations--------------------

typedef struct Node
{
  int data;
  struct Node* next_p;
  struct Node* prev_p;
  
} Node;

//-----------------functon declarations------------------
// creates new data and add it in the beginning of the list
void insertNode(Node** head_pp, int newData);

// creates new data and adds it in the end of the list
void insertNodeLast(Node** head_pp, int newData);

// creates new data and adds at the given position
int insertNodeAtIndex(Node** head_pp, int index, int newData);

// print the linked list
void printList(Node** head_pp);

// remove first node in the linked list
void removeFirst(Node** head_pp);

// remove node at given index in the list
void removeAtIndex(Node** head_pp, int index);

//sort list in increasing order
void sortList(Node** head_pp);

// print the linked list
void printList(Node** head_pp);


#endif
