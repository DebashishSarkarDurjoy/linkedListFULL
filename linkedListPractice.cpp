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
  printLL(head);

  return 0;
}
