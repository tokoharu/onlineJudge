
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
#define ALL(c) (c).begin(),(c).end() include<iostream>

const int NUM = 25100;
bool field[60][60][30];
int pos[NUM][3];

bool checkAndFill(int x,int y , int z) {
  if(field[x][y][z]) return false;
  field[x][y][z] = true;
  return true;
}


int main() {
  int n;
  cin>>n;
  pos[1][0] = 30;  pos[1][1] = 30; pos[1][2] = 1;
  checkAndFill(pos[1][0] , pos[1][1] , pos[1][2]);

  bool ok = true;
  int cntAdj = 0;
  for(int i=2; i<=n; i++) {
    int p;
    char c;
    scanf("%d %c",&p,&c);
    int data[3] ;
    for(int d=0; d<3; d++) data[d]= pos[p][d];
    if(c=='L') data[0]--;
    if(c=='R') data[0]++;
    if(c=='F') data[1]++;
    if(c=='B') data[1]--;
    if(c=='O') data[2]++;
    if(c=='U') data[2]--; 
    
    for(int d=0; d<3 ; d++) pos[i][d] = data[d];
    ok &= checkAndFill(data[0] , data[1] , data[2]);
    //   cout<<ok<<endl;
    int dx[6] = {1,-1,0,0,0,0};
    int dy[6] = {0,0,1,-1,0,0};
    int dz[6] = {0,0,0,0,1,-1};
    for(int d=0; d<6; d++) {
      int nx = data[0] + dx[d];
      int ny = data[1] + dy[d];
      int nz = data[2] + dz[d];
      if(field[nx][ny][nz]) cntAdj++;
    }
  }

  int ans = n * 6 - cntAdj*2;
  for(int i=0; i<60; i++) 
    for(int j=0; j<60; j++) 
      if(field[i][j][1]) {
	//	cout<<"poyo"<<endl;
	ans--;
      }
  if(!ok) ans = -1;
  cout<<ans<<endl;
  return 0;
}


