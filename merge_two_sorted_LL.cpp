#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

Node* merge_two_sorted(Node* a, Node* b) {
    Node* c = new Node(-1);  // dummy node
    Node* temp_c = c;

    while (a != NULL && b != NULL) {
        if (a->val <= b->val) {
            temp_c->next = new Node(a->val);
            a = a->next;
        } else {
            temp_c->next = new Node(b->val);
            b = b->next;
        }
        temp_c = temp_c->next;
    }

    // attach remaining nodes
    if (a != NULL) temp_c->next = a;
    else temp_c->next = b;

    return c->next; // skip dummy
}

void print(Node* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
     int n1, n2, val;

    cout << "Enter number of nodes in first sorted linked list: ";
    cin >> n1;

    Node* a = NULL;
    Node* tail1 = NULL;

    for (int i = 1; i <= n1; i++) {
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        Node* newNode = new Node(val);
        if (a == NULL) {
            a = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    cout << "\nEnter number of nodes in second sorted linked list: ";
    cin >> n2;

    Node* k = NULL;
    Node* tail2 = NULL;

    for (int i = 1; i <= n2; i++) {
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        Node* newNode = new Node(val);
        if (k == NULL) {
            k = newNode;
            tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    cout << "\nFirst List: ";
    print(a);

    cout << "Second List: ";
    print(k);

    Node* merged = merge_two_sorted(a, k);

    cout << "\nMerged Sorted List: ";
    print(merged);

    return 0;
}

