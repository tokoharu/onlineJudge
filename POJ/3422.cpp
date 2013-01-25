
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

#define MAX_V 5010
int INF = (int)1e6;
int V;//頂点数

struct edge { int to, cap, cost, rev; };


vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V];
int preve[MAX_V];

void add_edge(int from, int to, int cap, int cost ) {
	
	G[from].push_back( (edge){to, cap, cost, G[to].size()}  );
	G[to].push_back( (edge){from, 0, -cost, G[from].size()-1} );
}


int min_cost_flow_b(int s, int t, int f){
	
	int res = 0;
	fill( h, h+V, 0 );
	
	while( f>0 ) {
	  //		cout<<f<<endl;
		
		fill(dist, dist+V, INF) ;
		dist[s]=0;
		while(1) {
			bool update=false;
			for(int v=0; v<V; v++) for(int i=0; i<G[v].size(); i++){
				edge &e = G[v][i];
				if(e.cap>0 &&  dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]) {
					dist[e.to] = dist[v] + e.cost+h[v]-h[e.to];
					prevv[e.to] = v;
					preve[e.to] = i;
					update=true;
				}
			}
			if(!update) break;
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
//最初にV(頂点数)を設定しないと無限ループに陥るので注意。
//あと、最初からcout埋め込んでいるので消しておきましょう
//繰り返すときにはG[a]の初期化を忘れないこと
//多重辺があるときには死んでしまうので、適切に処理せよ

//ここまでコピペ推奨

//以下実際の問題

int n;
int getNode(int i, int j , int k) {
  return (i*n+j)*2+k;
}

int main() {
  int k;
  cin>>n>>k;
  k = min(n,k);
  V = n*n*2+2;
  int start = V-2;
  int goal = V-1;
  for(int i=0; i<n; i++) for(int j=0; j<n; j++){
      int p;
      scanf("%d",&p);
      add_edge(getNode(i,j,0),getNode(i,j,1),1,-p);
      if(i==0 || j==0) add_edge(start , getNode(i,j,0) , 1,0);
      if(i==n-1||j==n-1) add_edge(getNode(i,j,1),goal,1,0);
  }
  for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
      if(i!=n-1) add_edge(getNode(i,j,1),getNode(i+1,j,0),1,0);
      if(j!=n-1) add_edge(getNode(i,j,1),getNode(i,j+1,0),1,0);
  }
  cout<<-min_cost_flow_b(start,goal,k)<<endl;

  return 0;
}

