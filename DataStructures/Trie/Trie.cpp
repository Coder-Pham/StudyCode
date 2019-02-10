/**
 * Author:  Pham T. Nhan
 * DS:      Trie
 */

#include <iostream>

using namespace std;

// Character Trie
struct Node
{
    Node *child[26];
    int countLeaf;
};

Node *newNode()
{
    Node *node = new Node();
    for (int i = 0; i < 26; i++)
        node->child[i] = NULL;
    node->countLeaf = 0;
    return node;
}

void addNode(Node *root, string s)
{
    int ch;
    Node *temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
        {
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
    }
    temp->countLeaf++;
}

bool findWord(Node *root, string s)
{
    int ch;
    Node *temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
            return false;
        temp = temp->child[ch];
    }
    return temp->countLeaf > 0;
}

// Recursive in Deletion
bool isEmpty(Node *node)
{
    for (int i = 0; i < 26; i++)
        if (node->child[i] != NULL)
            return false;
    return true;
}

bool removeWord(Node *root, string s, int level, int length)
{
    if (!root)
        return false;
    int ch = s[level] - 'a';
    // Final character
    if (level == length)
    {
        if (root->countLeaf > 0)
        {
            root->countLeaf--;
            return true;
        }
        return false;
    }

    int flag = removeWord(root->child[ch], s, level + 1, length);
    if (flag && root->child[ch]->countLeaf == 0 && isEmpty(root->child[ch]))
    {
        delete root->child[ch];
        root->child[ch] = NULL;
    }
    return flag;
}