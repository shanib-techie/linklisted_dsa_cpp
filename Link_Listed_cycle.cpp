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
// 
// JUST RETURN TRUE OR FALSE DID THIS LL IS CYCLE LOOP
// WHERE FAST == SLOW SO THERE IS CYCLE AND NOT != NULL

bool check_cycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next;  // slow fast ko same speed se badaoo jaha dono barabr maltb cycle h 
        if(slow==fast)
        return true;
    }
    return false;
    
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
    // display_by_loop(a);
    // cout<<size(a);
    cout<<(check_cycle(a)?"cycle present":"no cycle");
//           condition    if true         if false
}