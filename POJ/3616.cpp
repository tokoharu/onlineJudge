/*
POJ3616
Rの時間だけ牛を使えないので、それぞれのスケジュールにR後付して
重み付きスケジューリングの軽いDPのような何か。
メモリ削減は面倒なのでメモリは潤沢に使用
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair

const int MAXS = 1000010;
vector<PII> data[2*MAXS];
int dp[2*MAXS];

int main() {
  int n,m,r;
  cin>>n>>m>>r;

  for(int i=0; i<2*n; i++) { 
    data[i].clear();
    dp[i] = 0;
  }
  for(int i=0; i<m; i++) {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    data[a].push_back( MP(b+r,c) );
  }
  int maxim = 0;
  for(int i=0; i<2*n; i++) {
    maxim = max(maxim,dp[i]);
    for(int j=0; j<data[i].size(); j++) {
      int dest = data[i][j].first;
      dp[dest] = max(dp[dest] , maxim + data[i][j].second);
    } 
  }
  cout<<maxim<<endl;
  return 0;
}
