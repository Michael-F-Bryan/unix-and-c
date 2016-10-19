#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "sorter.h"

#define TRUE 1
#define FALSE 0


// malloc a new Node and return a pointer to it.
Node* new_list(int value) {
    Node *temp = malloc(sizeof(Node));
    temp->next = NULL;
    temp->value = value;

    return temp;
}

// Return a new list with value at the front and `head` as the tail.
Node* push(Node *head, int value) {
    Node *new = malloc(sizeof(Node));
    printf("head = %x, new = %x\n", head, new);
    new->value = value;
    new->next = head;

    printf("new->next = %x\n", new->next);

    return new;
}

// Make head point at the second element, returning the value and then freeing
// the popped node.
int pop(Node *head) {
    Node *temp = head;
    int ret = temp->value;

    *head = *head->next;
    free(temp);
    return ret;
}
