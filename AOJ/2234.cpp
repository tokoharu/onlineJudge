
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
typedef long long Int;
typedef pair<int,int> PII;
#define MP make_pair
#define REP(i,n) for(int i=0;i<(int)n;i++) 
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++) 
#define ALL(c) (c).begin(),(c).end() 




//最大公約数
//最小公倍数
LL gcd(LL a,LL b){
  return b?gcd(b,a%b):a;
}
LL lcm(LL a,LL b){
  return a/gcd(a,b)*b;
}

LL calcSize(LL a,LL b , LL m , LL n) {
  LL p = m/gcd(a,m);
  LL q = n/gcd(b,n);
  //  cout<<p<<" "<<q<<endl;
  return lcm(p,q);
}


Int extgcd(Int a, Int b, Int &x, Int &y) {
  Int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
bool linearCongruences(const vector<Int> &a,
                       const vector<Int> &b,
                       const vector<Int> &m,
                       Int &x, Int &M) {
  int n = a.size();
  x = 0; M = 1;
  REP(i, n) {
    Int a_ = a[i] * M, b_ = b[i] - a[i] * x, m_ = m[i];
    Int y, t, g = extgcd(a_, m_, y, t);
    if (b_ % g) return false;
    b_ /= g; m_ /= g;
    x += M * (y * b_ % m_);
    M *= m_;
  }
  x = (x + M) % M;
  return true;
}


//true  :  hukumarenai 
//false :  hukumareru
bool check(LL a,LL b,LL c,LL d,LL m,LL n) {
  vector<LL> A ,B,M;
  A.push_back(a);A.push_back(b);
  B.push_back(c);B.push_back(d);
  M.push_back(m);M.push_back(n);
  LL p,q;
  if(linearCongruences(A,B,M,p,q)) return false;
  return true;  
}

bool solveA(LL a, LL b,LL c,LL d,LL m,LL n,LL i) {
  LL x = c*i%m;
  LL y = d*i%n;
  if(check(a,b,x,y,m,n))return true ;
  return false;
}

int main() {
  LL m,n,a,b,c,d;
  cin>>m>>n>>a>>b>>c>>d;
  a %= m , c %= m;
  b %= n , d %= n;

  bool ok = true;
  ok &= check(a,b,c,d,m,n);
  ok &= check(c,d,a,b,m,n);
  
  LL p = calcSize(a,b,m,n);
  LL q = calcSize(c,d,m,n);
  //cout<<p<<" "<<q<<endl;
  LL ans;
  if(ok) {
    LL goal = n*m/p;
    LL minim = goal;
    for(LL i=1; i*i<=goal; i++) if(goal%i==0)  {
	if(!solveA(a,b,c,d,m,n,i)) minim = min(minim,i);
	if(!solveA(a,b,c,d,m,n,goal/i) ) minim = min(minim,goal/i);
    }
    ans = p*minim-1;
  }
  if(!ok) ans = max(p,q)-1;
  cout<<ans<<endl;
 
  return 0;
}
