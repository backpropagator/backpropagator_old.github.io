#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)       cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

int main(){
	ll t, n;
	string s;
	cin>>t;
	for(int j=1; j<=t; j++){
		cin>>n;
	    cin>>s;
	    cout<<"Case #"<<j<<": ";
	    for (int i = 0; i < s.length(); ++i)
	    {
	    	if(s[i] == 'S') cout<<"E";
	    	else cout<<"S";
	    }
	    cout<<"\n";
	}

}