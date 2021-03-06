/*
POJ3669
あるマスに到達できるなら早ければ早いほうが良い。
後になって得になることはない。
移動のコストは単一なのでBFS。

この程度の量のinputでもcinをするとTLEになるらしい
 */

#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair

const int MAXS  =310;
int safeMap[MAXS][MAXS];
int arriveTm[MAXS][MAXS];

bool valid(int x,int y) {
  if(x<0) return false;
  if(y<0) return false;
  if(x>=MAXS) return false;
  if(y>=MAXS) return false;
  return true;
}


int main() {
  int INF = 1000000;
  for(int i=0; i<MAXS; i++)
    for(int j=0; j<MAXS; j++) {
      safeMap[i][j] = INF;
      arriveTm[i][j]  = INF;
    }


  int dx[5] = {0,0,1,-1,0};
  int dy[5] = {0,1,0,0,-1};
  int m;
  cin>>m;
  for(int i=0; i<m; i++) {
    int x,y,t;
    //    cin>>x>>y>>t;
    scanf("%d%d%d",&x,&y,&t);
    for(int d=0; d<5; d++) {
      int nx = x+dx[d];
      int ny = y+dy[d];
      if(valid(nx,ny))
	safeMap[nx][ny] = min(safeMap[nx][ny] , t);

    }
  }/*
  for(int i=0; i<MAXS; i++) 
    for(int j=0; j<MAXS; j++)
      if(safeMap[i][j]==INF)
	if(safeMap[i][j])

   */

  queue<PII> qu;
  qu.push(MP(0,0));
  arriveTm[0][0] = 0;
  int ans = -1;
  while(!qu.empty()) {
    PII current = qu.front(); qu.pop();
    int now = arriveTm[current.first][current.second];
    if(safeMap[current.first][current.second]==INF) {
      ans = now;
      break;
    }
    
    for(int d=1; d<5; d++ ) {
      PII next = current;
      next.first += dx[d];
      next.second += dy[d];
      if(valid(next.first , next.second)) {
	int x = next.first;
	int y = next.second;
	if(arriveTm[x][y]==INF && now+1<safeMap[x][y] ) {
	  arriveTm[x][y] = now+1;
	  qu.push(next);
	}
      }
    }
  }
  cout<<ans<<endl;

  return 0;
}
