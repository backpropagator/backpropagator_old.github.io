#include<bits/sdtc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll t, d;
    string p;
    cin>>t;
    for(ll i=1; i<=t; i++){
        cin>>d>>p;
        ll dmg = 0, cur = 1;
        vector<ll> dec;
        ll k=0;
        for(ll j=0; j<p.length(); j++){
            if(p[j] == 'C'){
                cur *= 2;
            }else{
                k++;
                dmg += cur;
            }
            if(j != p.length()-1 && p[j+1] == 'S' && p[j] == 'C'){
                ll tmp = pow(2,j-k);
                dec.push_back(tmp);
            }
        }
        sort(dec.begin(), dec.end(), greater<int>);
        ll r = dmg, cnt=0;
        bool pos = false;
        for (int i = 0; i < dec.size(); ++i)
        {
            if(r <= dmg){
                pos = true;
                break;
            }else{
                r -= dec[i];
            }
        }
        cout<<"Case #"<<i<<": ";
        if(pos){
            cout<<cnt<<"\n";
        }else{
            cout<<"IMPOSSIBLE\n";
        }
    }
}