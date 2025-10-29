#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n=words.size();
        int m=words[0].size();
        int ls=s.size();
        map<string,int> need;
        for(int i=0;i<n;i++)
        {
            ++need[words[i]];
        }
        if(ls<m*n)
        {
            return ans;
        }
        map<string,int> vis;
        for(int i=0;i<m;i++)//遍历偏移量，使所有偏移情况均被考虑到
        {
            for(int j=0;j<n;j++)
            {
                ++vis[s.substr(i+j*m,m)];
            }
            int pd=0;
            for(auto i:need)
            {
                if(vis[i.first]!=need[i.first])
                {
                    pd=1;
                    break;
                }
            }
            if(!pd)
            {
                ans.push_back(i);
            }
            if(--vis[s.substr(i,m)]==0)
            {
                vis.erase(s.substr(i,m));
            }
            for(int j=1;i+(j+n)*m<=ls;j++)
            {
                ++vis[s.substr(i+(j+n-1)*m,m)];
                pd=0;
                for(auto i:need)
                {
                    if(vis[i.first]!=need[i.first])
                    {
                        pd=1;
                        break;
                    }
                }
                if(!pd)
                {
                    ans.push_back(i+j*m);
                }
                if(--vis[s.substr(i+j*m,m)]==0)
                {
                    vis.erase(s.substr(i+j*m,m));
                }
            }
            vis.clear();
        }
        return ans;
    }
};
int main()
{
    Solution a;
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> t;
    for(int i=0;i<n;i++)
    {
        string p;
        cin>>p;
        t.push_back(p);
    }
    a.findSubstring(s,t);
}