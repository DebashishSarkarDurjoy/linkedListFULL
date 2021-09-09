#include <iostream>
using namespace std;

//---------node----------//
class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
    }
};
//---------node----------//

//----------linkedList---------//
void insertAtHead(node * &head, int data) {
    //if list is empty
    if (head == NULL) {
        head = new node(data);
        return;
    }
    //if list is not empty
    node* newNode = new node(data);
    newNode->next = head;
    head = newNode;

}

void printLL(node * head) {
    while(head!=NULL) {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << endl;
}

void insertInMiddle(node* &head, int data, int pos) {
    if (pos == 0) {
        insertAtHead(head, data);
        return;
    }
    else {
        node * temp = head;
        //get to position pos with pos-1 jumps
        for (int jumps = 1; jumps <= pos-1; jumps++) {
            temp = temp->next;
        }
        node * n = new node(data);
        n->next = temp->next;
        temp->next = n;

    }
}



//---------linkedList----------//

int main(void) {
    node* head = NULL;
    for(int i = 10; i >= 1; i--) {
        insertAtHead(head, i);
    }
    // insertAtHead(head, 4);
    // insertAtHead(head, 3);
    // insertAtHead(head, 2);
    // insertAtHead(head, 1);
    // insertAtHead(head, 0);
    // insertInMiddle(head, 10, 3);
    printLL(head);
    head = recReverse(head);
    printLL(head);
    return 0;
}
