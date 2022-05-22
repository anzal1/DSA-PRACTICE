#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *child[2];

    TreeNode()
    {
        child[0] = NULL;
        child[1] = NULL;
    }
};

bool insert(TreeNode *root, int row)
{
    if (root->child[row] == NULL)
    {
        root->child[row] = new TreeNode();
        return true;
    }
    return false;
}

int countDist(int a[][10], int n, int m)
{
    TreeNode *root = new TreeNode();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (insert(root, a[i][j]))
            {
                count++;
            }
        }
    }
    return count;
}
