#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

int U[24] , R[24] , L[24] ,D[24] ,F[24] ,B[24];

string ans = "rrrrggyybbwwggyybbwwoooo";

void print() {
  cout<<".."<<ans.substr(0,2)<<"...."<<endl;
  cout<<".."<<ans.substr(2,2)<<"...."<<endl;
  cout<<ans.substr(4,8)<<endl;
  cout<<ans.substr(12,8)<<endl;
  cout<<".."<<ans.substr(20,2)<<"...."<<endl;
  cout<<".."<<ans.substr(22,2)<<"...."<<endl;
}

int main() {
  string s;
  cin>>s;
  for(int i=0; i<24; i++) {
    U[i] = D[i] = R[i] = L[i] = F[i] = B[i] = i;
  }
  for(int i=0; i<8; i++) {
    U[i+4] = (i+2)%8 + 4; 
    D[i+12] = (i+6)%8 + 12;
  }
  /*  U[2]=0 , U[0]=1 , U[1]=3, U[3]=2;*/
  U[0]=2, U[2]=3, U[3]=1, U[1]=0;
  D[20]=22, D[22]=23 , D[23]=21, D[21]=20;
  
  F[2]=13 , F[13]=21, F[21]=8 , F[8]=2;
  F[3]=5 , F[5]=20, F[20]=16, F[16]=3;
  F[6]=14, F[14]=15, F[15]=7, F[7]=6;
  
  R[8]=16, R[16]=17, R[17]=9, R[9]=8;
  R[23]=10, R[10]=3, R[3]=15, R[15]=23;
  R[21]=18, R[18]=1, R[1]=7, R[7]=21;
  
  L[4]=12, L[12]=13, L[13]=5, L[5]=4;
  L[0]=19, L[19]=20, L[20]=6,L[6]=0;
  L[2]=11, L[11]=22, L[22]=14, L[14]=2;
  
  B[18]=19,B[19]=11, B[11]=10, B[10]=18;
  B[9]=23, B[23]=12, B[12]=0, B[0]=9;
  B[17]=22, B[22]=4, B[4]=1, B[1]=17;
  

  for(int i=0; i<s.size(); i++) {
    string tmp;
    tmp = ans;
    if(s[i]=='U') 
      for(int i=0; i<24; i++)
	tmp[i] = ans[U[i]];
    
    if(s[i]=='D') 
      for(int i=0; i<24; i++)
	tmp[i] = ans[D[i]];

    if(s[i]=='F') 
      for(int i=0; i<24; i++)
	tmp[i] = ans[F[i]];

    if(s[i]=='B') 
      for(int i=0; i<24; i++)
	tmp[i] = ans[B[i]];

    if(s[i]=='R') 
      for(int i=0; i<24; i++)
	tmp[i] = ans[R[i]];

    if(s[i]=='L') 
      for(int i=0; i<24; i++)
	tmp[i] = ans[L[i]];
    ans = tmp;
    //     print();
  }
  
  print();
  
  return 0;
}
/*
... .0 1
.... 2 3
 4 5 6 7 8 91011
1213141516171819
....2021
....2223
 */
