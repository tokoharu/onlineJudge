
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




//最大公約数
//最小公倍数
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}



const int NUM = 101;
bool solve(int n) {
  int dist[NUM];
  bool reached[NUM];
  for(int i=0; i<=n; i++) dist[i] = -1000000;
  dist[0] = 100;

  bool reachable[NUM][NUM];
  for(int i=0; i<n; i++) for(int j=0; j<n; j++) reachable[i][j] = false;

  vector<int> energy;
  vector<int> next[NUM];
  for(int i=0; i<n; i++) {
    int p,m;
    scanf("%d %d",&p,&m);
    energy.push_back(p);
    for(int j=0; j<m; j++) {
      int k;
      scanf("%d",&k);
      k--;
      next[i].push_back(k); 
      reachable[i][k] = true;
    }
    reached[i] = false;
  }
  reached[0] = true;

  for(int j=0; j<n; j++) for(int i=0; i<n; i++) for(int k=0; k<n; k++) reachable[i][k] |= reachable[i][j]&reachable[j][k];

  for(int i=0; i<n*2+5; i++) {
    int tmp[NUM];
    bool update= false;
    for(int j=0; j<=n; j++) tmp[j] = dist[j];
    for(int j=0; j<n; j++) {
      for(int k=0; k<next[j].size(); k++) {
	int dest = next[j][k];
	int newDist = energy[dest]+dist[j];
	//	reached[dest] |= reached[j];
	if(newDist>0) {
	  if(tmp[dest]<newDist) {
	    update = true;
	    tmp[dest] = newDist ;
	    if(i>n+5) if(reachable[dest][n-1]) return true; 
	    if(dest==n-1) return true;
	  }
	}
      }
    }
    for(int j=0; j<n; j++) dist[j] = max(dist[j],tmp[j]);
  }
  return false;
}

int main() {
  while(1) {
    int n;
    cin>>n;
    if(n==-1) break;
    if(solve(n))cout<<"winnable"<<endl;
    else       cout<< "hopeless"<<endl;
  }
  return 0;
}
