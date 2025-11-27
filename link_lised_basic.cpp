// #include <iostream>
// using namespace std;
// class Node{
//     public:
//     int val;
//     Node* next;
//     Node(int val){
//         this->val = val;
//         this->next = NULL;
//     }
// };
// void display_by_loop(Node* head){
//         Node* temp = head;
// while(temp!=NULL){
//     cout<<temp->val<<" ";
//     temp = temp->next;
// }
// cout<<"\n";
// }
//  int size(Node* head ){
//     Node* temp =head;
//     int n = 0;
//     while(temp!=NULL){
//         n++;
//         temp = temp->next;
//     }
//     return n;
//  }
// int main(){
//     Node* a = new Node(10) ;
//     Node* b = new Node(20);
//     Node* c = new Node(30);
//     Node* d = new Node(40);
//     a->next = b;
//     b->next = c;
//     c->next =d;
//     display_by_loop(a);
//     cout<<size(a);

// }


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

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = NULL; //nusll->3
    Node* temp = NULL; //3 

    for (int i = 1; i <= n; i++) {
        int val;
        cout << "Enter value for node " << i  << ": ";
        cin >> val; //3 5

        Node* newNode = new Node(val); //3 5

        if (head == NULL) {
            head = newNode; //3
            temp = newNode; //3
        } else {
            temp->next = newNode; //  
            temp = newNode;  // 5
        }
    }

    display_by_loop(head);
    cout << "\nSize = " << size(head);

    return 0;
}
