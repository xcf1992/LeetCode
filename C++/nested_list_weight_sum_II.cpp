/*
364. Nested List Weight Sum II
https://leetcode.com/problems/nested-list-weight-sum-ii/

Given a nested list of integers,
return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Different from the previous question where weight is increasing from root to leaf,
now the weight is defined from bottom up. i.e., the leaf level integers have weight 1,
and the root level integers have the largest weight.

Example 1:
Input: [[1,1],2,[1,1]]
Output: 8
Explanation: Four 1's at depth 1, one 2 at depth 2.

Example 2:
Input: [1,[4,[6]]]
Output: 17
Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 13 + 42 + 61 = 17.
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
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
private:
    int getMaxDepth(vector<NestedInteger>& nestedList) {
        int result = 1;
        for (int i = 0; i < nestedList.size(); i++) {
            if (!nestedList[i].isInteger()) {
                result = max(result, getMaxDepth(nestedList[i].getList()) + 1);
            }
        }
        return result;
    }

    int calculate(vector<NestedInteger>& nestedList, int depth) {
        int result = 0;
        for (int i = 0; i < nestedList.size(); i++) {
            if (nestedList[i].isInteger()) {
                result += nestedList[i].getInteger() * depth;
            }
            else {
                result += calculate(nestedList[i].getList(), depth - 1);
            }
        }
        return result;
    }
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = getMaxDepth(nestedList);
        return calculate(nestedList, depth);
    }
};