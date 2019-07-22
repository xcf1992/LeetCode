/*
1120. Maximum Average Subtree
Given the root of a binary tree, find the maximum average value of any subtree of that tree.

(A subtree of a tree is any node of that tree plus all its descendants.
The average value of a tree is the sum of its values,
divided by the number of nodes.)

Example 1:
        5
    /       \
    6       1
Input: [5,6,1]
Output: 6.00000
Explanation:
For the node with value = 5 we have and average of (5 + 6 + 1) / 3 = 4.
For the node with value = 6 we have and average of 6 / 1 = 6.
For the node with value = 1 we have and average of 1 / 1 = 1.
So the answer is 6 which is the maximum.


Note:

The number of nodes in the tree is between 1 and 5000.
Each node will have a value between 0 and 100000.
Answers will be accepted as correct if they are within 10^-5 of the correct answer.
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
#include "extra_data_types.hpp"
using namespace std;

class Solution {
private:
    pair<double, double> traverse(TreeNode* root, double& result) {
        if (root == nullptr) {
            return {0.0, 0.0};
        }

        if (root -> left == nullptr and root -> right == nullptr) {
            result = max(result, (double)(root -> val));
            return {root -> val, 1.0};
        }

        pair<double, double> lft = traverse(root -> left, result);
        pair<double, double> rgt = traverse(root -> right, result);
        double sum = root -> val + lft.first + rgt.first;
        double count = 1 + lft.second + rgt.second;
        double avg = sum / count;
        result = max(result, avg);
        return {sum, count};
    }
public:
    double maximumAverageSubtree(TreeNode* root) {
        double result = 0.0;
        traverse(root, result);
        return result;
    }
};