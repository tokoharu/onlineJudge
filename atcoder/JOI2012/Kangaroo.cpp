#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;
typedef long long LL;
LL MOD = 1000000007;

const int MAXS = 310;
LL dp[MAXS][MAXS];
void solve(vector<int> &A , vector<int> &B , int posA  ,int posB , vector<LL> &res) {
  posA++;
  posB++;
  res.push_back(1);
  for(int i=0; i<=posA+5; i++)
    for(int j=0; j<=posA+5; j++)
      dp[i][j] = 0;
  vector<int> cnt(posA+1,0);
  for(int i=0; i<posA; i++) 
    for(int j=0; j<posB; j++)
      if(A[i]<B[j])
	cnt[i]++;
  reverse(cnt.begin() , cnt.end());
  dp[0][0] = 1;
  for(int i=1 ;i<=posA; i++) {
    LL sum = 0;
    for(int j=0; j<=posA; j++) {
      int t = max(0,cnt[j]+1-i);
      dp[i][j] = sum * (LL)t;
      dp[i][j] %= MOD;
      
      
      sum += dp[i-1][j];
      sum %= MOD;
    }
    LL ans = 0;
    for(int j=0; j<=posA; j++) {
      ans += dp[i][j];
      ans %= MOD;
    }
    res.push_back(ans);
      
  }
}

int main() {
  int n;
  cin>>n;
  vector<int> A;
  vector<int> B;
  for(int i=0; i<n; i++)  {
    int p,q;
    scanf("%d%d",&p,&q);
    A.push_back(p);
    B.push_back(q);    
  }
  sort(A.begin(), A.end());
  sort(B.begin() , B.end());
  vector<int> RA = A , RB = B;
  reverse(RA.begin() , RA.end());
  reverse(RB.begin() , RB.end());
  for(int i=0; i<n; i++) {
    RA[i] = -RA[i];
    RB[i] = -RB[i];
  } 

  LL ans = 0;
  for(int i=0; i<n; i++) {
    int posA = i;
    int posB = n;
    for(int j=0; j<n; j++) {
      if(A[i]<B[j]) {
	posB = j;
	break;
      }
    }
    vector<LL> resX , resY;
    solve(A,B,posA-1,posB-1,resX);
    solve(RB,RA,n-1-posB,n-1-posA-1,resY);
    
    int xsz = resX.size();
    int ysz = resY.size();
    for(int j=0; j<min(xsz,ysz); j++) {
      LL tmp = 1;
      for(int k=0; k<j; k++) {
	tmp *= k+1;
	tmp %= MOD;
      } 
      tmp *= resX[xsz-j-1];
      tmp %= MOD;
      tmp *= resY[ysz-j-1];
      tmp %= MOD;
      ans += tmp;
      ans %= MOD;
    }
  }
  cout<<ans<<endl;
  return 0;
}
