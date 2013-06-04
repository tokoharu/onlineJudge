#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair

const int MAXN = 55;
const int MAXT = 120;
int G[MAXN][MAXN];
int dp[MAXN][MAXN][MAXT+1];
int N;

int dfs(int A, int B, int t) {
  if(A==B) return t;
  int inf = 10000000;
  if(t==MAXT) return inf;
  if(dp[A][B][t]!=-1) return dp[A][B][t];
  if(t%2==0) {
    int maxim = -1;
    for(int i=0; i<N; i++) {
      if(G[A][i]==1) {
	int x = dfs(i,B,t+1);
	maxim = max(maxim, x);
      }
      
    }
    return dp[A][B][t] = maxim; 
  }
  
  int minim = inf+1;
  for(int i=0; i<N; i++) {
    if(G[B][i]==1) 
      minim = min(minim, dfs(A,i,t+1));
    
  }
  return dp[A][B][t] = minim;
  
}


void solve() {
  int n;
  cin>>N;
  n=N;
  for(int i=0; i<MAXN; i++)
    for(int j=0; j<MAXN; j++)
      for(int k=0; k<=MAXT; k++) 
	dp[i][j][k] = -1;
  
  for(int i=0; i<n; i++) 
    for(int j=0; j<n; j++) {
      cin>>G[i][j];
      if(i==j) G[i][j] = 1;
      
    }
  int Alice, Bob;
  cin>>Alice>>Bob;
  int ans = dfs(Alice, Bob, 0);
  if(1000>ans) cout<<(ans+1)/2<<endl;
  else cout<<"infinity"<<endl;
}


int main() {
  int t;
  cin>>t;
  for(int i=0; i<t; i++)
    solve();
  
  return 0;
}
