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
Node* del_dupli(Node* head){
    if (head == NULL || head->next == NULL) { //base case bna diya agr LL 0 ya 1 ki ha
        return head;
    }

    Node* a = head;  //do pointer banao yeh ek pehle pr aur dusra ek aage hoge 
    Node* b = head->next;

    while (b != NULL) {  //jab tak b null ni ho jata  iska matlb a pura treverse kr lega
        while (b != NULL && b->val == a->val) {
            b = b->next;
        }

        a->next = b;
        a = b;

        if (b != NULL)
            b = b->next;
    }

    return head;
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
    Node* b = new Node(10);
    Node* c = new Node(10);
    Node* d = new Node(20);
    Node* e = new Node(22);
    Node* f = new Node(22);
    Node* g = new Node(22);
    Node* h = new Node(22);
    Node* i = new Node(45);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next =f;
    f->next = g;
    g->next =h;
    h->next = i;
    display_by_loop(a);
    cout<<endl;
    del_dupli(a);
     display_by_loop(a);
    // cout<<size(a);
}