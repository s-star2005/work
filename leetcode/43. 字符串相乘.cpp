#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0]=='0'||num2[0]=='0')
        {
            return "0";
        }
        int ans[500]={0};
        int len1=num1.size(),len2=num2.size();
        for(int i=0;i<len2;i++)
        {
            int a=num2[len2-i-1]-'0';
            for(int j=0;j<len1;j++)
            {
                int b=num1[len1-j-1]-'0';
                int t=a*b;
                ans[j+i]+=t%10;
                int p=j+i;
                while(ans[p]>=10)
                {
                    ans[p+1]+=ans[p]/10;
                    ans[p]=ans[p]%10;
                    p++;
                }
                ans[j+i+1]+=t/10;
                p=j+i+1;
                while(ans[p]>=10)
                {
                    ans[p+1]+=ans[p]/10;
                    ans[p]=ans[p]%10;
                    p++;
                }
            }
        }
        string sum;
        int i=499;
        for(;i>=0;i--)
        {
            if(ans[i]!=0)
            break;
        }
        for(;i>=0;i--)
        {
            sum+=(char)(ans[i]+'0');
        }
        return sum;
    }
};
int main()
{
    string a,b;
    cin>>a>>b;
    Solution t;
    cout<<t.multiply(a,b);
}