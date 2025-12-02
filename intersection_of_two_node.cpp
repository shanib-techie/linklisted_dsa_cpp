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

Node* intersection(Node* a, Node* b){
    Node* temp_a = a;
    Node* temp_b = b;
    int size_a  = 0;
    int size_b = 0;
    while(temp_a!=NULL){
        size_a++;
        temp_a = temp_a->next;
    }
        while(temp_b!=NULL){
        size_b++;
        temp_b = temp_b->next;
    }
    temp_a = a;
    temp_b = b;


    if(size_a> size_b){
        int diff = size_a - size_b;
        for(int i = 1;i<=diff;i++){
            temp_a = temp_a->next;
            temp_b = temp_b->next;
        }
        return temp_a;

    }
        else //(size_b > size_a)
        {
        int diff = size_b - size_a;
        for(int i = 1;i<=diff;i++){
            temp_a = temp_a->next;
            temp_b = temp_b->next;
        }
        return temp_a;    

    }
}
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;


}
int main() {
        // List A: 10 -> 30 -> 22 -> 33 -> 77
    Node* a1 = new Node(10);
    Node* a2 = new Node(30);
    Node* a3 = new Node(22);
    Node* a4 = new Node(33);
    Node* a5 = new Node(77);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;

    // List B: 9 -> 99 -> (intersects at 22)
    Node* b1 = new Node(9);
    Node* b2 = new Node(99);
    b1->next = b2;
    b2->next = a3; // intersection happens here

    Node* inter = intersection(a1, b1);
        if(inter != NULL)
        cout << "Intersection at node with value: " << inter->val << endl;
    else
        cout << "No intersection found" << endl;

}

// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int val;
//     Node* next;

//     Node(int val) {
//         this->val = val;
//         this->next = NULL;
//     }
// };

// Node* intersection(Node* a, Node* b){
//     Node* temp_a = a;
//     Node* temp_b = b;
//     int size_a  = 0;
//     int size_b = 0;

//     while(temp_a!=NULL){
//         size_a++;
//         temp_a = temp_a->next;
//     }
//     while(temp_b!=NULL){
//         size_b++;
//         temp_b = temp_b->next;
//     }

//     temp_a = a;
//     temp_b = b;

//     if(size_a > size_b){
//         int diff = size_a - size_b;
//         for(int i = 1; i <= diff; i++)
//             temp_a = temp_a->next;   // ✅ move only longer list
//     }
//     else {
//         int diff = size_b - size_a;
//         for(int i = 1; i <= diff; i++)
//             temp_b = temp_b->next;   // ✅ move only longer list
//     }

//     // ✅ find intersection
//     while(temp_a != NULL && temp_b != NULL){
//         if(temp_a == temp_b)
//             return temp_a;
//         temp_a = temp_a->next;
//         temp_b = temp_b->next;
//     }
//     return NULL;  // ✅ if no intersection
// }

// void display(Node* head) {
//     Node* temp = head;
//     while (temp != NULL) {
//         cout << temp->val << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main() {
//     Node* a1 = new Node(10);
//     Node* a2 = new Node(30);
//     Node* a3 = new Node(22);
//     Node* a4 = new Node(33);
//     Node* a5 = new Node(77);
//     a1->next = a2;
//     a2->next = a3;
//     a3->next = a4;
//     a4->next = a5;

//     Node* b1 = new Node(9);
//     Node* b2 = new Node(99);
//     b1->next = b2;
//     b2->next = a3; // intersection happens here

//     Node* inter = intersection(a1, b1);

//     if(inter != NULL)
//         cout << "Intersection at node with value: " << inter->val << endl;
//     else
//         cout << "No intersection found" << endl;
// }
