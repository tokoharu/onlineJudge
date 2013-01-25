 
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

const int NUM = 210;
vector<int> graph[NUM];
void solve(int n ,int m) {
  for(int i=0; i<NUM; i++) graph[i].clear();

  vector<int> node;
  vector<int> diff;
  for(int i=0; i<n; i++) {
    int p;
    cin>>p;
    node.push_back(p); 
  }
  for(int i=0; i<m; i++) {
    int p;
    cin>>p;
    diff.push_back(p);
  }
  sort(diff.begin() , diff.end());  

  for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++)
      if(binary_search(diff.begin() , diff.end() , node[j]-node[i]) ) {
	graph[i].push_back(j);
	graph[j].push_back(i);
	//	cout<<i<<" "<<j<<endl;
      }
  
  int parent[NUM];
  bool used[NUM];
  vector<int> order;
  for(int i=0; i<n; i++) {
    used[i] = false;
    parent[i] = -1;
  }
  for(int i=0; i<n; i++) if(!used[i]){
    stack<int> sta;
    sta.push(i);
    parent[i] = -1;
    used[i] = true;
    while(!sta.empty()) {
      int now = sta.top(); sta.pop();
      order.push_back(now);
      for(int j=0; j<graph[now].size(); j++) {
	int next = graph[now][j];
	if(!used[next]) {
	  used[next] = true ;
	  sta.push(next);
	  parent[next] = now;
	}
      }
    }
  }
  //  for(int i=0; i<n; i++) cout<<i<<" "<<parent[i]<<endl;  
  int dp[NUM][2];
  for(int i=0; i<NUM; i++) for(int j=0; j<2; j++) dp[i][j] = 0;
  reverse(order.begin() , order.end());
  // for(int i=0; i<order.size(); i++) cout<<order[i]<<" ";
  // cout<<endl;
  

  for(int i=0; i<order.size(); i++) {
    int now = order[i];
    dp[now][1] += node[now];
    if(parent[now]>=0) {
      dp[parent[now]][0] += max(dp[now][1],dp[now][0]);
      dp[parent[now]][1] += dp[now][0];
    }
  }
  int ans = 0;
  for(int i=0; i<n; i++) if(parent[i]==-1){
      //    cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
      ans += max(dp[i][0] , dp[i][1]);
  }
  cout<<ans<<endl;
}


int main() {
  while(1) {
    int n,m;
    cin>>n>>m;
    if(n==0 && m==0) break;
    solve(n,m);
  }  
  return 0;
}
