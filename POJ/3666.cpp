/*
POJ3666
考察をすると、出現する数字のどれかを遷移しても正しい解が求まることがわかる。
よって、各数字の位置でどのくらいの値を取るのかDPをする
下手にやると更新にO(N^2)だけかかってしまうが、
遷移の仕方を観察すると、それまでに出てきたdp[i]の最小値をみていけば良いことがわかる。
 */


#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair

const int MAXS = 2010;
LL dp[MAXS];

LL minL(LL a,LL b) {
  return a<b?a:b;
}

LL solve(vector<int> &input) {
  LL INF = 1000000;
  INF *= INF*INF*2;
  INF++;
  int n = input.size();
  vector<int> sorted = input;
  sort(sorted.begin() , sorted.end());
  
  for(int i=0; i<n; i++) 
    dp[i] = 0;

  for(int x=0; x<n; x++) {
    LL next[MAXS];
    for(int i=0; i<n; i++) 
      next[i] = INF;
    LL minim = INF;
    for(int i=0; i<n; i++) {
      minim = minL(minim,dp[i]);
      next[i] = minim + (LL)abs(input[x]-sorted[i]);
    }

    for(int i=0; i<n; i++) {
      dp[i] = next[i];
      //    cout<<dp[i]<<" ";
    }
    // cout<<endl;
  }
  LL ans = INF;
  for(int i=0; i<n; i++)
    ans = minL(ans , dp[i]);
  //  cout<<ans<<endl;
  return ans;
}

int main() {
  int n;
  cin>>n;
  vector<int> input;
  for(int i=0; i<n; i++) {
    int p;
    scanf("%d",&p);
    input.push_back(p);
  }
  LL ans = solve(input);
  reverse(input.begin(), input.end());
  ans = minL(ans , solve(input));  
  cout<<ans<<endl;
  return 0;
}
