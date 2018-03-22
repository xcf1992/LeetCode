/*
 Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
 
 If two nodes are in the same row and column, the order should be from left to right.
 
 Examples:
 
 Given binary tree [3,9,20,null,null,15,7],
       3
      /\
     /  \
    9  20
   /\
  /  \
 15   7
 return its vertical order traversal as:
 [
 [9],
 [3,15],
 [20],
 [7]
 ]
 Given binary tree [3,9,8,4,0,1,7],
      3
     /\
    /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
 return its vertical order traversal as:
 [
 [4],
 [9],
 [3,0,1],
 [8],
 [7]
 ]
 Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
       3
      /\
     /  \
    9   8
   /\  /\
  /  \/  \
 4  01   7
    /\
   /  \
  5   2
 return its vertical order traversal as:
 [
 [4],
 [9,5],
 [3,0,1],
 [8,2],
 [7]
 ]
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
#include <set>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
private:
    int getHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        return max(getHeight(root -> left), getHeight(root -> right)) + 1;
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        int height = getHeight(root);
        vector<vector<int>> pos(pow(2, height), vector<int>());
        queue<pair<int, TreeNode*>> bfs;
        bfs.push(make_pair(height, root));
        while (!bfs.empty()) {
            int index = bfs.front().first;
            TreeNode* cur = bfs.front().second;
            bfs.pop();
            
            if (cur == nullptr) {
                continue;
            }
            
            pos[index].push_back(cur -> val);
            bfs.push(make_pair(index - 1, cur -> left));
            bfs.push(make_pair(index + 1, cur -> right));
        }
        
        for (auto& col : pos) {
            if (!col.empty()) {
                result.push_back(col);
            }
        }
        return result;
    }
};