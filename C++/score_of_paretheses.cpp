/*
 Given a balanced parentheses string S, compute the score of the string based on the following rule:
 
 () has score 1
 AB has score A + B, where A and B are balanced parentheses strings.
 (A) has score 2 * A, where A is a balanced parentheses string.
 
 
 Example 1:
 
 Input: "()"
 Output: 1
 Example 2:
 
 Input: "(())"
 Output: 2
 Example 3:
 
 Input: "()()"
 Output: 2
 Example 4:
 
 Input: "(()(()))"
 Output: 6
 
 
 Note:
 
 S is a balanced parentheses string, containing only ( and ).
 2 <= S.length <= 50
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
    int scoreOfParentheses(string S) {
        int sum = 0;
        int depth = 0;
        for (int i = 0; i < S.size(); i++) {
            depth += S[i] == '(' ? 1 : -1;
            if (S[i] == ')' && S[i - 1] == '(') {
                sum += (1 << depth);
            }
        }
        return sum;
    }
};