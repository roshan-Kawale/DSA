#include<iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char ch) {
        data = ch;
        for(int i=0;i<26;i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    public: 
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root , string word) {
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        
        //present
        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        insertUtil(child , word.substr(1));
    }
    
    void insertWord(string word) {
        insertUtil(root , word);
    }
    
    //search the word in Trie
    bool searchUtil( TrieNode* root , string word) {
        if(word.length() == 0 ) {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        //present
        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            //absent
            return false;
        }
        return searchUtil(child , word.substr(1));
    }
    
    bool searchWord(string word) {
        return searchUtil(root , word);
    }
    
    //remove the word from Trie
    void removeUtil(TrieNode* root , string word) {
        if(word.length() == 0) {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        
        //present
        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            //absent
            return;
        }
        removeUtil(child , word.substr(1));
    }
    void removeWord(string word) {
        removeUtil(root , word);
    }
};

int main() {
    Trie* t = new Trie();
    
    t->insertWord("abcde");
    cout<<"Present " << t->searchWord("abcde")<<endl;
    t->removeWord("abcde");
    cout<<"Present " << t->searchWord("abcde")<<endl;
}