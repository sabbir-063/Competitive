#include <bits/stdc++.h>
#define in long long
#define du long double
#define rep(i,a,n) for(in i=a ; i<n ; i++)
#define rep2(i,a,n)  for(in i=a ; i*i<=n ; i++)
const in INF = 1e9+7 , MOD = 1e9+7 ;

using namespace std ;

template<typename T> 
T mx(T x , T y){
    if(x>=y) return x ;
    return y ;
}

vector<int> graph[100005] ;
vector<int> dist(100005) , vis(1000005) , parent(1000005) ;
void BFS(int source){
    queue<int> q ;
    q.push(source) ;
    dist[source]=0 ;
    parent[source]=-1 ;
    vis[source]=1 ;

    while (!q.empty())
    {
        int sinior = q.front() ;
        q.pop() ;
        for(auto i=graph[sinior].begin();i<graph[sinior].end();i++){
            if(!vis[*i]){
                vis[*i]=1 ;
                dist[*i]=dist[sinior]+1 ;
                q.push(*i) ;
                parent[*i]=sinior ;
            }
        }
    }
}

void dfs(int node){
    vis[node]=1;
    for(auto it : graph[node]){
        if(!vis[it]){
            dfs(it);
        }
    }
}

const in N=1e5+2;
int tree[4*N], a[N];
 
void build(int node, int st, int en){
    if(st == en){
        tree[node] = a[st];
        return;
    }
 
    int mid = (st + en) >> 1;
	int left=node << 1;
	int right=(node << 1) + 1;
    build(left, st, mid);
    build(right, mid+1, en);
 
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

int query(int node, int st, int en, int l, int r){
    if(en < l || st > r){
        return MOD;
    }
 
    if(l <= st and en <= r)
        return tree[node];
 
    int mid = (st + en) >> 1;
	int left=node << 1;
	int right=(node << 1) + 1;

    int q1 = query(left, st, mid, l, r);
    int q2 = query(right, mid+1, en, l, r);
 
    return min(q1, q2);
}
 
void update(int node, int st, int en, int idx, int val){
    if(st == en){
        a[st] = val;
        tree[node] = val;
        return;
    }
 
    int mid = (st + en) >> 1;
	int left=node << 1;
	int right=(node << 1) + 1;

    if(idx <= mid){
        update(left, st, mid, idx, val);
    }
    else{
        update(right, mid+1, en, idx, val);
    }
 
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

/*
void dijkstra(){
    int n , m ;
    cin >> n >> m ;
    vector<vector<pair<int,int>>> e(n) ;
    while(m--){
        int u , v , w ;
        cin >> u >> v >> w ;
        u-- ; v-- ;
        e[u].push_back({v,w}) ;
    }

    vector<bool> done(n,false) ;
    vector<int> dis(n,INF) ;
    dis[0]=0 ;

    while(true){
        int curr=-1 ;
        for(int i=0;i<n;i++){
            if(!done[i] and(curr==-1 or dis[i] < dis[curr])){
                curr=i ;
            }
        }

        if(curr==-1) break ;
        done[curr]=true ;

        for(auto [to,w] : e[curr]){
            dis[to] = min(dis[curr]+w , dis[to]) ;
        }

    }
    for(int i=0;i<n;i++){
        cerr << i+1 << " -> " << dis[i] << endl ;
    }
    cerr << endl ;
}

void dijkstra_set(){
    int n , m ;
    cin >> n >> m ;
    vector<vector<pair<int,int>>> e(n) ;
    while(m--){
        int u , v , w ;
        cin >> u >> v >> w ;
        u-- ; v-- ;
        e[u].push_back({v,w}) ;
    }

    set<pair<int,int>> st ;
    vector<int> d(n,INF) ;
    vector<int>parent(n) ;
    d[0]=0 ;
    parent[0]=-1 ;
    st.insert({0,0}) ;

    while(!st.empty()){
        auto [dist,curr] = *st.begin() ;
        st.erase(st.begin()) ;
        for(auto [to,w] : e[curr]){
            if(d[to] > d[curr]+w){
                st.erase({d[to],to}) ;
                d[to]=d[curr]+w ;
                st.insert({d[to],to}) ;
                parent[to]=curr ;
            }
        }
    }
    for(int i=0;i<n;i++){
        cerr << i+1 << " -> " << d[i] << endl ;
    }
    cerr << endl ;
    /// for path finding
    vector<int> path ;
    int at=n-1 ;
    while(at!=0){
        path.push_back(at) ;
        at=parent[at] ;
    }
    path.push_back(at) ;
    reverse(path.begin(),path.end()) ;
    for(auto i:path) cerr << i+1 << " " ;
    cerr << endl ;
}



void dijkstra_priority_queue(){
    int n , m , s , t ;
    cin >> n >> m >> s >> t ;
    vector<vector<pair<int,int>>> e(n) ;
    while(m--){
        int u , v , w ;
        cin >> u >> v >> w ;
        e[u].push_back({v,w}) ;
        e[v].push_back({u,w}) ;
    }

    priority_queue<pair<int,int>> pq ;
    vector<int> d(n,INF) ;
    vector<int> done(n,false) ;
    d[s]=0 ;
    pq.push({0,s}) ;

    while(!pq.empty()){
        int dist = pq.top().first ;
        int curr = pq.top().second ;
        pq.pop() ; dist=-dist ;

        if(done[curr]) continue ;
        done[curr]=1 ;

        for(auto [to,w] : e[curr]){
            if(d[to] > d[curr]+w){
                d[to]=d[curr]+w ;
                pq.push({-d[to],to}) ;
            }
        }
    }

    if(d[t]==INF) cerr << "unreachable" << endl ;
    else cerr << d[t] << endl ;

}
*/

int dp[10005] ;
int MinSquare(int n){
    //top down approach
    rep(i,0,10005) dp[i]=MOD ;
    if(n<=3) return n ;  
    if(dp[n] != MOD)
        return dp[n] ;
    rep2(i,1,n){
        dp[n]=min(dp[n],1+MinSquare(n-i*i)) ;
    }
    return dp[n] ;  

    // bottom up approach
    // rep(i,0,N+1) dp[i]=MOD ;
    // rep(i,0,4) dp[i]=i ;

    // for(int i=1 ; i*i<=n ; i++){
    //     for(int j=0 ; i*i+j<=n ; j++){
    //         dp[i*i+j]=min(dp[i*i+j],1+dp[j]) ;
    //     }
    // }
    // return dp[n] ;
}


int m[2005][2005] ;
int weight[2005] , prices[2005] ;
void knapsack001(int w , int indx){
    rep(i,1,w+1){
        rep(j,1,indx+1){
            if(i<weight[j])
                m[i][j]=m[i][j-1] ;
            else{
                int notTaken=m[i][j-1] ;
                int taken=prices[j]+m[i-weight[j]][j-1] ;
                m[i][j]=max(notTaken,taken) ;
            }
        }
    }
}



int memo[1005][1005] ;
int LCS(string s1 ,string s2 ,int len1, int len2){

    if (len1 == 0 or len2 == 0) return 0 ;

    if(memo[len1][len2] != -1)
        return memo[len1][len2] ;

    if(s1[len1-1] == s2[len2-1]) 
        return 1+LCS(s1,s2,len1-1,len2-1) ;

    return  memo[len1][len2] = max(LCS(s1,s2,len1-1,len2),LCS(s1,s2,len1,len2-1)) ;

}

int LcsBottomUp(string x , string y , int l1 , int l2){
    rep(i,0,l1+1){
        rep(j,0,l2+1){
            if(i==0 or j==0) memo[i][j]=0 ;
            else if(x[i-1]==y[j-1]){
                memo[i][j]=1+memo[i-1][j-1] ;
            }else{
                memo[i][j]=max(memo[i-1][j],memo[i][j-1]) ;
            }
        }
    }
    return memo[l1][l2] ;
}

string memoS[111][111] ;
void LcsLexoMinStringPrint(string x , string y , int l1 , int l2){
    rep(i,0,l1+1){
        rep(j,0,l2+1){
            if(i==0 or j==0) memoS[i][j]="" ;
            else if(x[i-1]==y[j-1]){
                memoS[i][j]=memoS[i-1][j-1] + x[i-1] ;
            }
            else if(memoS[i-1][j].size() == memoS[i][j-1].size()){
                if(memoS[i-1][j] <= memoS[i][j-1])
                    memoS[i][j] = memoS[i-1][j] ;
                else 
                    memoS[i][j] = memoS[i][j-1] ;
            }
            else if(memoS[i-1][j].size() > memoS[i][j-1].size()){
                memoS[i][j] = memoS[i-1][j] ;
            }
            else{
                memoS[i][j] = memoS[i][j-1] ;
            }
        }
    }
}


in matriX[1005][1005] , spliT[1005][1005] ;
in inputPos[1005] , n;
in MCM(in i , in j){
    if(i == j) return 0 ;
    if(matriX[i][j] != -1) return matriX[i][j] ;

    in ans=INF ;
    in indx=0 ;
    rep(k,i,j){
        in temp = MCM(i,k) + MCM(k+1,j) + inputPos[i-1]*inputPos[k]*inputPos[j] ;
        if(temp < ans){
            ans = temp ;
            indx = k ;
        }
    }
    spliT[i][j] = indx ;
    return matriX[i][j] = ans ;
}

void McmBottomUp(){
    rep(i,1,n) matriX[i][i] = 0;

    rep(l,2,n+1){
        for(in i=1 , j=l ; i < n-l+1 ; j++ , i++){
            in ans = INF ;
            in indx = 0 ;
            rep(k,i,j){
                in temp = matriX[i][k] + matriX[k+1][j] + inputPos[i-1]*inputPos[k]*inputPos[j];
                if(temp < ans){
                    ans = temp ;
                    indx = k ;
                }
            }
            matriX[i][j] = ans ;
            spliT[i][j] = indx ;
        }
    }
}

void patrenthesize(int i , int j , int &count){
    if(i == j){
        cerr << "A" << count++ ;
        return ;
    }

    cerr << "(" ;
    patrenthesize(i , spliT[i][j] , count) ;
    patrenthesize(spliT[i][j]+1 , j , count) ;
    cerr << ")" ;

}

const int N = 1e5+2, MOD = 1e7+2;
int tree[4*N], a[N];
void build(int node, int st, int en){
    if(st == en){
        tree[node] = a[st];
        return;
    }
 
    int mid = (st + en)/2;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
 
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

int query(int node, int st, int en, int l, int r){
    if(en < l || st > r){
        return MOD;
    }
 
    if(l <= st and en <= r)
        return tree[node];
 
    int mid = (st + en)/2;
    int q1 = query(2*node, st, mid, l, r);
    int q2 = query(2*node+1, mid+1, en, l, r);
 
    return min(q1, q2);
}
 
void update(int node, int st, int en, int idx, int val){
    if(st == en){
        a[st] = val;
        tree[node] = val;
        return;
    }
 
    int mid = (st+en)/2;
    if(idx <= mid){
        update(2*node, st, mid, idx, val);
    }
    else{
        update(2*node+1, mid+1, en, idx, val);
    }
 
    tree[node] = max(tree[2*node], tree[2*node+1]);
}

/// @brief Trie er class
class Node{
public:
    int EoW;
    Node *children[26];
    Node(){
        EoW=0;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }

    void Insert(Node *root,string s){
        int n=s.size();
        Node *temp=new Node();
        temp=root;
        for(int i=0;i<n;i++){
            int x=s[i]-'A';
            if(temp->children[x]==NULL) temp->children[x]= new Node();
            temp=temp->children[x];
        }
        temp->EoW++;
    }

    int Search(string s, Node *temp=root, int k=0){
        if(temp == NULL) return 0;
        if(k == s.size()) return temp->EoW;
        return Search(s,temp->children[s[k]-97],k+1);
    }

    bool isLeaf(Node *temp){
        for(int i=0;i<26;i++){
            if(temp->children[i]!=NULL)
                return 0;
        }
        return 1;
    }

    bool isJunction(Node *temp){
        if(temp->EoW>=1) return 1;
        if(isLeaf(temp)) return 0;   ///if the edge is leaf then it is not junction
        return 1;
    }

    void removeEdge(Node *temp,char c,int d){
        if(d==0) return ;  ///don't delete edge
        int x=c-'A';
        Node *toDelete=temp->children[x];
        temp->children[x]=NULL;
        delete toDelete;
    }

    bool Delete(Node *temp,string s,int k){
        if(temp==NULL) return 0;
        if(k==s.size()){
            if(temp->EoW==0) return 0;
            if(isLeaf(temp)==0){      ///Not leaf node
                temp->EoW-=1;         ///simply decreasing EoW by 1
                return 0;             ///No need of edge deletion
            }
            return 1;                 ///if Leaf and Eow>0, then edge deletion is needed =>> so return 1
        }
        int x=s[k]-'A';
        int d=Delete(temp->children[x],s,k+1);
        removeEdge(temp,s[k],d);
        if(isJunction(temp)==1)  d=0;  ///if temp reaches to a junction point,
                                        ///then the deletion of edge is not needed anymore
        return d;
    }

    void printTRIE(Node *cur , string s=""){
        if(cur->EoW>=1){
            cerr<<s<<" "<<cur->EoW<<endl;
        }
        for(int i=0;i<26;i++){
            if(cur->children[i]!=NULL)
            {
                char c=char(i+65);
                printTRIE(cur->children[i],s+c);
            }
        }
    }
    
};
Node *root;

const int nn=10005;
vector<int>parent(nn);

void makeset(){
	for(int i=0;i<nn;i++) 
		parent[i]=i;
}
int findSet(int u){
	int ru=parent[u];
	if(ru == u) return u;
	return parent[u] = findSet(ru);
}
void Union(int u, int v){
	int ru=parent[u]; 
	int rv=parent[v];
	if(ru == rv) return;

	parent[ru]=rv;
}

int pow2(int x, int y){
	if(y==0) return 1;
	int d=pow2(x,y/2);
	if(y&1)
		return x*d*d;
	else
		return d*d;
}

vector<bool>sve(N,true);
void seive(){
	for(int i=2;i*i <= N; i++){
		if(sve[i]){
			for(int j=i*i;j<=N;j+=i)
				sve[j]=0;
		}
	}
}