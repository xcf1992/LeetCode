/*
436. Find Right Interval
Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.

For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.

Note:

You may assume the interval's end point is always bigger than its start point.
You may assume none of these intervals have the same start point.
 

Example 1:

Input: [ [1,2] ]

Output: [-1]

Explanation: There is only one interval in the collection, so it outputs -1.
 

Example 2:

Input: [ [3,4], [2,3], [1,2] ]

Output: [-1, 0, 1]

Explanation: There is no satisfied "right" interval for [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point;
For [1,2], the interval [2,3] has minimum-"right" start point.
 

Example 3:

Input: [ [1,4], [2,3], [3,4] ]

Output: [-1, 2, -1]

Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.


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

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> cache;
        for (int i = 0; i < intervals.size(); i++) {
            cache[intervals[i][0]] = i;
        }

        vector<int> result;
        for (vector<int>& interval : intervals) {
            auto it = cache.lower_bound(interval[1]);
            result.push_back(it == cache.end() ? -1 : it -> second);
        }
        return result;
    }
};

// wrong answer do not know why
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; ++i) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0] or (a[0] == b[0] and a[1] < b[1]);
        });
        
        stack<pair<int, int>> stk;
        vector<int> result(n, -1);
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() and intervals[i][0] >= intervals[stk.top().first][1]) {
                result[stk.top().second] = intervals[i][2];
                stk.pop();
            }
            stk.push({i, intervals[i][2]});
        }
        return result;
    }
};
