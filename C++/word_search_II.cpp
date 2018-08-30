/*
 Given a 2D board and a list of words from the dictionary, find all words in the board.
 
 Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
 
 Example:
 
 Input:
 words = ["oath","pea","eat","rain"] and board =
 [
 ['o','a','a','n'],
 ['e','t','a','e'],
 ['i','h','k','r'],
 ['i','f','l','v']
 ]
 
 Output: ["eat","oath"]
 Note:
 You may assume that all inputs are consist of lowercase letters a-z.
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
using namespace std;

struct TrieNode {
    bool isWord;
    string word;
    vector<TrieNode*> next;
    
    TrieNode() {
        word = "";
        isWord = false;
        next.resize(26, nullptr);
    }
};

class Solution {
private:
    TrieNode* root = new TrieNode;
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur -> next[c - 'a'] == nullptr) {
                cur -> next[c - 'a'] = new TrieNode;
            }
            cur = cur -> next[c - 'a'];
        }
        cur -> word = word;
        cur -> isWord = true;
    }
    
    void findWord(vector<string>& result, vector<vector<bool>>& visited, vector<vector<char>>& board, TrieNode* cur, int r, int c) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || visited[r][c] || cur == nullptr) {
            return;
        }
        
        TrieNode* next = cur -> next[board[r][c] - 'a'];
        if (next != nullptr and next -> isWord) {
            result.push_back(next -> word);
            next -> isWord = false;
        }
        
        visited[r][c] = true;
        findWord(result, visited, board, next, r - 1, c);
        findWord(result, visited, board, next, r + 1, c);
        findWord(result, visited, board, next, r, c - 1);
        findWord(result, visited, board, next, r, c + 1);
        visited[r][c] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string word : words) {
            addWord(word);
        }
        
        int m = board.size();
        int n = board[0].size();
        vector<string> found;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                findWord(found, visited, board, root, i, j);
            }
        }
        return found;
    }
};
