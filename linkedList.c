#include <stdio.h>
#include "linkedListLib.h"

int main()
{

  Node* list_p = NULL;

  insertNode(&list_p,14);
  insertNode(&list_p,3);
  insertNode(&list_p,5);
  insertNode(&list_p,1);
  insertNode(&list_p,2);
  insertNode(&list_p,5);
  printList(&list_p);
  removeFirst(&list_p);
  printList(&list_p);
  insertNodeLast(&list_p, 9);
  printList(&list_p);
  insertNodeAtIndex(&list_p, 2, 10);
  printList(&list_p);
  removeAtIndex(&list_p, 1);
  printList(&list_p);
  sortList(&list_p);
  printList(&list_p);
  
  return 0;
}

