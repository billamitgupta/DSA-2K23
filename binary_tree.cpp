#include<bits/stdc++.h>
#include <iostream>

using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
    
  node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

node* buildtree(node* root)
{
  cout << "enter the data " << endl;
  int data;
  cin >> data;
  root= new node(data);
  
  if(data==-1) {return NULL;}
  
  cout<<"enter the data for inserting in left node "<<data<<endl;
  root->left=buildtree(root->left);
  cout<<"enter the data for inserting in right node "<<data<<endl;
  root->right = buildtree(root->right);
  return root;

}

void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
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

void buildFromLevelOrder(node* root)
{
    queue<node*> q;
    int data;
    cout<<"enter data dor root "<<endl;
    cin>>data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout<<"enter the left node "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout<<"enter the right node "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1)
        {
            temp->right = new node(rightdata);
        }
    }
    
}

void inOrder(node* root)
{
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(node* root)


{
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void preOrder(node* root)


{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    
}


int main ()
{
  node* root = NULL;
  root = buildtree(root);

  buildFromLevelOrder(root);
  
//   cout<<"printing the level order traversal output< "<<endl;
//   levelOrderTraversal(root);
//   cout<<"Inorder traversal : "<<endl;      //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//   inOrder(root);

//   cout<<"postOrder traversal : "<<endl;
//   postOrder(root);

//   cout<<"PreOrder traversal: "<<endl;
//   preOrder(root);
  return 0;
}
