#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
Node *root;
// find ceiling on the left side of the element using set

void findCeiling(int arr[], int key)
{
    int len = sizeof(arr) / sizeof(arr[0]);
    set<int> s;
    for (int i = 0; i < len; i++)
    {
        s.insert(arr[i]);
    }
    auto it = s.lower_bound(key);
    if (it != s.end())
    {
        cout << *it;
    }
    else
    {
        cout << -1;
    }
}

// find kth smallest element in a  BST
int counter = 0;
void kthSmallest(Node *root, int k)
{
    if (root == NULL)
        return;
    kthSmallest(root->left, k);
    counter++;
    if (counter == k)
    {
        counter << root->data;
        return;
    }
    kthSmallest(root->right, k);
}

/////////////////////////////////////////////////////////////////////////////////////////////

// efficiently find kth smallest element in a BST
// augmented tree bst

struct questions
{
    int data;
    int count;
    questions *left, *right;
    questions(int x)
    {
        data = x;
        count = 1;
        left = NULL;
        right = NULL;
    }
};

questions *root;

void kthSmallest(questions *root, int k)
{
    if (root == NULL)
        return;
    kthSmallest(root->left, k);
    root->count++;
    if (root->count == k)
    {
        cout << root->data;
        return;
    }
    kthSmallest(root->right, k);
}

void insertNodes(questions *root, int x)
{
    if (root == NULL)
    {
        root = new questions(x);
        return;
    }
    if (root->data > x)
    {
        if (root->left == NULL)
        {
            root->left = new questions(x);
            return;
        }
        else
        {
            insertNodes(root->left, x);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = new questions(x);
            return;
        }
        else
        {
            insertNodes(root->right, x);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////

// check for BST

bool checkBST(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if (root->left == NULL)
    {
        if (root->data < root->right->data)
            return checkBST(root->right);
        else
            return false;
    }
    if (root->right == NULL)
    {
        if (root->data > root->left->data)
            return checkBST(root->left);
        else
            return false;
    }
    if (root->data > root->left->data && root->data < root->right->data)
    {
        return checkBST(root->left) && checkBST(root->right);
    }
    else
        return false;
}

// efficiently check for BST

bool checkEfficientlyBST(Node *root, int min, int max)
{
    if (root == NULL)
        return true;
    if (root->data < min || root->data > max)
        return false;
    return checkEfficientlyBST(root->left, min, root->data) && checkEfficientlyBST(root->right, root->data, max);
}

bool checkeffBST(Node *root)
{
    return checkEfficientlyBST(root, INT_MIN, INT_MAX);
}

// best way to check for BST

// inorder traversal of binary tree is sorted

int previous = INT_MIN;
bool isBST(Node *root)
{
    if (root == NULL)
        return true;
    if (!isBST(root->left))
        return false;
    if (previous > root->data)
        return false;
    previous = root->data;
    return isBST(root->right);
}

// fix bst with two nodes swapped
Node *previ = NULL, *first = NULL, *second = NULL;
void fixBST(Node *root)
{
    if (root == NULL)
        return;
    fixBST(root->left);
    if (previ != NULL && root->data < previ->data)
    {
        if (first == NULL)
        {
            first = previ;
        }
        second = root;
    }
    previ = root;
    fixBST(root->right);
}

// find pair sum in given BST

// use of hashing

bool isPairPresent(Node *root, int sum, unordered_set<int> &s)
{
    if (root == NULL)
        return false;
    if (s.find(sum - root->data) != s.end())
        return true;
    s.insert(root->data);
    return isPairPresent(root->left, sum, s) || isPairPresent(root->right, sum, s);
}



//vertical sum in a binary tree

void printVerticalSum(Node *root, int hd, map<int, int> &m)
{
    if (root == NULL)
        return;
    m[hd] += root->data;
    printVerticalSum(root->left, hd - 1, m);
    printVerticalSum(root->right, hd + 1, m);
}


void vsum(Node *root)
{
    map<int, int> m;
    printVerticalSum(root, 0, m);
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->second << " ";
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////



//print vertical order traversal of a binary tree

void printVerticalOrder(Node *root, int hd, map<int, vector<int>> &m)
{
    if (root == NULL)
        return;
    m[hd].push_back(root->data);
    printVerticalOrder(root->left, hd - 1, m);
    printVerticalOrder(root->right, hd + 1, m);
}

void pvorder(Node *root)
{
    map<int, vector<int>> m;
    printVerticalOrder(root, 0, m);
    for (auto it = m.begin(); it != m.end(); it++)
    {
        for (auto it1 = it->second.begin(); it1 != it->second.end(); it1++)
        {
            cout << *it1 << " ";
        }
    }
}