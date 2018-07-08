/*
 You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
 
 Define a pair (u,v) which consists of one element from the first array and one element from the second array.
 
 Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 
 Example 1:
 Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
 
 Return: [1,2],[1,4],[1,6]
 
 The first 3 pairs are returned from the sequence:
 [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 Example 2:
 Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
 
 Return: [1,1],[1,1]
 
 The first 2 pairs are returned from the sequence:
 [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 Example 3:
 Given nums1 = [1,2], nums2 = [3],  k = 3
 
 Return: [1,3],[2,3]
 
 All possible pairs are returned from the sequence:
 [1,3],[2,3]
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
using namespace std;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        if (nums1.empty() || nums2.empty()) {
            return result;
        }
        
        auto comp = [](pair<int, int>& a, pair<int, int>& b) {
            return a.first + a.second > b.first + b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);
        
        for (int num1 : nums1) {
            for (int num2 : nums2) {
                minHeap.push(make_pair(num1, num2));
            }
        }
        
        while (!minHeap.empty() && result.size() < k) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        return result;
    }
};