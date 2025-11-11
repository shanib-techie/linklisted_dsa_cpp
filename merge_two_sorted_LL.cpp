#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

// int size(Node* head){
//     int n = 0;
//     Node* temp = head;
//     while(temp!=NULL){
//         n++;
//         temp = temp->next;
//     }
//     return n;
    
// }

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

void display_by_loop(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";

        temp = temp->next;
    }
}
int main(){
    Node* a = new Node(10);
    Node* b = new Node(30);
    Node* c = new Node(22);
    Node* d = new Node(55);

    a->next = b;
    b->next = c;
    c->next = d;



//// SECOND LINKLISTED : 
    Node* k = new Node(20);
    Node* p = new Node(33);
    Node* r = new Node(44);
    Node * s = new Node(50);
    k->next = p;
    p->next = r;
    r->next = s;




  Node* merge =   merge_two_sorted(a,k);
//   cout<<(merge)->val;
    
    display_by_loop(merge);
    // cout<<"\n secont ll : ";
    // display_by_loop(k);
    // // cout<<size(a);
}



