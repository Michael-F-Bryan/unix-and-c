typedef struct Node {
    int value;
    struct Node *next;
} Node;


Node* new_list(int value);
Node* push(Node *head, int value);
int pop(Node *head);
