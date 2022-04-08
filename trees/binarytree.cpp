#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int main()
{

    Node *root = new Node(10);
    root->right = new Node(20);
    root->left = new Node(30);
    root->left->left = new Node(40);
}

//   INORDER PREORDER POSTORDER
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << (root->key) << " ";
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << (root->key) << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << (root->key) << " ";
    }
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
        return max(height(root->left), height(root->right)) + 1;
}

void printknode(Node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << (root->key) << " ";
    }
    else
    {
        printknode(root->left, k - 1);
        printknode(root->right, k - 1);
    }
}

void BFS(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << (temp->key) << " ";
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}

void BFS_newline(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << "\n";
            q.push(NULL);
            continue;
        }
        cout << (temp->key) << " ";
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}

void printlevelOrderline(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            cout << (curr->key) << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->left);
            cout << "\n";
        }
    }
}

int getSize(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + getSize(root->left) + getSize(root->right);
}

int maxBinary(Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->key, max(maxBinary(root->left), maxBinary(root->right)));
}

int maxlevel = 0;
void printLeft(Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level > maxlevel)
    {
        cout << root->key << " ";
        maxlevel = level;
    }
    printLeft(root->left, level + 1);
    printLeft(root->right, level + 1);
}

void printLeftView(Node *root)
{
    printLeft(root, 1);
}

void PrintLeft(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
            {
                cout << curr->key << " ";
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

// test wether the given tree obeys children sum property or not
bool childernSum(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    int sum = 0;
    if (root->left != NULL)
    {
        sum += root->left->key;
    }
    if (root->right != NULL)
    {
        sum += root->right->key;
    }
    return (root->key == sum) && childernSum(root->left) && childernSum(root->right);
}

// chcck if the tree is balanced or not

int balancer(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = balancer(root->left);
    if (lh == -1)
        return -1;
    int rh = balancer(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
}



int maxWidth(Node *root)
{
    if(root==NULL)
    {
        return 0;

    }
    queue<Node *>q;
    q.push(root);
    int res=0;
    while(q.empty()==false)
    {
        int count=q.size();
        res=max(res,count);
        for(int i=0;i<count;i++)
        {
            Node *curr=q.front();
            q.pop();
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }
    }
        return res;
}



//convert binary tree to doubly linked list
 Node* previous=NULL;
Node* BTToDL(Node *root)
{
    if(root==NULL) return root;
    Node *head =BTToDL(root->left);
    if(previous==NULL)head=root;
    else{
        root->left=previous;
        previous->right=root;

    }
    previous=root;
    BTToDL(root->right);
    return head;

}



//construct binary tree form inorder and preorder 

//given inorder traversal {20,10,30}
//given postorder traversal {10,20,30}

int preIndex=0;
Node *cTree(int in[],int pre[],int is,int ie)
{
    if(is>ie)return NULL;
    Node *root=new Node(pre[preIndex++]);
    int inIndex;
    for(int i=is;i<=ie;i++)
    {
        if(in[i]==root->key)
        {
            inIndex=i;
            break;
        }
    } 
    root->left=cTree(in,pre,is,inIndex-1);
    root->right=cTree(in,pre,inIndex+1,ie);
    return root;
}

//print spiral view of a binary tree
void printspiral(Node *root )
{
    if(root=NULL)return;
    queue<Node *>q;
    stack<int>s;
    bool reverse=false;
    q.push(root);
    while(q.empty()==false)
    {
        int count =q.size();
        for(int i=0;i<count;i++)
        {
            Node *cur=q.front();q.pop();
            if(reverse==true)
            {
                s.push(cur->key);
            }
            else
            {
                cout<<cur->key<<" ";
                if(cur->left!=NULL)q.push(cur->left);
                if(cur->right!=NULL)q.push(cur->right);

            }
        }
        if(reverse)
        {
            while(s.empty()==false)
            {
                cout<<s.top()<<" ";
                s.pop();

            }
        }
        reverse=!reverse;
        cout<<endl;    
    }
}

//altrnate method for spiral print 

void spiraller(Node *root)
{
    // stack 1 and stack 2
}


//Find diameter of binary tree


int  Diameter(Node *root)
{
    if(root==NULL)return 0;
     int d1=1+height(root->left)+height(root->right);
     int d2=Diameter(root->left);
     int d3=Diameter(root->right);
     return max(d1,d2,d3);

}

//better solution o(n)
//make a map for each node with node and height as a key value pair and then go down and traverse it 


//best solution without extra overhead;

int res=0;
int DiameterEffecient(Node *root)
{
  if(root=NULL)return 0;
  int lh=DiameterEffecient(root->left);
  int rh=DiameterEffecient(root->right);
  res=max(res,lh+rh+1);
  return (1+max(rh,lh));
}


//LCA of Binary tree
//Lowest common ancestor of a binary tree

bool findpath(Node *root ,vector<Node *> &p,int n)
{
    if(root==NULL)return false;
    p.push_back(root);
    if(root->key==n)return true;
    if(findpath(root->left,p,n)||findpath(root->right,p,n))
    {
        return true;
    }
    p.pop_back();
    return false;

}

Node *lca(Node *root,int n1 ,int n2 )
{
    vector<Node *> path1,path2;
    if(findpath(root,path1,n1)==false||findpath(root,path2,n2)==false)
    {
        return NULL;
    }
    for(int i=0;i<path1.size()-1&& i<path2.size()-1;i++)
    {
        if(path1[i+1]!=path2[i+1])
        {
            return path1[i];
        }
    }
    return NULL;
}



Node* lcaeffecient(Node *root,int n1,int n2)
{
  if(root==NULL)return NULL;
  if(root->key==n1 ||root->key==n2)return root;
  Node *lca1=lcaeffecient(root->left,n1,n2);
  Node *lca2=lcaeffecient(root->right,n1,n2);
  if(lca1!=NULL && lca2!=NULL)return root;
  if(lca1!=NULL)return lca1;
  else return lca2;
}
//end of lca finding function



//burn a binary tree from a leaf

int res=0;
int burnTime(Node *root,int leaf,int &dist)
{
    if(root==NULL)return 0;
    if(root->key==leaf){dist=0;return 1;}
    int ldist=-1,rdist=-1;
    int lh =burnTime(root->left,leaf,ldist);
    int rh =burnTime(root->right,leaf,rdist);
    if(ldist!=-1)
    {
        dist=ldist+1;
        res=max(res,dist+rh);
    }
    else if(rdist!=-1)
    {
        dist=rdist+1;
        res=max(res,dist+lh);
    }
    return max(lh,rh)+1;
}


//count nodes in complete binary tree

int countNode(Node *root)
{
    if(root==NULL)return 0;
    else return 1+countNode(root->left)+countNode(root->right);
}

// efficient approach

int countNodeEffieciently(Node *root)
{
    int lh=0,rh=0;
    Node *curr=root;
    while(curr!=NULL)
    {
        lh++;
        curr=curr->left;
    }
    curr=root;
    while(curr!=NULL)
    {
        rh++;
        curr=curr->right;
    }
    if(rh=lh)return pow(2,lh)-1;
    else return 1+ countNodeEffieciently(root->left)+countNodeEffieciently(root->right);
}



// serialize and deserialize a binary tree

// we need two functions 

// void serialize(Node *root,vector<int>&arr);
// Node* deserialize(vector<int>&arr);

const int EMPTY=-1;
void serialize(Node *root,vector<int>&arr)
{
    if(root==NULL)
    {
        arr.push_back(EMPTY);
        return;
    }
    arr.push_back(root->key);
    serialize(root->left,arr);
    serialize(root->right,arr);
}

int index=0;
Node* deserialize(vector<int>&arr)
{
    if(index==arr.size())return NULL;
    int key=arr[index];
    index++;
    if(key==EMPTY)return NULL;
    Node *root=new Node(key);
    root->left=deserialize(arr);
    root->right=deserialize(arr);
    return root;
}


//iterative inorder traversal
void itrerativeInorder(Node *root)
{   if(root==NULL)return;
    stack<Node *>s;
    Node *curr=root;
    while(curr!=NULL||s.empty()==false)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->key<<" ";
        curr=curr->right;
    }
}


//iterative preorder traversal
void itrerativePreorder(Node *root)
{   if(root==NULL)return;
    stack<Node *>s;
    Node *curr=root;
    while(curr!=NULL||s.empty()==false)
    {
        while(curr!=NULL)
        {
            cout<<curr->key<<" ";
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        curr=curr->right;
    }
}

//iterative Preorder Traversal (space optimized)
void iterativePreorderSpaceOptimized(Node *root)
{
    if(root==NULL)return;
    stack<Node *>s;
    s.push(root);
    while(s.empty()==false)
    {
        Node *curr=s.top();
        s.pop();
        cout<<curr->key<<" ";
        if(curr->right!=NULL)s.push(curr->right);
        if(curr->left!=NULL)s.push(curr->left);
    }
}

//iterative postorder traversal
void itrerativePostorder(Node *root)
{   if(root==NULL)return;
    stack<Node *>s;
    Node *curr=root;
    Node *prev=NULL;
    while(curr!=NULL||s.empty()==false)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        if(curr->right==NULL||curr->right==prev)
        {
            cout<<curr->key<<" ";
            s.pop();
            prev=curr;
            curr=NULL;
        }
        else
        {
            curr=curr->right;
        }
    }
}

//iterative Postorder Traversal (space optimized)
void iterativePostorderSpaceOptimized(Node *root)
{
    if(root==NULL)return;
    stack<Node *>s;
    Node *curr=root;
    Node *prev=NULL;
    while(curr!=NULL||s.empty()==false)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        if(curr->right==NULL||curr->right==prev)
        {
            cout<<curr->key<<" ";
            s.pop();
            prev=curr;
            curr=NULL;
        }
        else
        {
            curr=curr->right;
        }
    }
}




//iterative levlorder traversal
void itrerativeLevelorder(Node *root)
{   if(root==NULL)return;
    queue<Node *>q;
    Node *curr=root;
    q.push(curr);
    while(q.empty()==false)
    {
        curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left!=NULL)q.push(curr->left);
        if(curr->right!=NULL)q.push(curr->right);
    }
}


//iterative Levelorder Traversal (space optimized)
void iterativeLevelorderSpaceOptimized(Node *root)
{
    if(root==NULL)return;
    queue<Node *>q;
    Node *curr=root;
    q.push(curr);
    while(q.empty()==false)
    {
        curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left!=NULL)q.push(curr->left);
        if(curr->right!=NULL)q.push(curr->right);
    }
}


//iterative Inorder Traversal (space optimized)
void iterativeInorderSpaceOptimized(Node *root)
{
    if(root==NULL)return;
    stack<Node *>s;
    Node *curr=root;
    while(curr!=NULL||s.empty()==false)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->key<<" ";
        curr=curr->right;
    }
}





