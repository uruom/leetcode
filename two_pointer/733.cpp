class Solution {
public:
    bool flag[52][52];
    void dfs(int sr,int sc,int m,int n,vector<vector<int>>& image,int newColor)
    {
        flag[sr][sc]=false;
        if(sr>0&&image[sr][sc]==image[sr-1][sc]&&flag[sr-1][sc]) dfs(sr-1,sc,m,n,image,newColor);
        if(sc>0&&image[sr][sc]==image[sr][sc-1]&&flag[sr][sc-1]) dfs(sr,sc-1,m,n,image,newColor);
        if(sr<m&&image[sr][sc]==image[sr+1][sc]&&flag[sr+1][sc]) dfs(sr+1,sc,m,n,image,newColor);
        if(sc<n&&image[sr][sc]==image[sr][sc+1]&&flag[sr][sc+1]) dfs(sr,sc+1,m,n,image,newColor);
        image[sr][sc]=newColor;
    } 
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size()-1;
        int n=image[0].size()-1;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
            flag[i][j]=true;
        flag[sr][sc]=false;
        if(sr>0&&image[sr][sc]==image[sr-1][sc]&&flag[sr-1][sc]) dfs(sr-1,sc,m,n,image,newColor);
        if(sc>0&&image[sr][sc]==image[sr][sc-1]&&flag[sr][sc-1]) dfs(sr,sc-1,m,n,image,newColor);
        if(sr<m&&image[sr][sc]==image[sr+1][sc]&&flag[sr+1][sc]) dfs(sr+1,sc,m,n,image,newColor);
        if(sc<n&&image[sr][sc]==image[sr][sc+1]&&flag[sr][sc+1]) dfs(sr,sc+1,m,n,image,newColor);
        image[sr][sc]=newColor;
    //    cout<<n<<"   "<<m<<endl;
        return image;
    }
};
