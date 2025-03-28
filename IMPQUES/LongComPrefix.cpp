#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26]; // 26 English lowercase letters
    bool isTerminal;
    int childCount;

    TrieNode(char ch) {
        data = ch;
        isTerminal = false;
        childCount = 0;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};


class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0'); 
    }


    void insertWord(string word) {
        TrieNode* current = root;

        for (char ch : word) {
            int index = ch - 'a'; 
            
            
            if (current->children[index] == NULL) {
                current->children[index] = new TrieNode(ch);
                current->childCount++;
            }
            
            current = current->children[index]; 
        }
        current->isTerminal = true; 
    }

    string longestCommonPrefix(string firstWord) {
        string ans = "";
        TrieNode* current = root;

        for (char ch : firstWord) {
            int index = ch - 'a';
            
         
            if (current->childCount != 1 || current->isTerminal)
                break;

            ans += ch; 
            current = current->children[index]; 
        }
        return ans;
    }
};


string longestCommonPrefix(vector<string>& arr, int n) {
  if (n == 0) return "";

  Trie* t = new Trie();

  // Insert all words into Trie
  for (string word : arr) {
      t->insertWord(word);
  }

  // Get LCP from the first word
  return t->longestCommonPrefix(arr[0]);
}

