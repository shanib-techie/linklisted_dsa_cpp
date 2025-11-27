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

    void insertattail(int val){
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
    void insertathead(int val){
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
    }
    void insertatidx(int idx,int val){
        if(idx == 0){
            insertathead(val);
        }else if (idx == size-1)
        {
            insertattail(val);
        }else if (idx < 0 || idx > size){
            cout<<"invalid";
        }else{
            Node* t = new Node(val);
            Node* temp = head;
            for(int i = 1; i<=idx-1;i++){
                temp = temp->next;
            }
            t->next= temp->next;
            temp->next =t;
        }
    }




    int getatidx(int idx){
        if(idx < 0 || idx >= size){
            cout<<"invalid....";
            return -1;

        }
        else if(idx == 0){
            head->val;
        }
        else if(idx == size-1){
            return tail->val;
        }
        else{
        Node* temp = head;
        for(int i = 1 ; i<= idx-1;i++){
            temp = temp->next;
        }
        return temp->val;
    }}



    void del_at_head(){


        if(size == 0){
            cout<<"list is empty";
        }else if (size == 1){
            head = tail = NULL;
            size --;
        }
        else{
            head = head->next;
            size--;
        }

    }
    void del_at_tail(){
             if(size == 0){
            cout<<"list is empty";
        }else if (size == 1){
            head = tail = NULL;
            size --;
        }else{
            Node* temp = head;
            while (temp->next->next != NULL) //10 20 30 40 50 null
            {
                /* code */
                temp = temp->next;
            }
            temp->next = NULL;
            size--;
            
        }

    }
    void del_at_idx(int idx){
                if(idx < 0 || idx >= size){
            cout<<"invalid....";
        }
        else if (idx == 0){
            del_at_head();
        }
        else if (idx == size-1){
            del_at_tail();
        }
        else{
            Node* temp = head;
            for(int i = 1;i<=idx-1;i++){
                temp= temp->next;
            }
            temp->next = temp->next->next;
        }
        

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
    ll.insertattail(10);
    ll.insertattail(20);
    ll.insertattail(40);
    cout<<"\n"<<" ";
    cout<<ll.size_of_LL();
    ll.display();
    ll.insertathead(50);
       ll.display();
    // ll.insertatidx(54,30);
    cout<<ll.getatidx(2);
    ll.insertathead(45);
    ll.insertattail(34);
    ll.del_at_head();
    ll.display();
}