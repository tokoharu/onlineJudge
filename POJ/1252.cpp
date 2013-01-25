
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

const int NUM  = 205;
void solve() {
  vector<int> coins;
  for(int i=0; i<6; i++) {
    int p;
    cin>>p;
    coins.push_back(p);
  }
  int dist[NUM][NUM];
  for(int i=0; i<NUM; i++) 
    for(int j=0; j<NUM; j++)
      dist[i][j] = 10000;
  for(int c=0; c<coins.size(); c++) {
    for(int i=0; i+coins[c]<NUM; i++) {
      int p = i;
      int q = i+coins[c];
      dist[p][q] = 1;
      dist[q][p] = 1;
    }
  }

  for(int j=0; j<NUM; j++) 
    for(int i=0; i<NUM; i++) 
      for(int k=0; k<NUM; k++)
	dist[i][k] = min(dist[i][k] , dist[i][j] + dist[j][k]);
  int ans = 0;
  int maxim = 0;
  for(int i=1; i<=100; i++) ans += dist[0][i] , maxim = max(maxim , dist[0][i]);
  cout<<ans/100<<".";
  printf("%2d",ans%100);
  cout<<" "<<maxim<<endl;
}


int main() {
  int t;
  cin>>t;
  for(int i=0; i<t; i++) solve();
  return 0;
}


