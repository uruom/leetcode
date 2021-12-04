class Solution {
public: 
    bool flag[52][52];
    int dfs(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
        int ans=1;
        flag[i][j]=false;
        if(i>0)
            if(flag[i-1][j]&&grid[i-1][j])    ans+=dfs(grid,i-1,j,n,m);
        if(j>0)
            if(flag[i][j-1]&&grid[i][j-1])    ans+=dfs(grid,i,j-1,n,m);
        if(i<n)
            if(flag[i+1][j]&&grid[i+1][j])    ans+=dfs(grid,i+1,j,n,m);
        if(j<m)
            if(flag[i][j+1]&&grid[i][j+1])    ans+=dfs(grid,i,j+1,n,m);
        return ans;
        

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size()-1;
        int m=grid[0].size()-1;
        int ans=0;
        for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        flag[i][j]=true;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(grid[i][j]==1&&flag[i][j])
                ans=max(dfs(grid,i,j,n,m),ans);
            }
        }
        return ans;
    }
};
