class Solution {
public:
    int smin(int a,int b)
    {
        if(a>b) return b;
        else return a;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size()-1;
        if(n==0) return triangle[0][0];
        int ans[n+2];
        for(int i=n;i>=0;i--)
        ans[i]=triangle[n][i];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                ans[j]=smin(ans[j],ans[j+1])+triangle[i][j];
            }
        }
        return ans[0];
    }
};
