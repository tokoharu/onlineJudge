 
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

vector<vector<int> > makeTable(vector<int> X , vector<int>Y) {
  int n = X.size();
  int m = Y.size();
  vector<vector<int> > ret(n+1 , vector<int>(m+1,0)); 

  int inf = 10000000;
  for(int i=0; i<n+1; i++) ret[i][0] = inf;
  for(int j=0; j<m+1; j++) ret[n][j] = inf;
  ret[n][0] = 0;

  for(int i=n-1; i>=0; i--) 
    for(int j=1; j<=m; j++) {
      int next = ret[i+1][j-1];
      int sum = 0;
      for(int k=j-2; k>=0; k--) {
	sum += abs(X[i]-Y[k]);
	next = min(next , sum + ret[i+1][k] );
      }
      sum = 0;
      for(int k=i+2; k<=n; k++) {
	sum += abs(Y[j-1]-X[k-1]);
	next = min(next , sum + ret[k][j-1]);
      }
      ret[i][j] = next + abs(X[i]-Y[j-1]);
    }
  /*
  for(int i=0; i<n+1; i++,cout<<endl)
    for(int j=0; j<m+1; j++) 
      cout<<ret[i][j]<<" ";
  */
  return ret;
}



void solve() {
  int n,m,k;
  cin>>n>>m>>k;
  vector<int>X;
  vector<int>Y;
  vector<int>Z;
  for(int i=0; i<n; i++) {
    int p;
    cin>>p;
    X.push_back(p);
  }
  for(int i=0; i<m; i++) {
    int p;
    cin>>p;
    Y.push_back(p);
  }
  for(int i=0; i<k ;i++) {
    int p;
    cin>>p;
    Z.push_back(p);
  }
  vector<vector<int> > XY = makeTable(X,Y);
  vector<vector<int> > YZ = makeTable(Y,Z);
  vector<vector<int> > ZX = makeTable(Z,X);
  int ans = 1000000000;
  for(int x=0; x<=X.size(); x++) 
    for(int y=0; y<=Y.size(); y++) 
      for(int z=0; z<=Z.size(); z++) {
	ans = min(ans ,XY[x][y] + YZ[y][z] + ZX[z][x] ) ;
      }
  for(int x=0; x<X.size(); x++) 
    for(int y=0; y<Y.size(); y++)
      for(int z=0; z<Z.size(); z++)  {
	int score = XY[x+1][y] + YZ[y+1][z] + ZX[z+1][x];
	int p = abs(X[x] - Y[y]);
	int q = abs(Y[y] - Z[z]);
	int r = abs(Z[z] - X[x]);
	score += p + q + r - max(max(p,q),r);
	//	cout<<x<<" "<<y<<" "<<z<<" "<<score<<endl;
	ans = min(ans,score);
      }

  cout<<ans<<endl;
}


int main() {
  int n;
  cin>>n;
  for(int i=0; i<n; i++) solve();
  return 0;
}
