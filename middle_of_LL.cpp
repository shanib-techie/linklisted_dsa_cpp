

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

Node* middle_ele(Node* head){
    Node* temp = head;
   int size = 0;
    while(temp!=NULL){
        size++;
        temp = temp->next;
    }
    int midIdx = size/2;
    Node* mid = head;
    for(int i =1;i<=midIdx;i++){
        mid = mid->next;
       }
       return mid;

}
int main(){
    Node* a = new Node(10);
    Node* b = new Node(30);
    Node* c = new Node(22);
    Node*d = new Node(33);

    a->next = b;
    b->next = c;
    c->next = d;
    display_by_loop(a);
    cout<<size(a);
   cout<<middle_ele(a)->val;
}