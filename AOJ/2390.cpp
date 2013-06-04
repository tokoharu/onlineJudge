#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;


typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define REP(i,n) for(int i=0;i<(int)n;i++) 
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++) 
#define ALL(c) (c).begin(),(c).end()
const int  MAXN = 10007; 
int parent[MAXN];
bool isBase[MAXN];
void init() {
  REP(i,MAXN){
    parent[i]= i;
    isBase[i] = false;
  }
}
int searchRoot(int v) {
  if(parent[v]==v) return v;
  return parent[v] = searchRoot(parent[v]);
}

int nokori;
int finalAns;

void append(int v,int u,int cost) {
  v = searchRoot(v);
  u = searchRoot(u);
  if(v!=u) {
    if(isBase[u] && isBase[v]) {
      if(nokori==0) {
	return ;
      }
      nokori--;
    }
    finalAns -= cost;
    if(isBase[u]) {
      parent[v] = u;
      return ;
    }
    parent[u] = v;
  }
      
}


bool solve(int caseNum) {
  init();
  int N,T,K;
  cin>>N>>T>>K;
  nokori = T-K-1;
  finalAns = 0;
  if(N==0 && T==0 && K==0)
    return false;
  
  vector<pair<int,PII> > input;
  for(int i=0; i<N-1; i++) {
    int p,q,r;
    scanf("%d%d%d",&p,&q,&r);
    p--;q--;
    input.push_back(MP(r,MP(p,q)));
    finalAns += r;
  }
  REP(i,T) {
    int p;
    scanf("%d",&p);
    p--;
    isBase[p] = true;
  }
  
  
  sort(ALL(input));
  reverse(ALL(input));
  REP(i,N-1) {
    int v = input[i].second.first;
    int u = input[i].second.second;
    int cost = input[i].first;
    append(v,u,cost);
  }
  //  cout<<"Case "<<caseNum<<": "<<finalAns<<endl;
  printf("Case %d: %d\n",caseNum,finalAns);
  
  return true;
}



int main() {
  int i =1;
  while(1) {
    if(!solve(i)) 
      break;
    i++;
  }
  
  return 0;
}
