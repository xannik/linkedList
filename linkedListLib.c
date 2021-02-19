#include <stdio.h>
#include <stdlib.h>
#include "linkedListLib.h"


// creates new node with data and adds it in the beginning of the list
void insertNode(Node** head_pp, int newData)
{
  Node* newNode_p = (Node*)malloc(sizeof(Node));

  newNode_p->data = newData;
  newNode_p->next_p = *head_pp;
  newNode_p->prev_p = NULL;

  // new node is added at the start,
  // make previous start node have reference to new node
  if(*head_pp != NULL)
    {
      (*head_pp)->prev_p = newNode_p;
    }

  //Make start of list point to new node
  *head_pp = newNode_p;
}

// creates new data and adds it in the end of the list
void insertNodeLast(Node** head_pp, int newData)
{
 
  Node* newNode_p = (Node*)malloc(sizeof(Node));
  Node* currentNode_p = *head_pp;
  newNode_p->data = newData;
  newNode_p->next_p = NULL;
 
  //search for last item in the linked list
  while(currentNode_p->next_p != NULL)
    {
      currentNode_p = currentNode_p->next_p;
    }

  currentNode_p->next_p = newNode_p;
  newNode_p->prev_p = currentNode_p;
  
}

// creates new data and adds at the given position
int insertNodeAtIndex(Node** head_pp, int index, int newData)
{
  Node* newNode_p = (Node*)malloc(sizeof(Node));
  Node* currentNode_p = *head_pp;
  Node* previousNode_p = NULL;
  newNode_p->data = newData;

  int i = 0;
  while (currentNode_p->next_p != NULL && i < index)
    {
      currentNode_p = currentNode_p->next_p;
      i++;
    }

  previousNode_p = currentNode_p->prev_p;
  previousNode_p->next_p = newNode_p;
  newNode_p->next_p = currentNode_p;
  
  return index;
}

// remove first node in the linked list
void removeFirst(Node** head_pp)
{

  if (*head_pp != NULL)
    {
      Node* nodeToRemove_p  = *head_pp;
      
      //as long as there are >1 items in the list
      if (nodeToRemove_p->next_p != NULL)
	{
	  *head_pp = nodeToRemove_p->next_p;
	  (*head_pp)->prev_p = NULL;
	  free(nodeToRemove_p);
	}
      else
	{
	  
	  free(*head_pp);
	  *head_pp = NULL;
	}
      
    }
}

// remove node at current position
void removeAtIndex(Node** head_pp, int index)
{
  Node* currentNode_p = *head_pp;
  
  //find List item delete and free the memory
  int i = 0;

  //Node* next_p = currentNode->next_p;
  Node* prev_p = NULL;
  Node* next_p = NULL;
  while (currentNode_p->next_p != NULL && i < index)
    {
      prev_p = currentNode_p;
      currentNode_p = currentNode_p->next_p;
      i++;
    }
  next_p = currentNode_p->next_p;
  if (next_p != NULL)
    {
      next_p->prev_p = prev_p;
      prev_p->next_p = next_p;
      free(currentNode_p);
    }
  else
    {
      prev_p->next_p = NULL;
      free(currentNode_p);
    }
}

//sortList in increasing order 
void sortList(Node** head_pp)
{
  Node* currentNode_p = *head_pp;
  Node* nextNode_p = NULL;
  Node* tmpNode_p = NULL;
  Node* previousNode_p = NULL;
  while (currentNode_p->next_p != NULL)
    {
      previousNode_p = currentNode_p;
      currentNode_p = currentNode_p->next_p;
      nextNode_p = currentNode_p;
      while (nextNode_p->next_p != NULL)
	{
	  if (nextNode_p->data < currentNode_p->data)
	    {
	      if(nextNode_p->next_p != NULL)
		{
		  tmpNode_p = nextNode_p->next_p;
		  nextNode_p->next_p = currentNode_p->next_p;
		  currentNode_p->next_p = tmpNode_p;
		  nextNode_p->prev_p = previousNode_p;
		  previousNode_p->next_p = nextNode_p;
		  
		}
	    }
	  nextNode_p = nextNode_p->next_p;
	}
    }

}

void printList(Node ** head_pp)
{
  Node* currentNode_p = *head_pp;

  //list is empty
  if(*head_pp == NULL)
    {
      return;
    }
    
  while (currentNode_p != NULL)
    {
      printf("%d ", currentNode_p->data);
      currentNode_p = currentNode_p->next_p;
    }

  printf("\n");
}
