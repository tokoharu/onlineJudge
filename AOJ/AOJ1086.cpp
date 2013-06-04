#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<utility>
#include<algorithm>

using namespace std;

int E[20][40];
int F[20][40];

int dp[35][55][7];

bool solve() {
  int C,D,W,X;
  cin>>C>>D>>W>>X;
  //  cout<<C<<" "<<D<<" "<<W<<" "<<X<<endl;
  if(C==0 && D==0 && W==0 && X==0) 
    return false;
  for(int i=0; i<C; i++) {
    for(int j=0; j<D; j++)
      cin>>E[i][j];
    
  }
  for(int i=0; i<C; i++)
    for(int j=0; j<D; j++)
      cin>>F[i][j];

  for(int i=0; i<35; i++)
    for(int j=0; j<55; j++)
      for(int k=0; k<7; k++)
	dp[i][j][k] = -1000000000;
  dp[0][W][0] = 0;
  for(int day=0; day<D; day++) {
    for(int x=0; x<=X; x++) 
      for(int w=0; w<=W; w++)
	dp[day+1][w][x] = dp[day][w][x];
    for(int x=0; x<=X; x++) {
      for(int city=0; city<C; city++) {
	if(E[city][day]!=0) {
	  for(int w=F[city][day]; w<=W; w++) {
	    dp[day+1][w-F[city][day]][x] = max(dp[day+1][w-F[city][day]][x]  , dp[day][w][x] + E[city][day]);
	  }
	}
      }
      for(int cityA=0; cityA<C; cityA++) {
	int sumE = 0;
	int sumF = 0;
	for(int cityB=cityA; cityB<C; cityB++) {
	  if(E[cityB][day]==0) break;
	  sumE += E[cityB][day];
	  sumF += F[cityB][day];
	  for(int w=sumF; w<=W; w++) {
	    dp[day+1][w-sumF][x+1] = max(dp[day+1][w-sumF][x+1] , dp[day][w][x] + sumE);
	  }
	}
      }
    }
  }
  int ans = 0;
  for(int day=0; day<=D; day++)
    for(int w=0; w<=W; w++)
      for(int x=0; x<=X; x++) 
	ans = max(ans , dp[day][w][x]);
  cout<<ans<<endl;
  
  return true;
}

int main() {
  while(1)  if(!solve()) break;
  return 0;
}

