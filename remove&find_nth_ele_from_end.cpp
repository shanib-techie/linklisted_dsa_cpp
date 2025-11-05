#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next = NULL;

    Node(int val)
    {
      this->val = val;
      this->next = NULL;
    }
};

Node* nth_ele_from_end(Node* head , int n){
    Node * temp = head;
    int size = 0;

    while(temp!=NULL){
        size++;
        temp = temp->next;
    }
    if(n==size){
        head = head->next;
        return head;
    }
   int m = (size-n)+1;
   int idx = m-1;
   temp = head;
   for(int i = 1;i<idx;i++){
      temp = temp->next;
   }
   temp->next = temp->next->next;
   return head;

}

void display(Node*head ){
   Node* temp = head;
   while(temp!= NULL){
    cout<<temp->val<<" ";
    temp = temp->next;
   }
   cout<<endl;

}
int main(){
    Node* a = new Node(10);
    Node* b = new Node(30);
    Node* c = new Node(22);
    Node*d = new Node(33);

    a->next = b;
    b->next = c;
    c->next = d;
   nth_ele_from_end(a,2);
    display(a);
}