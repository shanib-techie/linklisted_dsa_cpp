#include <iostream>
using namespace std;

// Structure for a term in polynomial
struct Node {
    int coeff;
    int pow;
    Node* next;
};

// Function to create a new node
Node* createNode(int coeff, int pow) {
    Node* newNode = new Node;
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term at end
void insert(Node** head, int coeff, int pow) {
    Node* newNode = createNode(coeff, pow);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to display polynomial
void display(Node* head) {
    if (head == NULL) {
        cout << "0";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->coeff << "x^" << temp->pow;
        if (temp->next != NULL)
            cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to add two polynomials
Node* addPolynomials(Node* p1, Node* p2) {
    Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->pow == p2->pow) {
            insert(&result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->pow > p2->pow) {
            insert(&result, p1->coeff, p1->pow);
            p1 = p1->next;
        } else {
            insert(&result, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }

    // Add remaining terms
    while (p1 != NULL) {
        insert(&result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insert(&result, p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return result;
}

// Main Function
int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* sum = NULL;

    int n1, n2, coeff, pow;

    cout << "Enter number of terms in Polynomial 1: ";
    cin >> n1;
    cout << "Enter terms for Polynomial 1 (coefficient and power):\n";
    for (int i = 0; i < n1; i++) {
        cout << "Term " << i + 1 << ": ";
        cin >> coeff >> pow;
        insert(&poly1, coeff, pow);
    }

    cout << "\nEnter number of terms in Polynomial 2: ";
    cin >> n2;
    cout << "Enter terms for Polynomial 2 (coefficient and power):\n";
    for (int i = 0; i < n2; i++) {
        cout << "Term " << i + 1 << ": ";
        cin >> coeff >> pow;
        insert(&poly2, coeff, pow);
    }

    cout << "\nPolynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    sum = addPolynomials(poly1, poly2);

    cout << "\nSum of Polynomials: ";
    display(sum);

    return 0;
}
