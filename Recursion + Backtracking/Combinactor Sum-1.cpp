#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
        void findCOmbinations(int ind,int target,vector<int>&v,vector<int>&ds,vector<vector<int>>&ans)
        {
            // Base Case
            if(ind==v.size())
            {
                if(target==0)
                {
                    ans.push_back(ds);
                }
                return;
            }
            if(target>=v[ind])
            {
                // Take
                ds.push_back(v[ind]);
                findCOmbinations(ind,target-v[ind],v,ds,ans);
                // Not Take
                ds.pop_back();
            }
            findCOmbinations(ind+1,target,v,ds,ans);
        }
    public:
        vector<vector<int>> Combinations1(vector<int>&v,int target)
        {
            vector<vector<int>>ans;
            vector<int>ds;
            int ind=0;
            findCOmbinations(ind,target,v,ds,ans);
            return ans;
        }
};

int main()
{
    vector<int>v={1,2,3};
    Solution s;
    vector<vector<int>>ans=s.Combinations1(v,2);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}