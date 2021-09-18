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

void insertNodeAtHead(Node* &Head, int value) {
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

void printLL(Node* Head) {
  Node* current = Head;

  while (current != NULL) {
    cout << current->value << " --> ";
    current = current->next;
  }
  cout << endl;
}

int main(void) {
  Node* head = NULL;
  for (int i = 10; i > 0; i--) {
    insertNodeAtHead(head, i);
  }
  //insertAtMiddle(head, 8, 100);
  head = rReverse(head);
  printLL(head);

  return 0;
}
