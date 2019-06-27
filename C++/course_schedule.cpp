/*
207. Course Schedule
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> depent;
        unordered_map<int, unordered_set<int>> pre;
        for (vector<int>& prerequisite : prerequisites) {
            depent[prerequisite[0]].insert(prerequisite[1]);
            pre[prerequisite[1]].insert(prerequisite[0]);
        }

        queue<int> order;
        for (int i = 0; i < numCourses; i++) {
            if (depent.find(i) == depent.end() || depent[i].empty()) {
                order.push(i);

            }
        }

        vector<int> result;
        while (!order.empty()) {
            int course = order.front();
            result.push_back(course);
            order.pop();

            for (int nextCourse : pre[course]) {
                depent[nextCourse].erase(course);
                if (depent[nextCourse].empty()) {
                    order.push(nextCourse);
                }
            }
        }
        return result.size() == numCourses;
    }
};
