#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "sorter.h"

#define TRUE 1
#define FALSE 0

// Make a `test` macro which will automatically run our tests and print
// a tick if it was successful
#define test(name, function_call) \
      printf("testing %s... ", name); \
      function_call(); \
      printf("passed \u2714\n");


int test_new_list() {
    Node *head = new_list(5);

    assert(head->value == 5);
    assert(head->next == NULL);

    return TRUE;
}


int test_pop() {
    Node *head = new_list(5);
    int val = pop(head);
    assert(val == 5);
    assert(head == NULL);
    return TRUE;
}

// Push a value onto the list and make sure it looks how we expect
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

void run_tests() {
    test("constructor", test_new_list);
    test("push", test_push);
    test("pop", test_pop);
}



int main(int argc, char *argv[])
{
    run_tests();
    return 0;
}
