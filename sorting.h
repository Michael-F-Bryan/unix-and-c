typedef struct List {
  int len;
  struct Node *front;
  struct Node *back;
} List;

typedef struct Node {
    int value;
    struct Node *next;
    struct Node *previous;
} Node;


Node* new_list(int value);
Node* push(Node *head, int value);
int pop(Node **head);
int len(Node *head);
void free_list(Node *head);
void print_list(Node *head);
