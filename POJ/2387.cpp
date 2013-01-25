
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
#define ALL(c) (c).begin(),(c).end() include<iostream>

const int NUM = 1010;
vector<PII> graph[NUM];

int main() {
  int t,n;
  cin>>t>>n;
  for(int i=0; i<t; i++) {
    int p,q,r;
    scanf("%d %d %d",&p,&q,&r);
    p--;q--;
    graph[p].push_back(MP(q,r));
    graph[q].push_back(MP(p,r));
  }
  int dist[NUM];
  for(int i=0; i<n; i++) dist[i] = 10000000;
  dist[0] = 0;
  for(int x=0; x<n; x++) {
    for(int i=0; i<n; i++) 
      for(int j=0; j<graph[i].size(); j++) {
	int next = graph[i][j].first;
	int cost = graph[i][j].second;
	dist[next] = min(dist[next] , dist[i]+cost);
      }

  }
  cout<<dist[n-1]<<endl;
  return 0;
}


