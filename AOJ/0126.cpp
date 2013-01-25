
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

void solve() {
  int table[9][9];
  bool wrong[9][9];
  int n = 9;
  for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
      cin>>table[i][j];
      wrong[i][j] = false;
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n;j++) {
      for(int k=0; k<n; k++) if(j!=k) {
	if(table[i][j]==table[i][k]) wrong[i][j] = wrong[i][k] = true;
	if(table[j][i]==table[k][i]) wrong[j][i]  =wrong[k][i] = true;
	
      }
    }
  }
  for(int x=0; x<3; x++) for(int y=0; y<3; y++) {
   for(int j=0; j<3; j++) for(int k=0; k<3; k++) {
       int X = x*3+j;
       int Y = y*3+k;  
       for(int p = 0; p<3; p++) for(int q=0; q<3; q++)if(!(j==p && k==q)) {
	     int Z = x * 3+p;
	     int W = y *3 + q;
	     if(table[X][Y]==table[Z][W]) wrong[X][Y] = wrong[Z][W] = true;
	  
       }
   }
  }
  for(int i=0; i<n; i++,cout<<endl) for(int j=0; j<n; j++) {
      if(wrong[i][j]) cout<<"*";
      else cout<<" ";
      cout<<table[i][j];

  }

}




int main() {
  int n;
  cin>>n;
  for(int i=0; i<n; i++) solve();
  
  return 0;
}

