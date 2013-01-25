
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

const int NUM = 1000100;

LL parent[NUM];
LL child[NUM][2];

LL dist[NUM];
LL ending[NUM];
LL best[NUM];
LL res[NUM];
LL dp[NUM]; 
LL height[NUM];

int index;
void makeLeaf(int par,int hei) {
  parent[index] = par;
  best[index] = 0;
  ending[index] = 1;
  dist[index] = 0;
  //  res[index] = hei;
  //  dp[index] = res[index];
  dp[index] = hei;
  index++;
}

int main() {
  LL INF = 10000000;
  INF *= INF;
  int n;
  cin>>n;
  index = n;
  parent[1] = -1;
  height[1] = 0;
  for(int i=1; i<n; i++) {
    dist[i] = 0;
    ending[i] = 0;
    best[i] = INF;
    res[i] = INF;
    dp[i] = INF;
    int p,q;
    scanf("%d %d",&p,&q);
    if(p==n) {
      child[i][0] = index;
      makeLeaf(i,height[i]+1);
    }
    else {
      height[p] = height[i]+1;
      parent[p] = i;
      child[i][0] = p;
    }
    if(q==n) {
      child[i][1] = index;
      makeLeaf(i,height[i]+1);
    }
    else {
      height[q] = height[i]+1;
      parent[q] = i;
      child[i][1] = q;
    }
  }
  for(int i=index-1; i>=1; i--) {
    int par = parent[i];
    if(i<n) {
      int p = child[i][0];
      int q = child[i][1];
      best[i] = min(best[p]+ending[q]+dist[q],best[q]+ending[p]+dist[p])+1;
      //      res[i] = best[i] + height[i];
      //      dp[i] = min(best[i]+height[i],dp[p]+dp[q]);
      best[i] =  dp[i] = min(best[i] , dp[p]+dp[q]+2+height[i]);
      //     cout<<p<<" "<<q<<endl;
    }
    if(i>1) {
      ending[par] += ending[i];
      dist[par] += ending[i] + dist[i];
    }
    //        cout<<i<<" "<<ending[i]<<" "<<dist[i]<<" "<<best[i]<<" "<<dp[i]<<endl;
  }
  cout<<dp[1]<<endl;

  return 0;
}
