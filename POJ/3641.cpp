/*
POJ3641

素数判定とp^a=p(mod p)の判定を行う

 */


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;

bool isPrime[100000];
vector<int> prime;
void generatePrime(int n) {
  for(int i=0; i<n; i++) isPrime[i] = true;
  isPrime[0] = false;
  isPrime[1] = false;
  for(int i=2; i*i<n; i++ ) for(int j=i; j*i<n; j++) isPrime[i*j] = false;
  for(int i=0; i<n; i++) if(isPrime[i]) prime.push_back(i);
  
}


bool primecheck(LL n) {
  for(int i=0; prime[i]*prime[i]<=n; i++) {
    if(n%prime[i]==0) return false;
    
  }
  return true;

}


LL power(LL a,LL n,LL mod ) {
  if(n==1) return a;
  LL ret = power(a,n/2,mod);
  ret *= ret;
  ret %= mod;
  if(n%2==1) {
    ret *= a;
    ret %= mod;
  }
  return ret;
}


bool solve(LL p,LL a) {
  if(primecheck(p)) return false;
  LL res = power(a,p,p);
  if(res!=a) return false;
  return true;
}
 

int main() {
  generatePrime(100000);
  while(true) {
    LL p,a;
    cin>>p>>a;
    if(p==0 && a==0)
      break;
    bool ok = solve(p,a);
    if(ok) cout<<"yes"<<endl;
    else  cout<<"no"<<endl;
  }
  return 0;
}
