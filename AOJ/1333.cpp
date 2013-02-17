
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
const int MAXW = 80010;

int W,N;
vector<int> input;

void makeIndex(vector<int> &index , int K , bool wide) {
  int sum = input[0];
  int right = 1;
  for(int now=0; now<N; now++) {
    if(wide) {
      while(sum<=W) {
	sum += K+input[right];
	right++;
      }
    }
    else {
      while(sum<W) {
	sum += K+input[right];
	right++;
      }
    }
    index.push_back(right-1);
    sum -= K+input[now];
  }
  index.push_back(N);
  
}

int dp[MAXW];
vector<int>rightA;
bool check(int K) {
  vector<int> left ;
  makeIndex(left,K,false);
  for(int i=0; i<MAXW; i++) dp[i] = 0;
  dp[0] = 1;
  dp[1] = -1;
  int sum = 0;
  for(int now = 0;now<=N; now++) {
    sum += dp[now];
    if(sum>0){
      if(left[now]==N) return true;
      if(left[now]<rightA[now]) {
	dp[left[now]+1]++;
	dp[rightA[now]+1]--;
      }
    }
  }
  return false;

}


void solve() {
  input.clear();
  for(int i=0; i<N; i++) {
    int p;
    scanf("%d",&p);
    input.push_back(p);
  }
  input.push_back(1000000);
  int leftK= 0, rightK = W;
  rightA.clear();
  makeIndex(rightA,1,true);
  while(leftK+1<rightK) {
    int medK = (leftK+rightK+1)/2;
    if(check(medK)) rightK = medK;
    else leftK = medK;
  }
  //  cout<<rightK<<endl;
  printf("%d\n",rightK);
}


int main() {
  while(1) {
    scanf("%d %d",&W,&N);
    if(W==0 && N==0) break;
    solve();
  }
  
  return 0;
}
