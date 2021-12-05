class Solution {
public:
    struct S_Line
    {
        int x;
        int y;
    };
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size()-1;
        int m=mat[0].size()-1;
        struct S_Line line[10004];
        int l=0,r=0,al=(n+1)*(m+1);
        vector<vector<int>> dis (n+1);
        for(int i=0;i<=n;i++)
        dis[i].resize(m+1);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(mat[i][j]==0)
                {
                    dis[i][j]=0;
                    r++;
                    line[r].x=i;
                    line[r].y=j;
                }
                else
                dis[i][j]=-1; 
            }
        }
        while(r<al)
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
        return dis;

    }
};
