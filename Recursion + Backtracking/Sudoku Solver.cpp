#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        // Fucntion to check if given character be placed in the given row col.
        bool isValid(vector<vector<char>>&board,int row,int col,char a)
        {
            for(int i=0;i<9;i++)
            {
                // Same column
                if(board[i][col]==a)
                {
                    return false;
                }
                // Same row
                if(board[row][i]==a)
                {
                    return false;
                }
                // Same sub-square
                if(board[3*(row/3)+i/3][3*(col/3)+i%3]==a)
                {
                    return false;
                }
            }
            // If follow all condition, return true
            return true;
        }
        // Solve the sudoku
        bool solveSudoku(vector<vector<char>>&board)
        {
            for(int i=0;i<board.size();i++)
            {
                for(int j=0;j<board[0].size();j++)
                {
                    if(board[i][j]=='.')
                    {
                        for(char a='1';a<='9';a++)
                        {
                            if(isValid(board,i,j,a))
                            {
                                board[i][j]=a;
                                if(solveSudoku(board)==true)
                                {
                                    return true;
                                }
                                else
                                {
                                    board[i][j]='.';
                                }
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }
        // Return the board.
        void SudokuSolution(vector<vector<char>>&board)
        {
            solveSudoku(board);
        }
};

int main()
{
    vector<vector<char>>board{
        {'.', '1', '9', '.', '.', '.', '7', '6', '8'},
        {'.', '2', '5', '8', '6', '.', '3', '.', '4'},
        {'.', '.', '6', '.', '.', '9', '1', '.', '.'},
        {'9', '4', '2', '6', '.', '7', '.', '8', '.'},
        {'3', '.', '1', '9', '4', '8', '6', '.', '2'},
        {'.', '7', '.', '2', '.', '5', '9', '.', '1'},
        {'2', '6', '.', '1', '8', '3', '4', '5', '9'},
        {'1', '8', '.', '.', '9', '6', '2', '.', '7'},
        {'.', '9', '3', '7', '.', '4', '.', '.', '.'}
    };
    Solution s;
    s.SudokuSolution(board);
    cout<<"The Solved sudoku is :"<<endl;
    for(auto i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}