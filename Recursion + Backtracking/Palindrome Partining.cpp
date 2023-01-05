#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        bool isPalin(string s,int start,int end)
        {
            while(start<=end)
            {
                if(s[start++]!=s[end--])
                {
                    return false;
                }
            }
            return true;
        }
        void helper(int ind,string s,vector<string>path,vector<vector<string>>&ans)
        {
            if(ind==s.size())
            {
                ans.push_back(path);
                return;
            }
            for(int i=ind;i<s.size();i++)
            {
                if(isPalin(s,ind,i))
                {
                    path.push_back(s.substr(ind,i-ind+1));
                    helper(i+1,s,path,ans);
                    path.pop_back();
                }
            }
        }
        vector<vector<string>>PaliPart(string s)
        {
            vector<vector<string>>ans;
            vector<string>path;
            helper(0,s,path,ans);
            return ans;
        }
};

int main()
{
    string s="abc";
    Solution s1;
    vector<vector<string>>ans=s1.PaliPart(s);
    for(auto i=0;i<ans.size();i++)
    {
        for(auto j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}