#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
};

void insertAthead(Node* &head ,int d)
{
    Node* temp = new Node(d);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    tail=temp;
    
}
void insertAtMiddle(Node* &head, int position , int d)
{
    if(position==1) {
        insertAthead(head ,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;


}

void print( Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
       cout<<temp->data<<" ";
       temp=temp->next;
    }cout<<endl;
    
}

int main()
{
    Node* node = new Node(10);
    Node* head=node;
    Node* tail = node;
    print(node);
}