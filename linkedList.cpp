#include <iostream>
using namespace std;

//---------node----------//
class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
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

node* recReverse(node* head) {
    // Base Case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    //Otherwise
    node* shead = recReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return shead;
}

void iterReverseUdemy(node* &head) {
    node* current = head;
    node* prev = NULL;
    node* temp;

    while (current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    head = prev;
}

node* kReverse(node *head, int k) {
        //base
        if (head == NULL) {
            return head;
        }

        //otherwise reverse first k nodes
        node* current = head;
        node* prev = NULL;
        node* temp;
        int cnt = 1;

        while(current != NULL && cnt <= 3) {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
            cnt++;
        }

        if (temp != NULL) {
            head->next = kReverse(temp, k);
        }

        return prev;
}

node* merge(node* a, node* b) {
    //base case
    if (a == NULL) {
        return b;
    }
    if (b == NULL) {
        return a;
    }

    //recursive case
    node* c;
    if (a->data < b->data) {
        c = a;
        c->next = merge(a->next, b);
    }
    else {
        c = b;
        c->next = merge(a, b->next);
    }

    return c;
}

int runnerTechnique(node* head) {
    node* h1 = head;
    node* h2 = head;

    while (h1->next != NULL && h1->next->next != NULL) {
        h1 = h1->next->next;
        h2 = h2->next;
    }

    return h2->data;
}

//---------linkedList----------//

int main(void) {
    // node* head = NULL;
    // for(int i = 10; i >= 1; i--) {
    //     insertAtHead(head, i);
    // }
    // // insertAtHead(head, 4);
    // // insertAtHead(head, 3);
    // // insertAtHead(head, 2);
    // // insertAtHead(head, 1);
    // // insertAtHead(head, 0);
    // // insertInMiddle(head, 10, 3);
    // printLL(head);
    // head = kReverse(head, 3);
    // printLL(head);

    // -----------------
    node * a = NULL;
    node * b = NULL;

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

    // node * head = merge(a, b);

    int midValue = runnerTechnique(a);
    printf("\n%d\n", midValue);
    midValue = runnerTechnique(b);
    printf("\n%d\n", midValue);


    return 0;
}
