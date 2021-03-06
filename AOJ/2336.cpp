/*
2336
パッと見方程式ゲーとも思ったけれども、これは変数1つだけですべての距離を表すことができる
したがって、タイルから階段までの平均到達時間を二分探索で求めてやればよい

 */


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

const int MAXS = 510;
string field[MAXS];
PII start , goal;
vector<PII> spring;

PII dist[MAXS][MAXS];

int main() {
  int W,H;
  cin>>W>>H;
  
  for(int i=0; i<H; i++) {
    string s;
    cin>>s;
    field[i] = s;
    for(int j=0; j<W; j++) {
      if(field[i][j]=='s') start = MP(i,j);
      if(field[i][j]=='g') goal  = MP(i,j);
      if(field[i][j]=='*') spring.push_back(MP(i,j));
    }
  }

  int inf = 100000000;
  for(int i=0; i<H; i++) for(int j=0; j<W; j++) {
      dist[i][j].first = inf;
      dist[i][j].second = inf;
  }
  
  int dx[4] = {1,-1,0,0};
  int dy[4] = {0,0,1,-1};
  //gからの距離を調べる
  {
    queue<PII> qu;
    qu.push(goal);
    dist[goal.first][goal.second].first = 0;
    while(!qu.empty()) {
      PII now = qu.front(); qu.pop();
      for(int d=0; d<4; d++) {
	PII next = now;
	next.first += dx[d];
	next.second += dy[d];
	if(field[next.first][next.second]!='#') {
	  if(dist[next.first][next.second].first == inf) {
	    qu.push(next);
	    dist[next.first][next.second].first = 
	      dist[now.first][now.second].first+1;
	  }
	}
      }      
    }
  }
  //*からの距離を調べる
  {
    queue<PII> qu;
    for(int i=0; i<spring.size(); i++) {
      PII pos = spring[i];
      qu.push(pos);
      dist[pos.first][pos.second].second = 0;
    }
    while(!qu.empty()) {
      PII now = qu.front(); qu.pop();
      for(int d=0; d<4; d++) {
	PII next = now;
	next.first += dx[d];
	next.second += dy[d];
	if(field[next.first][next.second]!='#') {
	  if(dist[next.first][next.second].second == inf) {
	    qu.push(next);
	    dist[next.first][next.second].second = 
	      dist[now.first][now.second].second+1;
	  }
	}
      }
      
    }
    
  }


  double leftX = 0;
  double rightX = 100000000;

  for(int z=0; z<50; z++) {
    double medX = (rightX+leftX)/2;
    int cnt = 0;
    double sum = 0;
    for(int i=0; i<H; i++) 
      for(int j=0; j<W; j++ ) {
	char c = field[i][j];
	if(c=='s' || c=='.') {
	  cnt++;
	  sum += min(medX+(double)dist[i][j].second ,(double)dist[i][j].first );
	  
	}
      }
    if(cnt==0) break;
    sum /= (double)cnt;
    if(sum>medX) leftX = medX;
    else rightX = medX;

  }
  int x = start.first;
  int y = start.second;
  double ans = min((double)dist[x][y].first , leftX + (double)dist[x][y].second);
  printf("%.10f\n",ans);

  return 0;
}
