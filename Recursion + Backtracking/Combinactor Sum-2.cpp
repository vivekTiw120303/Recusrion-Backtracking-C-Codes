#include<bits/stdc++.h>
using namespace std;

// No Repeating of elements in answer

class Solution
{
    private:
        void findCombinations(int ind,int target,vector<int>&v,vector<int>&ds,vector<vector<int>>&ans)
        {
            // Base Case
            if(target==0)
            {
                ans.push_back(ds);
                return;
            }
            for(int i=ind;i<v.size();i++)
            {
                if(i>ind && v[i]==v[i-1])
                {
                    continue;
                }
                if(v[i]>target)
                {
                    break;
                }
                ds.push_back(v[i]);
                findCombinations(i+1,target-v[i],v,ds,ans);
                ds.pop_back();
            }
        }
    public:
        vector<vector<int>>Combinations2(vector<int>&v,int target)
        {
            sort(v.begin(),v.end());
            vector<vector<int>>ans;
            vector<int>ds;
            int ind=0;
            findCombinations(ind,target,v,ds,ans);
            return ans;
        }
};

int main()
{
    vector<int>v={1,2,2,3,3,3,3,3};
    Solution d;
    vector<vector<int>>ans=d.Combinations2(v,9);
    for(auto i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}