#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<set>
#include<utility>
#include<algorithm>
using namespace std;

#define MP make_pair
typedef pair<double,double> PDD;

const int MAXN = 105;
const double PI = 3.14159265358979;


double two(double k) {
  return k*k;
}

double dist(PDD p, PDD q) {
  return sqrt( two(p.first- q.first) + two(p.second-  q.second)  );
}

void hosei(double &k) {
  while(k<0) k += 2*PI;
  while(k>2*PI) k-= 2*PI;
}


void solve(int n) {
  vector<pair<PDD,double> >  input ;
  bool hougan[MAXN];
  vector<pair<double, int> > kukan[MAXN]; // 位置情報とどちらに遷移するか
  int cntOrigin[MAXN];
  for(int i=0; i<MAXN; i++) {
    hougan[i] = false;
    kukan[i].clear();
    cntOrigin[i] = 0;
  }
  
  for(int i=0; i<n; i++) {
    double p,q,r;
    cin>>p>>q>>r;
    input.push_back(MP(MP(p,q),r));
  }

  double EPS = 1e-10;
  
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) 
      if(i!=j) {
	double d = dist(input[i].first,input[j].first);
	double a = input[i].second;
	double b = input[j].second;
	
	if(d+b<a) continue;
	if(d>a+b) continue;
	if(d+a<b) {
	  //	  cout<<i<<endl;
	  hougan[i] = true; 
	  continue;
	}
	double theta = acos((a*a+d*d-b*b)/(2*a*d) ) ;
	double dir;
	double x = input[j].first.first - input[i].first.first;
	double y = input[j].first.second - input[i].first.second;
	
	if(abs(y)<EPS && x>0) dir = 0;
	else if(abs(y)<EPS && x<0) dir = PI;
	else {
	  dir = atan(-x/y)+PI/2;
	  if(y<0) dir += PI;
	}
	double start = dir - theta;
	double goal  = dir + theta;
	hosei(start);
	hosei(goal);
	//      	cout<<i<<" "<<j<<" "<<dir<<" "<<theta<<" "<<start<<" "<<goal<<endl;
	kukan[i].push_back(MP(start,1));
	kukan[i].push_back(MP(goal,-1));
	if(goal<start) cntOrigin[i]++ ;
	
      }
  }
  double ans = 0;
  for(int i=0; i<n; i++) {
    if(hougan[i]) {
      //      cout<<i<<endl;
      continue;
    }
    kukan[i].push_back(MP(0,0));
    kukan[i].push_back(MP(2*PI,0));
    sort(kukan[i].begin(), kukan[i].end());
    
    int cnt = cntOrigin[i];
    //    cout<<cnt<<endl;
    double prev = kukan[i][0].first;
    for(int j=1; j<kukan[i].size(); j++) {
      double cur = kukan[i][j].first - prev;
      if(cnt==0) ans += cur * input[i].second ; 
      cnt += kukan[i][j].second;
      prev = kukan[i][j].first;
      //   cout<<kukan[i][j].first<<"  "<<kukan[i][j].second<<endl;
    }
    //    cout<<ans<<endl;
  }
  printf("%.12lf\n",ans);
}


int main() {
  while(1) {
    int n;
    cin>>n;
    if(n==0) break;
    solve(n);
  }
  
  
  
  return 0;
}
