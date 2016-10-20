#include <stdio.h>
#include <stdlib.h>
#include "sorter.h"

#define TRUE 1
#define FALSE 0

// Make a `test` macro which will automatically run our tests and print
// a tick if it was successful. Otherwise it prints a cross.
#define test(name, function_call) \
          printf("testing %s... ", name); \
          if(function_call()) { \
            printf("passed \u2714\n"); \
          } else { \
            printf("failed \u2718\n"); \
          }


// Define an assert macro which will test an expression and return FALSE
// if it is not true.
#define assert(expr) \
if((expr) == FALSE) { \
  return FALSE; \
}


int test_new_list() {
  Node *head = new_list(5);

  assert(head->value == 5);
  assert(head->next == NULL);

  return TRUE;
}


int test_pop() {
  Node *head = new_list(5);
  int val = pop(&head);
  assert(val == 5);
  assert(head == NULL);
  return TRUE;
}


// Push a value onto the list and make sure it looks the way we expect
int test_push() {
  Node *head = new_list(5);
  Node *old_head = head;

  head = push(head, 7);

  assert(head->value == 7);
  assert(head->next != NULL);
  assert(head->next == old_head);

  Node *tail = head->next;
  assert(tail->value == 5);
  assert(tail->next == NULL);

  return TRUE;
}

int test_len() {
  Node *head = new_list(0);

  assert(len(head) == 1);

  // Add a bunch of stuff to the list and make sure length changes
  // appropriately
  int values[] = {1, 2, 3, 4, 5};
  for (int i=0; i < 5; i++) {
    head = push(head, values[i]);
  }
  assert(len(head) == 6);

  return TRUE;
}


// Given an array of values, create a new list from them (note: list is
// reversed)
Node* make_list(int values[], int length) {
  Node *head = new_list(values[0]);
  for (int i=1; i<length; i++) {
    head = push(head, values[i]);
  }

  return head;
}

// Pretty much the only way to check that this works is if you don't get
// a segfault...
int test_destructor() {
  int values[] = {0, 1, 2, 3, 4, 5, 6, 7};
  Node *head = make_list(values, 8);
  free_list(head);
  return TRUE;
}

void run_tests() {
  test("constructor", test_new_list);
  test("push", test_push);
  test("pop", test_pop);
  test("len", test_len);
  test("destructor", test_destructor);
}



int main(int argc, char *argv[])
{
  run_tests();
  return 0;
}
