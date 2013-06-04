#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair

const int MAXN = 1009;
LL dp[MAXN][MAXN];
LL pos[MAXN][MAXN];


int main() {
  vector<PII> input;
  int n;
  cin>>n;
  for(int i=0; i<n; i++) {
    int p,q;
    scanf("%d%d" ,&p ,&q);
    input.push_back(MP(p,q));
  }
  LL inf = 10000000;
  inf *= inf;
  for(int i=0; i<=n; i++)
    for(int j=0; j<=n; j++) {
      dp[i][j] = inf;
      pos[i][j] = -1;
    }
  
  for(int i=0; i<n; i++) {
    dp[i][i] = 0;
    pos[i][i] = i ;
  }
  for(int d=1; d<n; d++) {
    for(int left=0; left+d<=n; left++) {
      int right = left+d;
      for(int k=pos[left][right-1]; k<=pos[left+1][right]; k++ ) {
	LL newNum = dp[left][k] + dp[k+1][right]
	  + (input[k+1].first - input[left].first)
	  + (input[k].second - input[right].second);
	if(newNum < dp[left][right]) {
	  dp[left][right] = newNum;
	  pos[left][right] = k;
	  
	}
      }
    }
    
  } 
  cout<<dp[0][n-1]<<endl;
  
  return 0;
}
