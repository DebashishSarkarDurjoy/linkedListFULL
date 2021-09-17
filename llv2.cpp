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
};


int main(void) {

  linkedList myLL = linkedList();

  for (int i = 10; i > 0; i--) myLL.insertAtHead(i);

  myLL.printLL();

  return 0;
}
