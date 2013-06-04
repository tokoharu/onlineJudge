#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<utility>
#include<queue>


using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair


#define MAX_V 60000
const int INF = 100000;

struct edge{int to,cost;};

int V;
vector<edge> G[MAX_V];
int d[MAX_V];
bool used[MAX_V];
int inQ[MAX_V];

void spfa(int s) {
  for(int i=0;i<V;++i) d[i]=INF,inQ[i]=0;
  queue<int>q;
  inQ[s]=1;q.push(s);d[s]=0;
  while(!q.empty()){
    int cur=q.front();q.pop();
    inQ[cur]=0;
    int sz = G[cur].size();
    //    for(int i=head[cur];i!=-1;i=nxt[i]){//リストを走査
    for(int i=0; i<G[cur].size(); i++) {
      edge  e = G[cur][i];//(行き先,辺のコスト)
      if(d[e.to] > d[cur]+e.cost){
	d[e.to]=d[cur]+e.cost;
	if(!inQ[e.to]){
	  inQ[e.to]=1;
	  q.push(e.to);
	}
      }
    }
  }
}

/*
void dijkstra(int s){
  priority_queue<PII,vector<PII>,greater<PII> >que;
  
  for(int i=0; i<V; i++){
    d[i] = INF;
    used[i] = false;
    
  }
  d[s]=0;
  que.push(PII(0,-s));
  
  while(!que.empty()){
    PII p=que.top();que.pop();
    int v=-p.second;
    if(d[v]<p.first)continue;
    
    for(int u=v; u<V ; u++) {
      int sz = G[u].size();
      for(int i=0;i<sz;i++){
	edge e =G[u][i];
	if(d[e.to]>d[u]+e.cost) {
	  d[e.to]=d[u]+e.cost;
	  que.push(PII(d[e.to],-e.to));
	}
      }

      if(used[u]) break;
      used[u] = true;
    }
  }
  }
*/

void add_edge(int from,int to,int cost){
  G[from].push_back((edge){to,cost});
}

int main() {
  int n;
  //  cin>>n;
  scanf("%d",&n);
  V = 50008;
  for(int i=0; i<n; i++) {
    int a,b,x;
    scanf("%d%d%d",&a,&b,&x);
    add_edge(b+1,a,-x);
  }
  
  for(int i=0; i<50005; i++) {
    add_edge(i,i+1, 1);
    add_edge(i+1,i,0);
  }
  //  cout<<"hoge"<<endl;
  
  spfa(50002);
  /*  for(int i=0; i<12; i++) cout<<d[i]<<" ";
      cout<<endl;*/
  printf("%d\n",-d[0]);
  return 0;
}
