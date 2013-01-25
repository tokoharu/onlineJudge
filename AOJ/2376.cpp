
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

const int NUM = 1000;
bool input[NUM][NUM];

bool solve(int n) {
  int cnt = 0;
  for(int i=0; i<n; i++) 
    for(int j=0; j<n; j++)
      if(input[i][j])
	cnt++;
  cnt/=2;
  int edge = n * (n-1) /2;
  cout<<edge<<" "<<cnt<<endl;
  if(n%2==1) {
    if((edge-cnt)%2==0) return false;
    return true;
  }
  int cnteven = 0;
  int cntBunkatu = 0;
  int used[NUM];
  for(int i=0; i<n; i++) used[i] = false;
  for(int i=0; i<n; i++) if(!used[i]){
      cntBunkatu++;
      int v = 0;
      stack<int> sta;
      sta.push(i);
      used[i] = true;
      while(!sta.empty()) {
	v++;
	int now = sta.top();sta.pop();
	for(int ind=0; ind<n; ind++) 
	  if(input[now][ind]) if(!used[ind]){
	      used[ind] = true;
	      sta.push(ind);
	    }
      }
      if(v%2==0) cnteven++;
    }
  //  cout<<cnteven<<" "<<cntBunkatu<<endl;
  if((edge-cnt)%2==0) {
    if(cnteven<=1 && cntBunkatu<=3) return true;
    return false; 
  }
  if(cnteven==0 && cntBunkatu<=3 ) return false;
}

int main() {
  int n;
  cin>>n;
  for(int i=0; i<n; i++) {
    string s;
    cin>>s;
    for(int j=0; j<n; j++) {
      if(s[j]=='Y') input[i][j] = true;
      else             input[i][j] = false;
    }
  }  
  bool res = solve(n);
  if(res) cout<<"Taro"<<endl;
  else    cout<<"Hanako"<<endl;

  return 0;
}
