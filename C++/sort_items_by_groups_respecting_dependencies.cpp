/*
1203. Sort Items by Groups Respecting Dependencies
https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/

There are n items each belonging to zero or one of m groups
where group[i] is the group that the i-th item belongs to
and it's equal to -1 if the i-th item belongs to no group.
The items and the groups are zero indexed.
A group can have no item belonging to it.

Return a sorted list of the items such that:
The items that belong to the same group are next to each other in the sorted list.
There are some relations between these items
where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array
(to the left of the i-th item).
Return any solution if there is more than one solution and return an empty list if there is no solution.

Example 1:
Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
Output: [6,3,4,1,5,2,0,7]

Example 2:
Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
Output: []
Explanation: This is the same as example 1 except that 4 needs to be before 6 in the sorted list.

Constraints:
1 <= m <= n <= 3*10^4
group.length == beforeItems.length == n
-1 <= group[i] <= m-1
0 <= beforeItems[i].length <= n-1
0 <= beforeItems[i][j] <= n-1
i != beforeItems[i][j]
beforeItems[i] does not contain duplicates elements.
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
#include <numeric>
using namespace std;

class Solution {
private:
    unordered_map<int, unordered_set<int>> group2item; //组织架构，没有小组的项目会分配一个唯一的小组
    unordered_map<int, int> groupInNum;       //每个小组的入度
    unordered_map<int, unordered_set<int>> groupDir;   //小组的依赖图
    unordered_map<int, int> itemInNum;       //组内每个成员的入度
    unordered_map<int, unordered_set<int>> itemDir;    //组内的依赖图
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

    }
};