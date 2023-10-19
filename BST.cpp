#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
// void levelOrderTraversal(Node* root)
// {
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);

//     while(!q.empty())
//     {
//         Node* temp = q.front();
//         q.pop();

//         if(temp==NULL)
//         {
//             cout<<endl;

//             if(!q.empty())
//             {
//                 q.push(NULL);
//             }
//         }else{
//             cout<<temp->data<<" ";

//             if(temp->left) {q.push(temp->left);}
//             if(temp->right) {q.push(temp->right);}
//         }
//     }
    

// }

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    
}

void inOrder(Node* root){
if(root==NULL) return;
inOrder(root->left);
cout<<root->data<<" ";
inOrder(root->right);
}



Node* insertIntoBST(Node* root,int d){
    if(root==NULL) {
        root = new Node(d);
        return root;
    }
    if(d>root->data)
    {
        root->right = insertIntoBST(root->right,d);
    }else{
        root->left = insertIntoBST(root->left,d);
    }
    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;
    while (data != -1)
    {
        root = insertIntoBST(root,data);
        cin>>data;
    }
    
}

int main()
{
    Node* root = NULL;
    cout<<"enter data to create BST"<<endl;
    takeInput(root);

    cout<<"printing the BST"<<endl;
    levelOrderTraversal(root);
   inOrder(root);
    return 0;
}
