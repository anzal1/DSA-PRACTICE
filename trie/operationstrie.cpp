#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *child[26];
    bool isEnd;
    TreeNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};

bool search(string a)
{
    TreeNode *root = new TreeNode();
    for (int i = 0; i < a.length(); i++)
    {
        if (root->child[a[i] - 'a'] == NULL)
        {
            root->child[a[i] - 'a'] = new TreeNode();
        }
        root = root->child[a[i] - 'a'];
    }
    root->isEnd = true;
    return root->isEnd;
}

void insert(string a)
{
    TreeNode *root = new TreeNode();
    for (int i = 0; i < a.length(); i++)
    {
        if (root->child[a[i] - 'a'] == NULL)
        {
            root->child[a[i] - 'a'] = new TreeNode();
        }
        root = root->child[a[i] - 'a'];
    }
    root->isEnd = true;
}

void deleteNode(TreeNode *root, string &key, int i)
{
    if (i == key.length())
    {
        if (root->isEnd)
        {
            root->isEnd = false;
        }
        return;
    }
    if (root->child[key[i] - 'a'] != NULL)
    {
        deleteNode(root->child[key[i] - 'a'], key, i + 1);
    }
}