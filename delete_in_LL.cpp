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
    while (temp->next != tar){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}





// delete by value
Node* del_by_val(Node* head , int tarval){
    if(head->val == tarval){
       head = head->next;
       return head;
    }
    Node* temp = head;
    while (temp->next->val != tarval)
    {
        temp =temp->next;
    }
    temp->next = temp->next->next;
    return head;
    
}



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



    // del_by_index
    // display(a);
    // del_by_idx(a,c);
    // display(a);



    // del by val
    // Node* head = a;
    // display(head);
    // head = del_by_val(a,22);
    // display(head);

}