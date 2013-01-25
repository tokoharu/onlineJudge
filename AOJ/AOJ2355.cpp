
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
const int MAXN = 300000;
LL kaijo[MAXN];
LL MOD = 1000000007;

void init() {
  LL num = 1;
  kaijo[0] = 1;
  for(LL i=1; i<MAXN; i++) {
    num *= i;
    num %= MOD;
    kaijo[i] = num;
    //   if(i<10) cout<<i<<" "<<num<<endl;
  }

}


LL powMOD(LL n , LL p) {
  if(p==0) return 1;
  LL ret = powMOD(n,p/2);
  ret *= ret;
  ret %= MOD;
  if(p%2==1) ret *= n;
  ret %= MOD;
  return ret;
}

LL frac(LL n) {
  return powMOD(n,MOD-2);
}

LL comb(int n,int m) {
  if(m<=0) return 0;
  if(n<0) return 0;
  if(n<m) return 0;
  LL ret = frac(kaijo[m]) * frac(kaijo[n-m]) % MOD ;
  ret *= kaijo[n];
  ret %= MOD; 
  //  cout<<n<<" "<<m<<" "<<ret<<endl;
  return ret;
}



int main() {
  init();

  int n,m,k;
  cin>>n>>m>>k;

  LL ans = 0;
  for(int i=0; i<n+m+k; i++) {
    int x = i;
    int y = n+m+k-x;
    if(x>=n && y>=m) {
      LL cnt = comb(x+y+k,x+x-n);
      cnt *= comb(x+x-n,x) - comb(x+x-n,x+1);
      cnt %= MOD;
      cnt *= comb(y+y-m,y) - comb(y+y-m,y+1);
      cnt %= MOD;

      ans += cnt + MOD;
      ans %= MOD;
    }
    
  }
  cout<<ans<<endl;
  return 0;
}
