/*
 *2251.
 *フローチックに問題を帰着させて
 *結局DAGの最小パス被覆になるので
 *二部マッチングで解けるパターンの問題
 *
 *手持ちの最大流ライブラリではMLEが発生したのでおとなしく二部マッチングライブラリを使用。
 */


#include <algorithm>
#include <cmath>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
using namespace std;


typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define REP(i,n) for(int i=0;i<(int)n;i++) 
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++) 
#define ALL(c) (c).begin(),(c).end() 

const int MAX_V = 2010;
int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u , int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}
bool dfs(int v) {
  used[v] = true;
  for(int i=0; i<G[v].size(); i++) {
    int u = G[v][i] , w  =match[u];
    if(w<0 || !used[w] && dfs(w)) {
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  return false;
}

int bipartite_matching() {
  int res = 0;
  //  memset(match , -1,  sizeof(match));
  for(int i=0; i<MAX_V; i++) match[i] = -1;
  for(int v=0; v<V; v++) {
    if(match[v]<0) {
      for(int i=0; i<MAX_V; i++) used[i] = false; 
      //      memest(used,0,sizeof(used));
      if(dfs(v)) res++;
    }
  }
  return res;
}

const int MAXN = 105;

void solve( int n,int m,int l) {
  for(int i=0; i<MAX_V; i++) G[i].clear();
  V = 2*l+2;
  int dist[MAXN][MAXN];
  for(int i=0; i<n; i++) 
    for(int j=0; j<n; j++)
      dist[i][j] = 1000000000;
  for(int i=0; i<n; i++) dist[i][i] = 0;
  for(int i=0; i<m; i++) {
    int p,q,r;
    cin>>p>>q>>r;
    dist[p][q] = r;
    dist[q][p] = r;
  }

  for(int j=0; j<n; j++)
    for(int i=0; i<n; i++)
      for(int k=0; k<n; k++) 
	dist[i][k] = min(dist[i][k] , dist[i][j] + dist[j][k]);

  vector<PII> input;
  for(int i=0; i<l; i++) {
    int  p,q;
    cin>>p>>q;
    input.push_back(MP(q,p));
  }
  sort(input.begin() , input.end());

  int N = l;
  /*  int source = N*2;
  int sink = N*2+1;
  for(int i=0; i<N; i++) {
    add_edge(source , i,1);
    add_edge(N+i,sink,1);
    }*/

  for(int i=0; i<l; i++) for(int j=i+1; j<l; j++){
    int pret = input[i].first;
    int prep = input[i].second;
    int next = input[j].first;
    int nexp = input[j].second;
    if(dist[prep][nexp] <=next-pret) {
      add_edge(i,j+N);
    }
  }
  cout<<N-bipartite_matching()<<endl;


}

int main() {
  while(true) {
    int n,m,l;
    cin>>n>>m>>l;
    if(n==0 && m==0 && l==0) break;
    solve(n,m,l);
  }
  return 0;
}

