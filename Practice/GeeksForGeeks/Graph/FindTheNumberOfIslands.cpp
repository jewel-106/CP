
/// Find The Number of Island in cpp...
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution
{
    public:
        vector<int> dx = {-1,0, 1,0,1,-1,-1, 1};
        vector<int> dy = {0, -1,0,1,1, 1,-1,-1,};
        bool isvalid(int x,int y, int n, int m)
        {
            return (x >= 0 && x<n && y >= 0 && y<m);
        }
        int numIsLands(vector<vector<char>>& grid)
        {
            // code here
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<bool>> vis(n, vector<bool> (m,false));
            queue<pair<int,int>> q;
            int ans = 0;
            for(int i = 0; i<n; i++)
            {
                for(int j = 0; j<m; j++)
                {
                    if(!vis[i][j] && grid[i][j] == '1')
                    {
                        ans++;
                        vis[i][j] = true;
                        q.push({i,j});
                        while(!q.empty())
                        {
                            int x = q.front().first;
                            int y = q.front().second;
                            q.pop();

                            for(int k = 0 ; k<8;k++)
                            {
                                if(isvalid(x+dx[k],y+dy[k],n,m) && !vis[x+dx[k]][y+dy[k]] && grid[x+dx[k]][y+dy[k]] == '1')
                                {
                                    q.push({x+dx[k], y + dy[k]});
                                    vis[x+dx[k]][y+dy[k]] = true;
                                }
                            }
                        }
                    }
                }
            }
            return ans;

        }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<char>> grid(n,vector<char>(m,'#'));
        for(int i = 0; i<n;i++)
        {
            for(int j = 0; j<m;j++)
            {
                cin>>grid[i][j];
            }
        }

        Solution obj;
        int ans  = obj.numIsLands(grid);
        cout<<ans<<'\n';
    }
    return 0;
}

