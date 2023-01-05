#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int factorial(int n)
        {
            int f=1;
            for(int i=2;i<n;i++)
            {
                f*=i;
            }
            return f;
        }
        string kthPermute(int n,int k)
        {
            vector<int>v;
            for(int i=1;i<=n;i++)
            {
                v.push_back(i);
            }
            int fact=factorial(n);
            k--;
            string ans="";
            while(1)
            {
                ans+=to_string(v[k/fact]);
                v.erase(v.begin()+k/fact);
                if(v.size()==0)
                {
                    return ans;
                }
                k=k%fact;
                fact=fact/v.size();
            }
        }
};

int main()
{
    int n=3,k=4;
    Solution s;
    string ans=s.kthPermute(n,k);
    cout<<ans;
    return 0;
} 