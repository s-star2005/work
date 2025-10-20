#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int n=s.size();
        map<char,bool> vis;
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[s[i]])
            {
                ans=max(ans,cnt);
                while(cnt>0&&s[i-cnt]!=s[i])
                {
                    vis[s[i-cnt]]=false;
                    cnt--;
                }
            }
            else
            {
                cnt++;
                vis[s[i]]=true;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};