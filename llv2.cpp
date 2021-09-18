#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node (int data) {
      this->value = data;
      this->next = NULL;
    }
};

class linkedList {
private:
  Node* head;

  Node* rReverse(Node* node) {
    //base case
    if (node->next == NULL) {
      return node;
    }

    //otherwise
    Node* shead = rReverse(node->next);

    //on the way back
    node->next->next = node;
    node->next = NULL;

    return shead; //return this down the path
  }

public:
  linkedList() {
    this->head = NULL;
  }

  void insertAtHead(int value) {
    Node* newNode = new Node(value);
    newNode->next = this->head;
    this->head = newNode;
  }

  void printLL() {
    Node* current = this->head;
    while(current != NULL) {
      cout << current->value << " --> ";
      current = current->next;
    }
    cout << endl;
  }

  void insertAtMiddle(int pos, int value) {
    Node* current = this->head;
    while (current != NULL && pos > 2) {
      pos--;
      current = current->next;
    }
    Node* newNode = new Node(value);
    newNode->next = current->next;
    current->next = newNode;
  }

  void recursiveReverse() {
    this->head = this->rReverse(this->head);
  }
};


int main(void) {

  linkedList myLL = linkedList();

  for (int i = 10; i > 0; i--) myLL.insertAtHead(i);
  // myLL.insertAtMiddle(8, 100);
  myLL.recursiveReverse();
  myLL.printLL();

  return 0;
}
