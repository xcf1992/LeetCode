/*
 986. Interval List Intersections

 Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

 Return the intersection of these two interval lists.

 (Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)



 Example 1:



 Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
 Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.


 Note:

 0 <= A.length < 1000
 0 <= B.length < 1000
 0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
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
#include <numeric>
using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> result;
        int m = A.size(), a = 0;
        int n = B.size(), b = 0;
        while (a < m and b < n) {
            int left = max(A[a].start, B[b].start);
            int right = min(A[a].end, B[b].end);
            if (left <= right) {
                result.push_back(Interval(left, right));
            }
            if (A[a].end < B[b].end) {
                a += 1;
            }
            else {
                b += 1;
            }
        }
        return result;
    }
};
