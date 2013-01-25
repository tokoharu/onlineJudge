
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

int main() {
  int n,a,b;
  cin>>n>>a>>b;
  a--;b--;
  int dist[101][101];
  for(int i=0; i<101; i++)
    for(int j=0; j<101; j++)
      dist[i][j] = 100000;
  for(int i=0; i<n; i++)  {
    int m;
    cin>>m;
    for(int j=0; j<m; j++) {
      int p ;
      cin>>p;
      p--;
      if(j==0) dist[i][p] = 0;
      else     dist[i][p] = 1;
    }
  }
  for(int j=0; j<n; j++) 
    for(int i=0; i<n; i++)
      for(int k=0; k<n; k++)
	if(dist[i][j] + dist[j][k] < dist[i][k])
	  dist[i][k] = dist[i][j] + dist[j][k];
  if(dist[a][b]>10000) dist[a][b] = -1;
  cout<<dist[a][b]<<endl;
  return 0;

}

