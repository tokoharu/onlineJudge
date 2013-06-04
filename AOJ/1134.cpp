#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++) 

vector<string> partition(string s) {
  //  int pos = s.search("-");
  int pos = 0;
  for(int i=0; i<s.size(); i++) if(s[i]=='-') pos = i;
  vector<string> res;
  res.push_back(s.substr(0,pos));
  res.push_back(s.substr(pos+1, s.size()-pos-1));
  
  return res;
}

const int MAXN = 308;
vector<int> next[MAXN];
vector<int> prev[MAXN];
bool inequall[MAXN][MAXN];
int dist[MAXN][MAXN];
bool isStrong[MAXN][MAXN];


bool solve() {
  for(int i=0; i<MAXN ; i++) {
    next[i].clear();
    prev[i].clear();
    for(int j=0; j<MAXN; j++ ) {
      inequall[i][j] = false;
      dist[i][j] = 1000000;
      isStrong[i][j] = false;
    }
    
  }
 
  int n;
  cin>>n;
  if(n==0) return false;
  
  vector<string> input[2];
  set<string> street;
  map<string,int> index;
  for(int i=0; i<n; i++) {
    string s;
    cin>>s;
    //    cout<<s<<endl;
    vector<string> t = partition(s);
    //        cout<<t[0]<<" "<<t[1]<<endl;
    street.insert(t[0]);
    street.insert(t[1]);
    input[0].push_back(t[0]);
    input[1].push_back(t[1]);
  }
  {
    int iter = 0;
    EACH(i,street) {
      index[*i] = iter;
      iter++;
    }
  }
  for(int i=0; i<n; i++) {
    string s = input[0][i];
    string t = input[1][i];
    int A = index[s];
    int B = index[t];
    
    prev[B].push_back(A);
    next[A].push_back(B);
    dist[A][B] = dist[B][A] = 1; 
    
    isStrong[A][B] = true;
  }
  int m = index.size();
  
  for(int j=0; j<m; j++)
    for(int i=0; i<m; i++)
      for(int k=0; k<m; k++)
	dist[i][k] = min(dist[i][j] + dist[j][k] , dist[i][k]);
    
  for(int i=0; i<m; i++) {
    for(int j=0; j<prev[i].size(); j++) {
      for(int k=0; k<next[i].size();k++) {
	int A = prev[i][j];
	int B = next[i][k];
	inequall[A][B] = true;
	inequall[B][A] = true;
	
      }
    }
  } 
  for(int i=0; i<m; i++) {
    for(int j=0; j<m; j++) {
      if(dist[i][j]==2) {
	if(!inequall[i][j]) {
	  isStrong[i][j] = true;
	  isStrong[j][i] = true;
	}
      }
    }
  }
  for(int j=0; j<m; j++)
    for(int i=0; i<m; i++)
      for(int k=0; k<m; k++)
	isStrong[i][k] |= isStrong[i][j] & isStrong[j][k];
  
  int q;
  cin>>q;
  cout<<m<<endl;
  for(int i=0; i<q; i++) {
    string s;
    cin>>s;
    vector<string> data = partition(s);
    bool x = false,y = false;
    for(int iter=0; iter<n; iter++) {
      if(input[0][iter]==data[0] || data[0] == input[1][iter])
	x = true;
      if(input[0][iter]==data[1] || data[1] == input[1][iter])
	y = true;
    }
    if(!x || !y) {
      cout<<"NO"<<endl;
      continue;
    }   

    int A = index[data[0]];
    int B = index[data[1]];
    if(dist[A][B]%2==1 && isStrong[A][B]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
  }
  
  
  return true;
  
}

int main() {
  while(1) 
    if(!solve()) 
      break;
  return 0;
}
