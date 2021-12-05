class Solution {
public:
    int climbStairs(int n) {
        int ans[n+1];
        ans[0]=1;
        ans[1]=1;
        if(n==0)
        return 0;
        else if(n==1) return 1;
             else {
                 for(int i=2;i<=n;i++)
                 ans[i]=ans[i-1]+ans[i-2];
                 return ans[n];
             }
        
    }
};
