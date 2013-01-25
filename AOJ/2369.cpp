#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;

string Replace( string &String1, string String2,string String3 )
{
  std::string::size_type  Pos( String1.find( String2 ) );
  
  while( Pos != std::string::npos )
    {
        String1.replace( Pos, String2.length(), String3 );
        Pos = String1.find( String2, Pos + String3.length() );
    }
  
  return String1;
}

int main() {
  string s;
  cin>>s;
  while(1) {
    int p = s.size();    

    Replace(s,"mew","x");
    Replace(s,"mxew","x");
    Replace(s,"mexw","x");
    Replace(s,"mxexw","x");
    
    
    int q = s.size();
    if(p==q) break;
  }
  if(s=="x") cout<<"Cat"<<endl;
  else       cout<<"Rabbit"<<endl;
  return 0;
  
}
