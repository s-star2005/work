/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        #include<stack>
        map<char,int> xu;
        xu['(']=xu[')']=1;
        xu['[']=xu[']']=2;
        xu['{']=xu['}']=3;
        stack<int> q;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                q.push(s[i]);
            }
            else
            {
                if(q.empty())
                {
                    return false;
                }
                if(xu[q.top()]==xu[s[i]])
                {
                    q.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(!q.empty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
// @lc code=end

