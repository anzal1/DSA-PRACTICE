#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};
Node *root;

// recursive function to insert a node in the BST
bool search(Node *root, int x)
{
    if (root == NULL)
        return false;
    else if (root->key == x)
        return true;
    else if (root->key > x)
        return search(root->left, x);
    else
        return search(root->right, x);
}

// iterative search
bool search_iterative(Node *root, int x)
{
    while (root != NULL)
    {
        if (root->key == x)
            return true;
        else if (root->key > x)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

// recruisive insertion
Node *inserter(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    else if (root->key < val)
        root->right = inserter(root->right, val);
    else if (root->key > val)
        root->left = inserter(root->left, val);
    return root;
}

// iterative insert
Node *inserter_iterative(Node *root, int val)
{
    Node *temp = root;
    Node *prev = NULL;
    while (temp != NULL)
    {
        prev = temp;
        if (temp->key < val)
            temp = temp->right;
        else
            temp = temp->left;
    }
    if (prev->key < val)
        prev->right = new Node(val);
    else
        prev->left = new Node(val);
    return root;
}

// recurvise deletion
Node *deleter(Node *root, int val)
{
    if (root == NULL)
        return root;
    else if (root->key < val)
        root->right = deleter(root->right, val);
    else if (root->key > val)
        root->left = deleter(root->left, val);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;
        root->key = temp->key;
        root->right = deleter(root->right, temp->key);
    }
    return root;
}

// iterative deletion
Node *deleter_iterative(Node *root, int val)
{
    Node *temp = root;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->key == val)
            break;
        else if (temp->key > val)
        {
            prev = temp;
            temp = temp->left;
        }
        else
        {
            prev = temp;
            temp = temp->right;
        }
    }
    if (temp == NULL)
        return root;
    else if (temp->left == NULL)
    {
        if (prev == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (prev->key < val)
        {
            prev->right = temp->right;
            delete temp;
            return root;
        }
        else
        {
            prev->left = temp->right;
            delete temp;
            return root;
        }
    }
    else if (temp->right == NULL)
    {
        if (prev == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (prev->key < val)
        {
            prev->right = temp->left;
            delete temp;
            return root;
        }
        else
        {
            prev->left = temp->left;
            delete temp;
            return root;
        }
    }
    else
    {
        Node *temp = temp->right;
        while (temp->left != NULL)
            temp = temp->left;
        temp->left = temp->left;
        delete temp;
    }
    return root;
}

// floor of a given key in BST

Node *floor_calc(Node *root, int x)
{
    Node *res = NULL;
    while (root != NULL)
    {
        if (root->key == x)
        {
            return root;
        }
        else if (root->key > x)
            root = root->left;

        else
        {
            res = root;
            root = root->right;
        }
    }
    return res;
}

// ciel of a given key in BST

Node *ceil_calc(Node *root, int x)
{
    Node *res = NULL;
    while (root != NULL)
    {
        if (root->key == x)
        {
            return root;
        }
        else if (root->key > x)
        {
            res = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return res;
}

// self balancing BST

// AVL tree and RED BLACK TREE


// AVL TREE ====>>

// BALANCE FACTOR = RIGHT - LEFT; // if it is -1 then it is left heavy else it is right heavy

// h< clog2(n+2)+b
//where c ~ 1.4405
//b ` -1.3277


//red black tree , black height should be same for both left and right subtree
