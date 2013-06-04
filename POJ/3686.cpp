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
typedef pair<LL,int> PII;
#define MP make_pair
#define REP(i,n) for(int i=0;i<(int)n;i++) 
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++) 
#define ALL(c) (c).begin(),(c).end() 



#define MAX_V 3000
LL INF = (LL)1e7;
int V;//頂点数

struct edge { int to, cap, cost, rev; };


vector<edge> G[MAX_V];
LL h[MAX_V];
LL dist[MAX_V];
int prevv[MAX_V];
int preve[MAX_V];

void add_edge(int from, int to, int cap, int cost ) {
  
  G[from].push_back( (edge){to, cap, cost, G[to].size()}  );
  G[to].push_back( (edge){from, 0, -cost, G[from].size()-1} );
}


int min_cost_flow(int s, int t, int f){
  
  int res = 0;
  fill( h, h+V, 0 );
  
  while( f>0 ) {
    //    cout<<f<<endl;
    priority_queue<PII ,vector<PII>, greater<PII> > que;
    
    fill(dist, dist+V, INF);
    dist[s] = 0;
    que.push( PII( 0 , s ) ) ;
    while( !que.empty() ){
      PII p = que.top();
      que.pop();
      
      int v = p.second;
      if( dist[v]<p.first )continue;
      for(int i=0; i<G[v].size(); i++) {
	edge &e = G[v][i];
	if( e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to] ){
	  dist[e.to] = dist[v] + (LL)e.cost + h[v] -h[e.to];
	  prevv[e.to] = v;
	  preve[e.to] = i;
	  que.push( PII( dist[e.to], e.to ) );
	}
      }
    }
    
    if(dist[t] == INF) { 
      return -1;
    }
    
    for(int v=0; v<V; v++) h[v] += dist[v];
    
    int d = f;
    for(int v = t; v!=s; v=prevv[v]){
      d = min( d, G[prevv[v]][preve[v]].cap );
    }
    
    f -= d;
    res += d*h[t];
    for(int v=t; v!=s; v=prevv[v]) { 
      edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }
  
  return res;
}


//最初にV(頂点数)を設定しないと無限ループに陥るので注意。
//あと、最初からcout埋め込んでいるので消しておきましょう
//繰り返すときにはG[a]の初期化を忘れないこと
//多重辺があるときには死んでしまうので、適切に処理せよ

//ここまでコピペ推奨

int input[55][55];

void solve() {
  REP(i,MAX_V)
    G[i].clear();
  
  int N,M;
  cin>>N>>M;
  REP(i,N) REP(j,M) scanf("%d",&input[i][j]);
  
  // 0..N-1 : omotya
  // N..    : 1工場
  
  int s = N*(M+1);
  int t = s+1;
  V = t+1;
  
  for(int i=0; i<N; i++) {
    add_edge(s,i,1,0);
  }
  
  for(int i=0; i<M; i++) {
    for(int j=0; j<N; j++) {
      int v = (i+1)*N+j;
      add_edge(v,t,1,0);
      for(int k=0; k<N; k++) {
	add_edge(k, v, 1, (j+1) * input[k][i]  );
	
      }
      
    }
  }
  double ans = (double) min_cost_flow(s,t,N);
  
  ans /= (double)N;
  //  cout<<ans<<endl;
  printf("%.6f\n",ans);
}


int main() {
  int t;
  cin>>t;
  REP(i,t) {
    solve();
  }
  return 0;
}
