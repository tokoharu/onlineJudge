
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


void solve(int n) {
  int minim = 10000;
  int maxim = 0;
  int sum = 0;
  for(int i=0; i<n; i++) {
    int p;
    cin>>p;
    sum += p;
    minim = min(minim ,p); 
    maxim = max(maxim ,p);
  }

  sum -= maxim + minim;
  sum /= (n-2);
  cout<<sum<<endl;

  return;
}


int main() {
  while(1) {
    int n;
    cin>>n;
    if(n==0) break;
    solve(n);
  }

  return 0;
}

