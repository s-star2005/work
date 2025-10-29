class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> l(n,0),r(n,0);
        l[0]=height[0];
        for(int i=1;i<n;i++)
        {
            l[i]=max(height[i],l[i-1]);
        }
        r[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            r[i]=max(height[i],r[i+1]);
        }
        long long ans=0;
        for(int i=1;i<n-1;i++)
        {
            ans+=max(min(l[i-1],r[i+1])-height[i],0);
        }
        return ans;
    }
};