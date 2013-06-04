#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;

string trans[10]={
  ".,!? ",
  "abc",
  "def",
  "ghi",
  "jkl",
  "mno",
  "pqrs",
  "tuv",
  "wxyz",""};


void solve() {
  string s;
  cin>>s;
  //  cout<<s<<endl;
  int n = s.size();
  int prev = 0;
  int cnt = 0;
  for(int i=0; i<n; i++) {
    if(s[i]=='0') {
      if(prev!=0) {
	cnt-=1;
	int m = trans[prev-1].size();
	cout<<trans[prev-1][cnt%m];
	//	cout<<m<<endl;
      }
      cnt = 0;
    }
    else {
      cnt++;
    }
    prev = s[i]-'0';
    
  }
  
  cout<<endl;

}


int main() {
  int n;
  cin>>n;
  for(int i=0; i<n; i++) solve();
  
  
}

