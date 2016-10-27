#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

#define TRUE 1
#define FALSE 0


// malloc a new Node and return a pointer to it.
Node* new_list(int value) {
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->next = NULL;
  temp->value = value;

  return temp;
}

// Return a new list with value at the front and `head` as the tail.
Node* push(Node *head, int value) {
  Node *new = (Node*)malloc(sizeof(Node));
  new->value = value;
  new->next = head;

  return new;
}

// Pull the value out of our head node, set head to be the second node, then
// deallocate the old head.
int pop(Node **head) {
  Node *temp = *head;
  int ret = temp->value;

  *head = (*head)->next;
  free(temp);
  return ret;
}


// Get the length of our linked list.
int len(Node *head) {
  if (head == NULL) {
    return 0;
  }

  int counter = 1;
  while (head->next != NULL) {
    head = head->next;
    counter++;
  }

  return counter;
}


// Step through the list, freeing each node as you go.
void free_list(Node *head) {
  while (head != NULL) {
    // Get a pointer to the current node
    Node *current = head;

    // set head to the next element
    head = current->next;

    // free the current node
    free(current);
  }
}


// Print out the list contents separated by spaces.
void print_list(Node *head) {
  while (head != NULL) {
    printf("%d ", head->value);
    head = head->next;
  }
  printf("\n");
}
