/*
 1053. Previous Permutation With One Swap

 Given an array A of positive integers (not necessarily distinct), return the lexicographically largest permutation that is smaller than A, that can be made with one swap (A swap exchanges the positions of two numbers A[i] and A[j]).  If it cannot be done, then return the same array.
 
 
 
 Example 1:
 
 Input: [3,2,1]
 Output: [3,1,2]
 Explanation:
 Swapping 2 and 1.
 Example 2:
 
 Input: [1,1,5]
 Output: [1,1,5]
 Explanation:
 This is already the smallest permutation.
 Example 3:
 
 Input: [1,9,4,6,7]
 Output: [1,7,4,6,9]
 Explanation:
 Swapping 9 and 7.
 Example 4:
 
 Input: [3,1,1,3]
 Output: [1,1,3,3]
 
 
 Note:
 
 1 <= A.length <= 10000
 1 <= A[i] <= 10000
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
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        if (n <= 1) {
            return A;
        }
        
        int left = n - 2;
        while (left >= 0 and A[left] <= A[left + 1]) {
            left -= 1;
        }
        if (left < 0) {
            return A;
        }
        
        int right = n - 1;
        while (A[left] <= A[right]) {
            right -= 1;
        }
        while (A[right - 1] == A[right]) {
            right -= 1;
        }
        swap(A[left], A[right]);
        return A;
    }
};
