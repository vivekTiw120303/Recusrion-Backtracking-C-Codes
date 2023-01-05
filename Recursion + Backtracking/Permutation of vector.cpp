#include<bits/stdc++.h>
using namespace std;

class Solution1 // take or not take
{
    private:
        void permutehelp1(vector<int>&v,vector<int>&ds,map<int,int>mp,vector<vector<int>>&ans)
        {
            if(ds.size()==v.size())
            {
                ans.push_back(ds);
                return;
            }
            for(int i=0;i<v.size();i++)
            {
                if(!mp[v[i]])
                {
                    ds.push_back(v[i]);
                    mp[v[i]]=1;
                    permutehelp1(v,ds,mp,ans);
                    mp[v[i]]=0;
                    ds.pop_back();
                }
            }
        }
    public:
        vector<vector<int>>permute1(vector<int>&v)
        {
            vector<int>ds;
            vector<vector<int>>ans;
            map<int,int>mp;
            for(int i=0;i<v.size();i++)
            {
                mp[v[i]]=0;
            }
            permutehelp1(v,ds,mp,ans);
            return ans;
        }
};

class Solution2 //swap neighbours
{
    private:
        void permutehelp2(int ind,vector<int>&v,vector<vector<int>>&ans)
        {
            if(ind==v.size())
            {
                ans.push_back(v);
                return;
            }
            for(int i=ind;i<v.size();i++)
            {
                swap(v[ind],v[i]);
                permutehelp2(ind+1,v,ans);
                swap(v[ind],v[i]);
            }
        }
    public:
        vector<vector<int>>permute2(vector<int>&v)
        {
            vector<vector<int>>ans;
            permutehelp2(0,v,ans);
            return ans;
        }
};

int main()
{
    vector<int>v={1,2,3};
    Solution1 s1;
    vector<vector<int>>ans1=s1.permute1(v);
    for(auto i=0;i<ans1.size();i++)
    {
        for(auto x:ans1[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    Solution2 s2;
    vector<vector<int>>ans2=s2.permute2(v);
    for(auto i=0;i<ans2.size();i++)
    {
        for(auto x:ans2[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}