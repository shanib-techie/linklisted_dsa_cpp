
#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* pre;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->pre = NULL;
    }
};
void display_by_loop(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";

        temp = temp->next;
    }
}

void reverse_display(Node * head){
    if(head == NULL) return;
        reverse_display(head->next);
        cout<<head->val<<" ";
        // head = head->next;

    }

// }void reverse_display_by_rec(Node* head){
//     if (head == NULL) return;
//     reverse_display_by_rec(head->next);
//     cout<<head->val<<" ";
// }
int size(Node* head){
    int n = 0;
    Node* temp = head;
    while(temp!=NULL){
        n++;
        temp = temp->next;
    }
    return n;
    
}
int main(){
    Node* a = new Node(10);
    Node* b = new Node(30);
    Node* c = new Node(22);
    Node* d = new Node(55);
    Node* e = new Node(88);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->pre =d;
    d->pre = c;
    c->pre = b;
    b->pre = a;
    display_by_loop(a);
    cout<<size(a);
    cout<<"REVERSE DISPLAY : ";
    reverse_display(a);
}