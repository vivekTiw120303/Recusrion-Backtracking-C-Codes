#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
        void SubsetSumhelp(int ind,int sum,vector<int>&v,vector<int>&ans)
        {
            if(ind==(int)v.size())
            {
                ans.push_back(sum);
                return;
            }
            // if element is taken.
            SubsetSumhelp(ind+1,sum+v[ind],v,ans);
            // If element is not taken.
            SubsetSumhelp(ind+1,sum,v,ans);
        }
    public:
        vector<int>SubsetSum(vector<int>&v)
        {
            vector<int>ans;
            int sum=0;
            SubsetSumhelp(0,sum,v,ans);
            return ans;
        }
};

int main()
{
    vector<int>v={1,1,1,1};
    Solution s;
    vector<int>ans=s.SubsetSum(v);
    sort(ans.begin(),ans.end());
    for(auto &i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}