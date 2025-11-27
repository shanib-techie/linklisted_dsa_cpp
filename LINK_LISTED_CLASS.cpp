#include<iostream>
using namespace std;


class Node{  //user define data type 
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;    }
};

class LinkedList{  //user defined data structure
    public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        this->head = NULL;
        this->size= 0;
        this->tail = NULL;
    }

    void insertatEnd(int val){
        Node* temp = new Node(val);
        if(size==0){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    int size_of_LL(){
        size = 0;
        Node* temp = head;
        while(temp !=NULL){
            size++;
            temp = temp->next;
        }
        return size;
    }

};


int main(){
    LinkedList ll;
    ll.insertatEnd(10);
    ll.insertatEnd(20);
    ll.insertatEnd(40);
    cout<<"\n"<<" ";
    cout<<ll.size_of_LL();
    ll.display();

}