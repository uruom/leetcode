class Solution {
public:
    struct S_Line
    {
        int x;
        int y;
    };
    int smax(int a,int b)
    {
        if(a>b) return a;
        else return b;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size()-1;
        int m=grid[0].size()-1;
        struct S_Line line[10004];
        int l=0,r=0,al=(n+1)*(m+1);
        vector<vector<int>> dis (n+1);
        for(int i=0;i<=n;i++)
        dis[i].resize(m+1);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(grid[i][j]==0)
                {
                    l++;
                    r++;
                }
            }
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(grid[i][j]==2)
                {
                    dis[i][j]=0;
                    r++;
                    line[r].x=i;
                    line[r].y=j;
                //    cout<<i<<" "<<j<<endl;
                }
                else
                if(grid[i][j]==1)
                dis[i][j]=-1; 
            }
        }
        while(r<al&&l<r)
        {
            l++;
            if(line[l].x>0&&dis[line[l].x-1][line[l].y]==-1)
            {
                dis[line[l].x-1][line[l].y]=dis[line[l].x][line[l].y]+1;
                r++;
                line[r].x=line[l].x-1;
                line[r].y=line[l].y;
            }
            if(line[l].x<n&&dis[line[l].x+1][line[l].y]==-1)
            {
                dis[line[l].x+1][line[l].y]=dis[line[l].x][line[l].y]+1;
                r++;
                line[r].x=line[l].x+1;
                line[r].y=line[l].y;
            }
            if(line[l].y>0&&dis[line[l].x][line[l].y-1]==-1)
            {
                dis[line[l].x][line[l].y-1]=dis[line[l].x][line[l].y]+1;
                r++;
                line[r].x=line[l].x;
                line[r].y=line[l].y-1;
            }
            if(line[l].y<m&&dis[line[l].x][line[l].y+1]==-1)
            {
                dis[line[l].x][line[l].y+1]=dis[line[l].x][line[l].y]+1;
                r++;
                line[r].x=line[l].x;
                line[r].y=line[l].y+1;
            }
        }
 //       cout<<r<<" "<<line[r].x<<" "<<line[r].y<<endl;
        if(r==al)
        return smax(dis[line[r].x][line[r].y],0);//特殊点[[0]]
        else return -1;
    }
};
