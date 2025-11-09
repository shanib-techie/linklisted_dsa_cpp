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

// ROTATE k time
Node* rotate_n(Node* head , int k){
    if(head == NULL || head->next == NULL){
        return head;
    }
    int n  = 0;
    Node* temp = head;
    Node* tail= NULL;

    while(temp!=NULL){
        n++;
        tail = temp;
        temp = temp->next;
    }
    k = k%n;
    if(k == 0){
        return head;
    }
    temp = head;
    for(int i = 1;i<n-k;i++){
        temp = temp->next;
    }
    tail->next = head;
    head = temp->next;
    temp->next = NULL;
    return head;
}
void display_by_loop(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";

        temp = temp->next;
    }
}
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

    a->next = b;
    b->next = c;
    c->next = d;
    cout<<" BEFORE ROTATE : ";
     display_by_loop(a);
    // cout<<size(a);
    a = rotate_n(a,2);
    // cout<<rotate_n(a,2)->val;
    cout<<"\n AFTER ROTATE : ";
     display_by_loop(a);
}