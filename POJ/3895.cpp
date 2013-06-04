#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define REP(i,n) for(int i=0;i<(int)n;i++) 
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++) 
#define ALL(c) (c).begin(),(c).end() 

const int MAXN = 5000;
vector<int> graph[MAXN];
int depth[MAXN];

int ans;
void dfs(int v, int parent, int d) {
  depth[v] = d;
  int sz = graph[v].size();
  REP(i, sz) {
    int u = graph[v][i];
    if(u!=parent) {
      if(depth[u]==-1) 
	dfs(u,v,d+1);
      else ans = max(ans , depth[v] - depth[u]+1);
      
    }
  }
  
}

void solve() {
  ans = 0;
  REP(i,MAXN) {
    graph[i].clear();
    depth[i] = -1;
    
  } 
  int n,m;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    int p,q;
    scanf("%d%d",&p,&q);
    p--;q--;
    graph[p].push_back(q);
    graph[q].push_back(p);
  }
  dfs(0,-1,0);
  cout<<ans<<endl;
  
}
 

int main() {
  int t;
  cin>>t;
  REP(i,t)
    solve();
  
  return 0;
}
