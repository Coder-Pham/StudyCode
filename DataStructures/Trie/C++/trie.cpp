/**
 * @author Nhat M. Nguyen
 * @update 23-09-18
**/


#include <bits/stdc++.h>


using namespace std;


struct TrieNode {
    bool endOfWord;
    char key;
    map<char, TrieNode*> children;

    TrieNode(char key) {
        this->key = key;
        this->endOfWord = false;
    }
};


struct Trie {
    TrieNode* root;

    Trie() {
        this->root = new TrieNode('\0', NULL);
    }

    /**
     * Time complexity: O(length(s))
    **/
    void insert(string s) {
        TrieNode* node = this->root;

        for (char c : s) {
            auto nextNodeIt = node->children.find(c);
            if (nextNodeIt == node->children.end()) {
                node->children.emplace(c, new TrieNode(c));
                nextNodeIt = node->children.find(c);
            }
            node = nextNodeIt->second;
        }

        node->endOfWord = true;
    }

    /**
     * Time complexity: O(length(s))
    **/
    bool hasWord(string s) {
        TrieNode* node = this->root;

        for (char c : s) {
            auto nextNodeIt = node->children.find(c);
            if (nextNodeIt == node->children.end()) {
                return false;
            }
            node = nextNodeIt->second;
        }
        
        return node->endOfWord;
    }

    TrieNode* find(string s) {
        TrieNode* node = this->root;

        for (char c : s) {
            auto nextNodeIt = node->children.find(c);
            if (nextNodeIt == node->children.end()) {
                return NULL;
            }
            node = nextNodeIt->second;
        }
        
        return node;
    }

    vector<string> getWords() {
        return this->getWords(this->root, "");
    }

    vector<string> getWords(TrieNode* subTrieRoot, string prefix) {
        vector<string> res;
        map<char, TrieNode*> &children = subTrieRoot->children;

        for (auto it = children.begin(); it != children.end(); it++) {
            TrieNode* child = it->second;

            if (child->endOfWord) {
                res.emplace_back(prefix + child->key);
            }

            vector<string> wordsFromChild = this->getWords(child, prefix + child->key);
            for (string &word : wordsFromChild) {
                res.emplace_back(word);
            }
        }

        return res;
    }
};
