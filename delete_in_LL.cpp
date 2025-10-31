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





// DELETE NODE BY INDEX 
Node* del_by_idx(Node* head,Node* tar){
    if(head == tar){
        head = head->next;
        return head;
    }
    Node* temp = head;
    while (temp->next != head){
        temp = temp->next;
    }
    temp->next = temp->next->next;
}



// delete by valu



void display(Node* head){
    Node* temp = head;
    // delete by val
    cout<<"\n";
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }  
    cout<<"\n";
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
    display(a);
    cout<<size(a);
}