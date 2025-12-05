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





class doublyLL{
    public:
    Node* head;
    Node* tail;
    int size;
    doublyLL(){
        this->size = 0;
        head = tail = NULL;

    }
   void   insert_at_head(int val){
    Node* temp = new Node(val);
    if(size == 0){
        head = tail = temp;
    }else{
    // Node* temp = head;
    temp->next = head;
    head->pre = temp;
    head = temp;
   }
   size++;
}
   void insert_at_tail(int val){

    Node* temp = new Node(val);
        if(size == 0){
        head = tail = temp;
    }else{
        tail->next = temp;
        temp->pre = tail;
        tail = temp ;

    }
    size++;

   }


   void display(){
       Node* temp =  head;
       while(temp!=NULL){
           cout<<temp->val<<" ";
           temp = temp->next;
       }
   }
//    void insert_at_index(int idx,int val){

//    }

int del_at_tail(){
       if(head==NULL){
        cout<<"emply ";
    }else{
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = temp->next->next;
}}
int del_at_head(){
    if(head==NULL){
        cout<<"emply ";
    }else{
        head = head->next;
    }
}


};
int main (){
    doublyLL k;
    // k.insert_at_head(10);
    // k.insert_at_head(20);
    // k.insert_at_head(30);
    k.insert_at_tail(20);
    k.insert_at_tail(40);
    // k.display();
    k.insert_at_head(5);
    // k.display();
    k.insert_at_head(1);
    k.insert_at_tail(100);
    k.display();
    k.del_at_tail();
    cout<<"\n";
    k.display();
    k.del_at_head();
    cout<<"\n";
    k.display();
    
    


}