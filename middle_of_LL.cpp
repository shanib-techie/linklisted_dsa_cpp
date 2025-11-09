#include <iostream>
using namespace std;
// class Node{
//     public:
//     int val;
//     Node* next;
//     Node(int val){
//         this->val = val;
//         this->next = NULL;
//     }
// };
// Node* middle_ele(Node* head){
//     Node* temp = head;
//    int size = 0;
//     while(temp!=NULL){
//         size++;
//         temp = temp->next;
//     }
//     int midIdx = size/2;
//     Node* mid = head;
//     for(int i =1;i<=midIdx;i++){
//         mid = mid->next;
//        }
//        return mid;
// }

// void display_by_loop(Node* head){
//     Node* temp = head;
//     while(temp!=NULL){
//         cout<<temp->val<<" ";

//         temp = temp->next;
//     }
// }
// int size(Node* head){
//     int n = 0;
//     Node* temp = head;
//     while(temp!=NULL){
//         n++;
//         temp = temp->next;
//     }
//     return n;
    
// }
// int main(){
//     Node* a = new Node(10);
//     Node* b = new Node(30);
//     Node* c = new Node(22);
//     Node*d = new Node(33);

//     a->next = b;
//     b->next = c;
//     c->next = d;
//     // display_by_loop(a);
//     // cout<<size(a);
//    cout<<middle_ele(a)->val;
// }



// ANOTHER METHOD TO FIND MID BY USING TWO POINTER AND HERE WE ONLY TREVERSE ONE TIME

class Node {
    public:
    int val;
    Node* next;

    Node (int val){
        this->val = val;
        this->next = NULL;
    }
};
   
void display_by_loop(Node* head){
    Node* temp = head;
    while (temp != NULL) {  // Change: temp != NULL
        cout << temp->val << " ";
        temp = temp->next;
    }
}
// Corrected Code:
Node* by_two_pointer_print_mid(Node* head){
    Node* first = head;
    Node* second = head;
    while(second != NULL && second->next != NULL){
        first = first->next;
        second = second->next->next;
    }
    return first;
}


int main(){
    Node* a = new Node(45);
    Node* b = new Node(22);
    Node* c = new Node(65);
    Node* d = new Node(5);
    Node* e = new Node(76);

    a->next = b;
    b->next =c;
    c->next =d;
    d->next =e;/////

    cout<<by_two_pointer_print_mid(a)->val;
}
