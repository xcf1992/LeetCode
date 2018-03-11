/*
 Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
 
 Note:
 Given target value is a floating point.
 You may assume k is always valid, that is: k ≤ total nodes.
 You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
 Follow up:
 Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
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
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> larger;
        stack<TreeNode*> smaller;
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (cur -> val > target) {
                larger.push(cur);
                cur = cur -> left;
            }
            else {
                smaller.push(cur);
                cur = cur -> right;
            }
        }
        
        vector<int> closet;
        while (closet.size() < k) {
            if (larger.empty() ||
                 (!smaller.empty() && larger.top() -> val - target > target - smaller.top() -> val)) {
                cur = smaller.top();
                smaller.pop();
                closet.push_back(cur -> val);
                
                cur = cur -> left;
                while (cur != nullptr) {
                    smaller.push(cur);
                    cur = cur -> right;
                }
            }
            else {
                cur = larger.top();
                larger.pop();
                closet.push_back(cur -> val);
                
                cur = cur -> right;
                while (cur != nullptr) {
                    larger.push(cur);
                    cur = cur -> left;
                }
            }
        }
        return closet;
    }
};