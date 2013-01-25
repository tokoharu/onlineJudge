
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
const int POS = 150;
int dist[POS*2][POS*2];
bool used[POS*2][POS*2];

void init(int initx,int inity , int initcnt) {
  used[initx][inity] = true;
  queue<pair<PII,int> > qu;
  qu.push(MP(MP(initx,inity),initcnt));
  while(!qu.empty()) {
    int x = qu.front().first.first;
    int y = qu.front().first.second;
    int cnt = qu.front().second; 
    qu.pop();

    int dx[6] = {-1,-1,0,0,1,1};
    int dyA[6] = {0,1,-1,1,0,1}; // n:odd
    int dyB[6] = {-1,0,-1,1,-1,0};//n:even
    if(x<0 || y<0 || x>=2*POS || y>=2*POS) {
	continue; 
    }
    dist[x][y] = cnt;
    for(int i=0; i<6; i++) {
      int nx = x + dx[i];
      int ny = y + dyB[i];
      if(x%2==0) ny = y+dyA[i];
      if(!used[nx][ny]) {
	used[nx][ny] = true;
	qu.push(MP(MP(nx,ny),cnt+1));
      }
    }
    
  }
  /*
    for(int i=0; i<10; i++,cout<<endl) for(int j=0; j<10; j++) {
	if(j==0 && i%2==1) cout<<" ";
     cout<<dist[145+i][145+j]<<" ";
     }
  */
}
int calcDist(int x,int y,int z,int w){
  if(z%2==1) {
    if(x%2==1) ;
    else y++;
    z++;
    x++;
  }
  return dist[POS-z+x][POS-w+y];
}

 int field[POS][POS];

void solve(int m,int n ) {
  vector<PII> rival;
  vector<PII> cand;
  int r,s;
  cin>>r;
  for(int i=0; i<r; i++) {
    int p,q;
    scanf("%d %d",&p,&q);
    rival.push_back(MP(q,p)); 
  }
  cin>>s;
  for(int i=0 ;i<s; i++) {
    int p,q;
    scanf("%d %d",&p,&q);
    cand.push_back(MP(q,p));
  }
  int ans = 0;  
  for(int mine=0; mine<s; mine++) {
    int cnt = 0;
    //    cout<<n<<" "<<m<<endl;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) {
	//	if(j==1) cout<<endl;
	//	if(j==1 && i%2==0) cout<<" ";	
	int kijun = calcDist(i,j,cand[mine].first , cand[mine].second);
	bool ok = true;
       for(int ind=0; ind<rival.size(); ind++) {
	 if(calcDist(i,j,rival[ind].first , rival[ind].second) <= kijun)
	   ok = false;;
       }
       if(ok) cnt++ ;
       //       if(ok) cout<<"# ";
       /*      if(ok) cout<<kijun<<" " ;
       else cout<<"* ";
       */
    }
    ans = max(ans , cnt);
  }
  cout<<ans<<endl;
}

int main() {
  for(int i=0; i<POS*2; i++) for(int j=0; j<POS*2; j++) used[i][j] =false;
  init(POS,POS,0);
  while(1) {
    int n,m;
    cin>>m;
    if(m==0 ) break;
    cin>>n;
    solve(m,n);

  }
  
  return 0;
}

