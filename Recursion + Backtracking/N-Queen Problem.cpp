#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
        // Fucntion to check whether queen is safe at row and col.
        bool isSafe(int row,int col,vector<string>board,int n)
        {
            int r=row,c=col;
            // Upper left diagonal
            while(r>=0 && c>=0)
            {
                if(board[r][c]=='Q')
                {
                    return false;
                }
                r--;
                c--;
            }
            r=row;
            c=col;
            // Left columns
            while(c>=0)
            {
                if(board[row][c]=='Q')
                {
                    return false;
                }
                c--;
            }
            // Lower Left Diagonal
            r=row;
            c=col;
            while(r<n && c>=0)
            {
                if(board[r][c]=='Q') 
                {
                    return false;
                }
                r++;
                c--;
            }
            // If passes all cases
            return true;
        }
    public:
        // FUnction to compute board.
        void compute(vector<string>&board,int n,int col,vector<vector<string>>&ans)
        {
            if(col==n)
            {
                ans.push_back(board);
                return;
            }
            for(int row=0;row<n;row++)
            {
                if(isSafe(row,col,board,n))
                {
                    board[row][col]='Q';
                    compute(board,n,col+1,ans);
                    board[row][col]='.';
                }
            }
        }
        // Main Function 
        vector<vector<string>>NQueen(int n)
        {
            vector<vector<string>>ans;
            vector<string>board(n);
            string s(n,'.');
            for(int i=0;i<n;i++)
            {
                board[i]=s;
            }
            compute(board,n,0,ans);
            return ans;
        }
};

// The above can be optimised using hashing
// We can check left row : leftRow[n,0], by having n size array. Check whether leftRow[i]==0
// For left upper diagonal, simply create a array of size(2*n -1). And check whether LeftUpper[(n-1)+col-row]=0.
// For left lower diagonal, simply create a array of size(2*n -1). And check whether LeftLower[col+row]=0.
// Simply

class SolutionOptimised
{
    public:
        void computeOpti(vector<string>&board,int n,int col,vector<int>&leftCol,vector<int>&leftLower,vector<int>&leftUpper,vector<vector<string>>&ans)
        {
            if(col==n)
            {
                ans.push_back(board);
                return;
            }
            for(int row=0;row<n;row++)
            {
                if(leftCol[row]==0 && leftLower[row+col]==0 && leftUpper[(n-1)+(col-row)]==0)
                {
                    board[row][col]='Q';
                    leftCol[row]=1;
                    leftLower[row+col]=1;
                    leftUpper[(n-1)+(col-row)]=1;
                    computeOpti(board,n,col+1,leftCol,leftLower,leftUpper,ans);
                    board[row][col]='.';
                    leftCol[row]=0;
                    leftLower[row+col]=0;
                    leftUpper[(n-1)+(col-row)]=0;
                }
            }
        }
    public:
        vector<vector<string>>NQueenOptimised(int n)
        {
            vector<vector<string>>ans;
            vector<string>board(n);
            string s(n,'.');
            for(int i=0;i<n;i++)
            {
                board[i]=s;
            }
            vector<int>leftCol(n,0),leftUpper(2*n-1,0),leftLower(2*n-1,0);
            computeOpti(board,n,0,leftCol,leftLower,leftUpper,ans);
            return ans;
        }
};

int main()
{
    int n=4;
    /*Solution s;
    vector<vector<string>>ans=s.NQueen(n);
    for(auto i=0;i<n;i++)
    {
        for(auto x:ans[i])
        {
            cout<<x<<endl;
        }
        cout<<endl;
    }*/
    cout<<"\nUsing Optimisation\n"<<endl;
    SolutionOptimised m;
    vector<vector<string>>ans1=m.NQueenOptimised(n);
    for(auto i=0;i<n;i++)
    {
        for(auto x:ans1[i])
        {
            cout<<x<<endl;
        }
        cout<<endl;
    }
    return 0;
}