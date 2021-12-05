class Solution {
public:
    int smax(int a,int b)
    {
        if(a>b) return a;
        else return b;
    } 
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        int ans[n+1][2];//0表示不选，1表示选
        if(n==0) return nums[0];
        ans[0][0]=0;
        ans[0][1]=nums[0];
        if(n==1)
        return smax(nums[0],nums[1]);
        ans[1][0]=nums[1];
        ans[1][1]=nums[0];
        for(int i=2;i<=n;i++)
        {
            ans[i][0]=smax(smax(ans[i-1][0],ans[i-1][1]),ans[i-2][1]);
            ans[i][1]=nums[i]+smax(ans[i-2][1],ans[i-2][0]);
        }
        return smax(ans[n][0],ans[n][1]);
    }
};
