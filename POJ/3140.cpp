#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>


using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair


const int MAXN = 100007;
vector<int> graph[MAXN];
LL cnt[MAXN];
int parent[MAXN];


LL absL(LL n ) {
  if(n>0) return n;
  return -n;
}
 
bool solve(int casenum) {
  int n,m;
  cin>>n>>m;
  if(n==0 && m==0) return false;
  for(int i=0; i<n; i++)
    graph[i].clear();
    
  LL sum = 0;
  for(int i=0; i<n; i++) {
    int p;
    scanf("%d",&p);
    cnt[i] = p;
    sum += (LL)p;
  }
  for(int i=0; i<m; i++) {
    int p,q;
    scanf("%d%d",&p,&q);
    p--;q--;
    graph[p].push_back(q);
    graph[q].push_back(p);
  }
  stack<PII>  sta;
  vector<int> order;
  sta.push(MP(0,-1));
  while(!sta.empty()) {
    PII tmp = sta.top();sta.pop();
    int cur = tmp.first;
    int par = tmp.second;
    parent[cur] = par;
    order.push_back(cur);
    for(int i=0; i<graph[cur].size(); i++) {
      int next = graph[cur][i];
      if(next!=par)
	sta.push(MP(next,cur));
    }
  }

  reverse(order.begin() , order.end());
  LL ans  = 1000000;
  ans *= ans * ans;
  
  for(int i=0; i<order.size(); i++) {
    int cur = order[i];
    int par = parent[order[i]];
    ans = min(ans ,absL(sum - 2*cnt[cur]) );
    if(par>=0)
      cnt[par] += cnt[cur];
  }
  cout<<"Case "<<casenum<<": "<<ans<<endl;
  return true;
}


int main() {
  for(int i=1;; i++) 
    if(!solve(i))
      break;
  return 0;
}
