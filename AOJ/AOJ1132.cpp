#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<utility>
#include<cmath>
using namespace std;

typedef pair<double,double> PDD;
#define MP make_pair

long double twice(long double a) {return a*a; }

long double dist(PDD a, PDD b) {
  return sqrt(twice((long double)a.first - b.first) + twice((long double)a.second - b.second));
  
}
double EPS = 1e-6;

int solve() {
  int n;
  cin>>n;
  if(n==0) return -1;
  
  vector<pair<double,double> > input;
  for(int i=0; i<n; i++) {
    double p,q;
    cin>>p>>q;
    input.push_back(MP(p,q));
  }
  if(n==1) return 1;
  int ans = 1;
  for(int A=0; A<n; A++) {
    for(int B=A+1; B<n; B++) {
      for(int pat=0; pat<2; pat++) {
	long double x,y;
	long double d = dist(input[A],input[B]) / 2.0;
	if(d-EPS>1.0) continue;
	x = input[A].first + input[B].first;
	y = input[A].second + input[B].second;
	x /= 2.0 ,  y/= 2.0;
	
	long double dx = (long double )input[A].first - x;
	long double dy = (long double )input[A].second - y;
	
	long double dd = sqrt(1.00 - twice(d) ) / d;

	if(1.00-twice(d)<0) while(1);
	//	if(n<5)cout<<"dist"<<dx<<" "<<dy<<" "<<dd<<" "<<d<<endl;
	if(pat==0) {
	  x += dy * dd;
	  y -= dx * dd;
	}
	if(pat==1) {
	  x -= dy * dd;
	  y += dx * dd;
	}
	//cout<<dist(input[A], PDD(x,y))<<" "<<dist(input[B], PDD(x,y))<<endl;
	
	int cnt = 0;
	for(int i=0; i<n; i++) {
	  //	  if(n<5)cout<<dist(input[i], PDD(x,y))<<" ";
	  if(dist(input[i], PDD(x,y))<1.0 + EPS) {
	    cnt++;
	  }
	}
	//	if(n<5)cout<<endl<<A<<" "<<B<<" "<<cnt<<endl;
	ans = max(ans , cnt);
      } 
    }
  }
  return ans;
  
  
}


int main() {
  while(1) {
    int ans = solve();
    //    cout<<ans<<endl;
    if(ans<0) break;
    cout<<ans<<endl;
    
  }
   
  return 0;
}
