/*
You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.
 
 Write a function to determine if the starting player can guarantee a win.
 
 For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".
 
 Follow up:
 Derive your algorithm's runtime complexity.
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
    bool canWin(string s) {
        unordered_map<string, bool> results;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '+' && s[i - 1] == '+') {
                s[i] = s[i - 1] = '-';
                bool result = false;
                if (results.find(s) == results.end()) {
                    result = canWin(s);
                    results[s] = result;
                }
                else {
                    result = results[s];
                }
                s[i] = s[i - 1] = '+';
                if (!result) {
                    return true;
                }
            }
        }
        return false;
    }
};
class Solution1 {
private:
    bool canFlip(string s) {
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '+' && s[i - 1] == '+') {
                return true;
            }
        }
        return false;
    }
public:
    bool canWin(string s) {
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '+' && s[i - 1] == '+') {
                s[i] = s[i - 1] = '-';
                if (!canFlip(s)) {
                    return true;
                }
                if (!canWin(s)) {
                    return true;
                }
                s[i] = s[i - 1] = '+';
            }
        }
        return false;
    }
};