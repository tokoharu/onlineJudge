
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

const int NUM = 100;
void solve(int n,int m ) {
  double mat[NUM][NUM];
  for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
      scanf("%lf",&mat[i][j]);
  }
  double nowState[NUM];
  for(int i=0; i<n; i++) nowState[i] =1.0;
  for(int i=0; i<m-1; i++) {
    double nextState[NUM];
    for(int j=0; j<NUM; j++) nextState[j] = 0;
    for(int j=0; j<n; j++) for(int k=0; k<n; k++) {
	nextState[k] = max(nextState[k] , nowState[j] * mat[j][k]);
    }
    for(int j=0; j<n; j++) nowState[j] = nextState[j];
  }
  double ans = 0;
  for(int i=0; i<n; i++) ans = max(ans , nowState[i]);
  printf("%.2f\n",ans);

}

int main() {
  while(1) {
    int n,m;
    cin>>n>>m;
    if(n==0 && m==0 ) break;
    solve(n,m);

  }
  
  return 0;
}

