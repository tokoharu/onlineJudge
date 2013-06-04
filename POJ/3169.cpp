#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
typedef pair<int,int> PII;
#define MP make_pair

int dist[1005];
int inf = 1000000000;

vector<PII> graph[1005];

int main() {
  int N, A, B;
  cin>>N>>A>>B;
  for(int i=0; i<A; i++) {
    int p,q,r;
    scanf("%d%d%d",&p,&q,&r);
    p--;q--;
    graph[p].push_back(MP(q,r));
  }
  for(int i=0; i<B; i++) {
    int p,q,r;
    scanf("%d%d%d",&p,&q,&r);
    p--;q--;
    graph[q].push_back(MP(p,-r));
  }
  for(int i=1; i<N; i++) {
    graph[i].push_back(MP(i-1,0));
  }
  for(int i=0; i<N; i++)
    dist[i] = inf;
  dist[0] = 0;
  for(int x=0; x<N+10; x++) {
    bool update = false;
    for(int v=0; v<N; v++) {
      for(int j=0; j<graph[v].size(); j++) {
	int u = graph[v][j].first;
	int cost = graph[v][j].second;
	//	cout<<v<<" "<<u<<" "<<cost<<endl;
	if(dist[u] > dist[v] + cost) {
	  dist[u] = dist[v] + cost;
	  update = true;
	}
      }
    }
    if(!update) 
      break;
    if(x==N+9) {
      cout<<"-1"<<endl;
      return 0;
    }
  }
  //  for(int i=0; i<N; i++) cout<<i<<" "<<dist[i]<<endl;
  cout<<(dist[N-1]==inf?-2:dist[N-1])<<endl;
  
  return 0;
}
