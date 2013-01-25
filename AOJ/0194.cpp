
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

PII trans(string s) {
  PII ret;
  ret.first = s[0]-'a';
  if(s.size()==3) ret.second = s[2]-'1';
  if(s.size()==4) {
    ret.second = (s[2]-'0')*10 + s[3]-'0' - 1;
  }
  
  return ret;
}
PII inputAndTrans() {
  string s;
  cin>>s;
  return trans(s);
}

set<pair<PII,int> > arrivingSet[101];

void addState(PII pos , int t , int dir) {
  arrivingSet[t].insert(MP(pos,dir));
}



const int MAXW = 21;

void solve(int M, int N) {
  for(int i=0; i<101; i++) arrivingSet[i].clear();
  int D , ns , nc , nj;
  int dist[MAXW*2][MAXW*2];
  int shingo[MAXW][MAXW];
  cin>>D;
  for(int i=0; i<MAXW*2; i++) 
    for(int j=0; j<MAXW*2; j++) 
      dist[i][j] = D;
  for(int i=0; i<MAXW; i++) 
    for(int j=0; j<MAXW; j++)
      shingo[i][j] = -1;


  cin>>ns;
  for(int i=0; i<ns; i++) {
    string s;
    int k;
    cin>>s;
    cin>>k;
    PII p = trans(s);
    shingo[p.first][p.second] = k;
  }
  cin>>nc;
  for(int i=0; i<nc; i++) {
    string s,t;
    cin>>s>>t;
    PII p = trans(s);
    PII q = trans(t);
    dist[p.first+q.first][p.second+q.second] = 10000;
  }
  cin>>nj;
  for(int i=0; i<nj; i++) {
    string s,t;
    int d;
    cin>>s>>t>>d;
    PII p = trans(s);
    PII q = trans(t);
    dist[p.first+q.first][p.second+q.second] += d;
  }
  PII start = inputAndTrans();
  PII goal  = inputAndTrans();
  
  //  cout<<start.first<<" "<<start.second<<" "<<goal.first<<" "<<goal.second<<endl;
  //  cout<<D<<" "<<ns<<" "<<nj<<endl;
  
  addState(start,0,1);
  for(int tm=0; tm<=100; tm++) {
    //   cout<<"tm"<<tm<<endl;
    EACH(i,arrivingSet[tm]) {
      pair<PII,int> tmp = *i;
      PII pos = tmp.first;
      int dir = tmp.second;
      //      cout<<pos.first<<" "<<pos.second<<" "<<dir<<endl;

      if(pos==goal) {
	cout<<tm<<endl;
	return;
      }

      int dx[4] = {1,0,-1,0};
      int dy[4] = {0,1,0,-1};
      for(int d=0; d<4; d++) 
	if((d+2)%4!=dir) {
	  PII npos = pos;
	  npos.first += dx[d];
	  npos.second += dy[d];
	  if(npos.first<0) continue;
	  if(npos.first>=N) continue;
	  if(npos.second<0) continue;
	  if(npos.second>=M) continue;

	  int ntm = tm + dist[npos.first+pos.first][npos.second+pos.second];
	  //	  cout<<"    ntm"<<ntm<<endl;
	  if(ntm>100) continue;
	  
	  int shingoK = shingo[npos.first][npos.second];
	  if(shingoK!=-1) {
	    //	    cout<<"    "<<shingoK<<" "<<endl;
	    if(!(ntm/shingoK%2==0 ^ d%2==1)) continue; 
	    //	    cout<<"ok"<<endl;
	  }
	  addState(npos,ntm,d);
	}
    }
    
  }

}
 

int main() {
  while(1) {
    int m,n;
    cin>>m>>n;
    if(m==0 && n==0) break;
    solve(n,m);
    //    break;
  }
  return 0;
}


