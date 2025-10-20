#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        long long p=1;
        long long maxn=(p<<31)-1;
        int pd=0;
        long long ans=0;
        int fu=0;
        while(i<n)
        {
            if(s[i]==' ')
            {
                if(pd)
                break;
            }
            else if(s[i]=='-')
            {
                if(pd)
                break;
                pd=1;
                fu=1;
            }
            else if(s[i]=='+')
            {
                if(pd)
                break;
                pd=1;
            }
            else if(s[i]>='0'&&s[i]<='9')
            {
                ans=ans*10+s[i]-'0';
                if(ans>=maxn+1)
                {
                    break;
                }
                pd=1;
            }
            else
            {
                break;
            }
            i++;
        }
        if(fu)
        {
            ans=-ans;
        }
        if(ans>=maxn)
        ans=maxn;
        else if(ans<=-maxn-1)
        ans=-maxn-1;
        return ans;
    }
};