#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;



typedef pair<int,int> PII;
typedef long long LL;
#define MP make_pair

  int field[100][100];

  int dist[100][100];
void solve(int w, int h) {
  int H = 2*h+10;
  int W = 2*w+10;
  
  
  for(int i=0; i<H; i++)
    for(int j=0; j<W; j++)
      field[i][j] = 1;
  for(int i=0; i<2*h-1; i++) {
    if(i%2==0) {
      for(int j=0; j<w-1; j++) {
	cin>>field[i+2][j*2+3] ;
      }
    }
    else {
      for(int j=0; j<w; j++) {
	cin>>field[i+2][j*2+2];
	
      }
    }
    
  }
  /*
  cout<<H<<" "<<W<<endl;
  for(int i=0; i<H; i++,cout<<endl) 
    for(int j=0; j<W; j++)
      cout<<field[i][j]<<" ";
  */
  for(int i=0; i<H; i++) for(int j=0; j<W; j++) dist[i][j] = 10000000;
  queue<PII> qu;
  qu.push(MP(2,2));
  dist[2][2] = 0;
  while(!qu.empty()) {
    PII cur = qu.front(); qu.pop();
    int y = cur.first;
    int x = cur.second;
    //    cout<<y<<" "<<x<<endl;
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,1,-1,0};
    for(int d=0; d<4; d++) {
      int nx = dx[d]*2 + x;
      int ny = dy[d]*2 + y;
      int ex = dx[d] + x;
      int ey = dy[d] + y;
      if(dist[ny][nx]<1000) 
	continue;
      if(field[ey][ex]==1)
	continue;
      dist[ny][nx] = dist[y][x] + 1;
      qu.push(MP(ny,nx));
      
    }
  }
  int ans = dist[2*h][2*w]+1;
  if(ans>1000)
    cout<<0<<endl;
  else cout<<ans<<endl;

  //  cout<<dist[2*h][2*w]+1<<endl;
      
  

}


int main() {
  while(1) {
    int w,h;
    cin>>w>>h;
    if(w==0 && h==0) break;
    solve(w,h);

  }
  
  
  return 0;
}
