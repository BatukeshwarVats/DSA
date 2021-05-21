/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
class Node{
    public:
        int data;
        Node* next;
};
void print(Node* n){
    while(n!=NULL){
        std::cout << n->data << std::endl;
        n=n->next;
    }
}
void push(Node ** head_ref,int new_data){
    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}
void insertafter(Node* prev_node,int new_data){
    if (prev_node==NULL){
        cout<<"It cannot be null.";
        return;
    }
    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=prev_node->next;
    prev_node->next=new_node;
}
void insertatend(Node**head_ref,int new_data){
    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=NULL;
    Node *last=*head_ref;
    if (*head_ref==NULL){
        *head_ref=new_node;
        return;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=new_node;
    return;
}
int main()
{
    Node* head=NULL;
    Node* second=NULL;
    Node*third=NULL;
    head=new Node();
    second=new Node();
    third=new Node();
    head->data=3;
    head->next=second;
    second->data=6;
    second->next=third;
    third->data=1;
    third->next=NULL;
    push(&head,7);
    insertafter(head->next->next,10);
    insertatend(&head,50);
    print(head);

    return 0;
}
