#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1])//若当前的和上一个是一样的，则上一次包含这一次的所有情况，因此这一次可以跳过。
            {
                continue;
            }
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1])//同上
                {
                    continue;
                }
                long cha=(long)target-nums[i]-nums[j];
                int l=j+1,r=n-1;
                while(l<r)
                {
                    if(nums[l]+nums[r]<cha)
                    {
                        l++;
                    }
                    else if(nums[l]+nums[r]>cha)
                    {
                        r--;
                    }
                    else
                    {
                        vector<int> t(4);
                        t[0]=nums[i],t[1]=nums[j],t[2]=nums[l],t[3]=nums[r];
                        l++;
                        while(l<n-1&&nums[l]==nums[l-1])
                        {
                            l++;
                        }
                        r--;
                        while(r>l&&nums[r]==nums[r+1])
                        {
                            r--;
                        }
                        ans.push_back(t);
                    }
                }
            }
        }
        return ans;
    }
};