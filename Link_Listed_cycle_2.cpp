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
Node* detect_cycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    bool flag = false;//represent no cycle
    while (fast!=NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            flag = true;
            break;
        }
    }
    if(flag== false) return NULL;
    else{
        Node* temp = head;
        while (temp!=slow)
        { slow =slow->next;
           temp = temp->next;
        }
        return slow;
        
    }
    

}


int main(){
    Node* a = new Node(10);
    Node* b = new Node(30);
    Node* c = new Node(22);
    Node* d = new Node(55);

    a->next = b;
    b->next = c;
    c->next = b;
    cout<<detect_cycle(a)->val;
}