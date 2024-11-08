#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define CC(x) cout << "Case " << ++x << ":";
#define nn "\n"
#define rep(i,a,n) for(int i=a ; i<n ; i++)
const int MOD = 1e9+7, N=1e5+5 ;
#define fast ios_base::sync_with_stdio(false) ; cout.tie(0) ; cin.tie(0) ;

using namespace std;

vector<pair<int,int>>edge[N];
priority_queue<int>cost;
vector<bool>vis;

void dfs(int node, int cnt, int indx){
    vis[node]=1;
    for(auto child : edge[node]){
        if(!vis[child.first]){
            dfs(child.first,cnt+indx*child.second,indx+1);
        }
    }
    if(node != 0 and edge[node].size()==1) cost.push(cnt);
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp=head;
        if(temp == nullptr) return false;

        while(temp->next != nullptr){
            if(temp->next->val == -1000000) return true;
            temp->val = -1000000;
            temp = temp->next;
        }
        return false;
    }
};

void solve(){
    int n;cin>>n;
    int a[n];
    int cnt=0,ans=0;
    
    rep(i,0,n) cin>>a[i], ans += a[i];
    rep(i,0,n-1){
        if(a[i] == a[i+1] and a[i] == -1){
            cnt=2; break;
        }
        else if(a[i] == -1) cnt=1;
    }
	if(cnt == 0 and a[n-1] == -1) cnt = 1;
	
    if(cnt == 0) ans -= 4;
    else if(cnt == 2) ans += 4;
    cout<<ans<<endl;
}

signed main()
{
    fast;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0 ;
}