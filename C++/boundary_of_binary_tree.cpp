/*
545. Boundary of Binary Tree
https://leetcode.com/problems/boundary-of-binary-tree/

Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root.
Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.

Left boundary is defined as the path from root to the left-most node.
Right boundary is defined as the path from root to the right-most node.
If the root doesn't have left subtree or right subtree,
then the root itself is left boundary or right boundary.
Note this definition only applies to the input binary tree,
and not applies to any subtrees.

The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists.
If not, travel to the right subtree. Repeat until you reach a leaf node.

The right-most node is also defined by the same way with left and right exchanged.

Example 1
Input:
  1
   \
    2
   / \
  3   4
Ouput:
[1, 3, 4, 2]
Explanation:
The root doesn't have left subtree, so the root itself is left boundary.
The leaves are node 3 and 4.
The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
So order them in anti-clockwise without duplicates and we have [1,3,4,2].

Example 2
Input:
    ____1_____
   /          \
  2            3
 / \          /
4   5        6
   / \      / \
  7   8    9  10
Ouput:
[1,2,4,7,8,9,10,6,3]
Explanation:
The left boundary are node 1,2,4. (4 is the left-most node according to definition)
The leaves are node 4,7,8,9,10.
The right boundary are node 1,3,6,10. (10 is the right-most node).
So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <stdio.h>
#include <set>
#include <numeric>
#include "extra_data_types.hpp"
using namespace std;

class Solution {
private:
    void getLeftPath(TreeNode* root, vector<int>& leftPath, bool boundary) {
        if (root == nullptr) {
            return;
        }

        if (root -> left == nullptr and root -> right == nullptr) {
            leftPath.push_back(root -> val);
            return;
        }

        if (boundary) {
            leftPath.push_back(root -> val);
        }
        getLeftPath(root -> left, leftPath, boundary);
        getLeftPath(root -> right, leftPath, boundary and root -> left == nullptr);
    }

    void getRightPath(TreeNode* root, vector<int>& rightPath, bool boundary) {
        if (root == nullptr) {
            return;
        }

        if (root -> left == nullptr and root -> right == nullptr) {
            rightPath.push_back(root -> val);
            return;
        }

        if (boundary) {
            rightPath.push_back(root -> val);
        }
        getRightPath(root -> right, rightPath, boundary);
        getRightPath(root -> left, rightPath, boundary and root -> right == nullptr);
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> leftPath;
        getLeftPath(root -> left, leftPath, true);
        vector<int> rightPath;
        getRightPath(root -> right, rightPath, true);
        reverse(rightPath.begin(), rightPath.end());

        vector<int> result;
        result.push_back(root -> val);
        for (int i : leftPath) {
            result.push_back(i);
        }
        for (int i : rightPath) {
            result.push_back(i);
        }
        return result;
    }
};
