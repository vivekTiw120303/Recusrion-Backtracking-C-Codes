#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
        void SubsetSumhelp(int ind,int sum,vector<int>&v,set<int>&ans)
        {
            if(ind==(int)v.size())
            {
                ans.insert(sum);
                return;
            }
            // if element is taken.
            SubsetSumhelp(ind+1,sum+v[ind],v,ans);
            // If element is not taken.
            SubsetSumhelp(ind+1,sum,v,ans);
        }
    public:
        set<int>SubsetSum(vector<int>&v)
        {
            set<int>ans;
            int sum=0;
            SubsetSumhelp(0,sum,v,ans);
            return ans;
        }
};

int main()
{
    vector<int>v={1,1,1,1};
    Solution s;
    set<int>ans=s.SubsetSum(v);
    for(auto &i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}