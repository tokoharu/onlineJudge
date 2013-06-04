#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<utility>
using namespace std;

#define MP make_pair
typedef long long LL;
typedef pair<int,int> PII;

LL MOD = 1000000007;

void solve(){
  int N,W;
  cin>>N>>W;
  vector<int> input;
  vector<int> allSum;
  {
    int sum = 0;
    bool ok = true;
    for(int i=0; i<N; i++) {
      int p;
      scanf("%d",&p);
      input.push_back(p);
      sum += p;
      if(p<=W) ok = false;
    }
    if(sum<=W || ok) {
      cout<<1<<endl;
      return ;
    }
  }
  sort(input.begin() , input.end());
  {
    int sum = 0;
    allSum.push_back(0);
    for(int i=0; i<N; i++) {
      sum += input[i];
      allSum.push_back(sum);
    }
  }
  
  
  LL ans = 0;
  const int MAXW = 10010;
  LL dp[MAXW];
  for(int i=0; i<MAXW; i++) dp[i] = 0;
  dp[0] = 1;
  for(int cur=N-1; cur>=0; cur--) {
    int sum = allSum[cur];
    int start = W-input[cur]+1-sum;
    int goal = W - sum;
    start = max(start,0);
    for(int w=start; w<=goal; w++) {
      ans += dp[w];
      ans %= MOD;
    }/*
    cout<<start<<" "<<goal<<endl;
    cout<<ans<<endl;
    for(int w=0; w<=W; w++) cout<<dp[w]<<" ";
    cout<<endl;
     */
    int weight = input[cur];
    for(int w=W; w>=weight; w--) {
      dp[w] += dp[w-weight];
      dp[w] %= MOD;
    }
  }
  cout<<ans<<endl;
}


int main() {
  solve();
  
  return 0;
}
