#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
vector<vector<pair<int,int>>>ans(101);
int main(){
    for(int i=1;i<=100;i++){
        int ii=i;
        for(int j=2; j*j <= ii; j++){
            while(ii%j == 0){
                ii /= j; mp[j]++;
            }
        }
        if(ii >= 2) mp[ii]++;
        
        for(auto a : mp) ans[i].push_back({a.first,a.second});
    }
    // cout<<" hello ";
    int t; cin>>t;
    for(int i=1; i <= t; i++){
        int n; cin>>n;
        cout<<"Case "<<i<<": "<<n<<" = ";
        cout<<ans[n][0].first<<" ("<<ans[n][0].second<<")";
        for(int j=1; j<ans[n].size(); j++)
            cout<<" * "<<ans[n][j].first<<" ("<<ans[n][j].second<<")";
        cout<<endl;
    }
    
    return 0;
}