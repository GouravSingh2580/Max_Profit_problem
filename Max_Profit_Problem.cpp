#include <bits/stdc++.h>
using namespace std;
#define int long long

int val[3]={1500, 1000, 3000};
int wt[3]={5, 4, 10};

int knapSack(int &W, int wt[], int val[], int n)
{
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++) {
        for (int w = W; w >= 0; w--) {
            if (wt[i - 1] <= w)
                //max value
                dp[w] = max(dp[w],dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W];
}

int32_t main() 
{
    int time_unit;
    cin>>time_unit;
    vector<int>v;
    //map<int,int>mp; mp[knapSack(time_unit, wt,val,3)]++; for futue reference
  
    int ans=knapSack(time_unit, wt,val,3);
    for(auto i:val){
      if(i%ans==0) v.push_back(i/ans);
      else v.push_back(0);
    }
    
    cout<<"T: "<<v[0]<<" P: "<<v[1]<<" C: "<<v[2]<<endl;
}
