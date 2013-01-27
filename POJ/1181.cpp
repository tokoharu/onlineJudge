
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

int dist(PII p, PII q) {
  return abs(p.first - q.first) + abs(p.second - q.second) ;
}


int main() {
  int n;
  cin>>n;
  vector<PII> pos;
  for(int i=0; i<n; i++) {
    int  p,q;
    cin>>p>>q;
    pos.push_back(MP(p,q));
  }
  int minim = 100000000;
  for(int me=0; me<n; me++) {
    vector<PII> others;
    for(int i=0; i<n; i++) if(i!=me){
	others.push_back(MP(dist(pos[me],pos[i]) ,i)) ;
    }
    sort(others.begin() , others.end());

    for(int another = 0; another<n; another++) if(another!=me) {
	int m = others.size();
	int maximSum = 100000000;
	int maximAnother = 0;
	for(int i=m-1; i>=0 ;i--)  {
	  cout<<"    "<<others[i].first<<" "<<maximAnother<<endl;
	  maximSum = min(maximSum , maximAnother + others[i].first);
	  maximAnother = max(maximAnother , dist(pos[others[i].second] , pos[another]) );
	}
	maximSum = min(maximSum , maximAnother);
	cout<<me<<" "<<another<<" "<<maximSum<<" "<<dist(pos[another], pos[me])<<" "<<endl;
	minim = min(minim , maximSum + dist(pos[me],pos[another]));
    }
    
  }
  cout<<minim<<endl;
  
  return 0;
}


