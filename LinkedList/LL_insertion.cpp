#include <iostream>
using namespace std;

class node
{   
    public:
    int data;
    node* next;

    node(int d)
    {
        data=d;
        next=NULL;
    }

};

void insertAtHead(node* &head,int d) //head is passed by reference because we actually want the changes to occur at head
{
    node* n= new node(d);
    n->next=head;
    head=n;
}

void print(node* head)      ///passed by value because we dont want any changes in the linked list
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";     ///here instead of temp, head can be directly used because any changes made to head at this level wont affect the head in
        temp=temp->next;            /// main since the head is passed by value
    }
    cout<<endl;
}


int main() {
    node* head=NULL;
    
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);

    print(head);
}
