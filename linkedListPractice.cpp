#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node* next;
  Node(int value) {
    this->value = value;
    this->next = NULL;
  }
};

void insertAtHead(Node* &Head, int value) {
  //if (Head == NULL) Head = new Node(value);

  Node* newNode = new Node(value);
  newNode->next = Head;
  Head = newNode;

  return;
}

void insertAtMiddle(Node* Head, int pos, int value) {
  Node* current = Head;
  while (Head != NULL && pos > 2) {
    pos--;
    current = current->next;
  }
  Node* newNode = new Node(value);
  newNode->next = current->next;
  current->next = newNode;
}

// recursive reverse a linked list
Node* rReverse(Node* head) {
  //base case
  if (head->next == NULL) {
    return head;
  }

  //recursive case
  Node* shead = rReverse(head->next);

  head->next->next = head;
  head->next = NULL;

  return shead;
}

//iterative reverse
Node* iReverse(Node* head) {
  Node* prev = NULL;
  Node* current = head;
  Node* next = head;

  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  return prev;
}

void printLL(Node* Head) {
  Node* current = Head;

  while (current != NULL) {
    cout << current->value << " --> ";
    current = current->next;
  }
  cout << endl;
}

Node* kReverse(Node* head, int k) {
  //base case
  if (head == NULL) return NULL;

  //on the way up
  Node* prev = NULL;
  Node* current = head;
  Node* next = head;
  int counter = 1;

  while (current != NULL && counter <= k) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    counter++;
  }

  // recursive call
  if (current != NULL) {
    head->next = kReverse(current, 3);
  }

  //on the way back
  return prev;
}

Node* merge(Node* a, Node* b) {
  //base case
  if (a == NULL) {
    return b;
  }
  if (b == NULL) {
    return a;
  }

  //on the way up
  Node* c;
  if (a->value < b->value) {
    c = a;
    c->next = merge(a->next, b);
  }
  else {
    c = b;
    c->next = merge(a, b->next);
  }

  //on the way back
  return c;

}

int main(void) {
  Node* head = NULL;
  Node * a = NULL;
  Node * b = NULL;

  insertAtHead(a, 12);
  insertAtHead(a, 11);
  insertAtHead(a, 10);
  insertAtHead(a, 7);
  insertAtHead(a, 5);
  insertAtHead(a, 1);

  insertAtHead(b, 6);
  insertAtHead(b, 3);
  insertAtHead(b, 2);

  printLL(a);
  printLL(b);
  //insertAtMiddle(head, 8, 100);
  // head = rReverse(head);
  head = merge(a, b);
  printLL(head);

  return 0;
}
