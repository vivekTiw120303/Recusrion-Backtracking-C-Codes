#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        void solve(int i,int j,int n,vector<vector<int>>s,vector<vector<int>>vis,string move,vector<string>&ans)
        {
            if(i==n-1 && j==n-1)
            {
                ans.push_back(move);
                return;
            }
            // Downward
            if(i<n-1 && !vis[i+1][j] && s[i+1][j]==1)
            {
                vis[i+1][j]=1;
                solve(i+1,j,n,s,vis,move+'D',ans);
            }
            // Leftward
            if(j>=1 && !vis[i][j+1] && s[i][j+1]==1)
            {
                vis[i][j-1]=1;
                solve(i,j-1,n,s,vis,move+'L',ans);
                vis[i][j-1]=0;
            }
            // Right
            if(j<n-1 && !vis[i][j+1] && s[i][j+1]==1)
            {
                vis[i][j+1]=1;
                solve(i,j+1,n,s,vis,move+'R',ans);
                vis[i][j+1]=0;
            }
            // Upward
            if(i>0 && !vis[i-1][j] && s[i-1][j]==1)
            {
                vis[i-1][j]=1;
                solve(i-1,j,n,s,vis,move+'U',ans);
                vis[i-1][j]=0;
            }
        }
        vector<string>RatMaze(vector<vector<int>>v,int n)
        {
            vector<string>ans;
            vector<vector<int>>vis(n,vector<int>(n,0));
            solve(0,0,n,v,vis,"",ans);
            return ans;
        }
};

int main()
{
    int n=4;
    vector<vector<int>>v={{1,0,0,1},{0,1,1,1},{0,0,0,1},{0,0,0,1}};
    Solution s1;
    vector<string>ans=s1.RatMaze(v,n);
    for(auto i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}