#include<iostream>
#include<cstdio>
#include<cmath>
#include<utility>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> PII;
#define MP make_pair

LL calc(LL med) {
  LL t = med/2;
  return t*t+t*(med%2);
}

LL MOD = 1000000007;

PII fibCalc(LL a) {
  if(a==0) return MP(1,0);
  if(a==1) return MP(1,1);
  PII k = fibCalc(a/2);
  PII ret ;
  ret.first = k.first*k.first + k.second*k.second;
  ret.second = k.first*k.first - (k.first-k.second) * (k.first-k.second) ;
  ret.first %= MOD;
  ret.second %= MOD;
  ret.first += MOD;
  ret.second += MOD;
  ret.first %= MOD;
  ret.second %= MOD;
  if(a%2==1) {
    swap(ret.first , ret.second);
    ret.first += ret.second;
    ret.first %= MOD;
  }
  //  cout<<a<<" "<<ret.first<<" "<<ret.second<<endl;
  return ret;
 }

LL fib(LL a) {
  PII k = fibCalc(a) ;
  return k.first;
}


int main() {
  LL k;
  cin>>k;
  if(k<=5) {
    cout<<k<<endl;
    return 0;
  }
  LL left = 0;
  LL right = 2000000000;
  while(left+1<right) {
    LL med = left+right;
    med /= 2;
    LL tmp = calc(med);
    if(tmp<k)left = med;
    else right = med;
  }
  LL sum = right;
  LL p = k-calc(left);
  LL range = calc(right) - calc(left);
   cout<<sum<<" "<<p<<" "<<range<<endl;
  LL a,b;
  if((p-1)*2<range)a = p*2-1;
  else a = (range-p)*2+2;
  b = sum-a;  
  //   cout<<a<<" "<<b<<endl;
  LL ans = fib(a) * fib(b) % MOD;
  cout<<ans<<endl;

  return 0;
  
}
