#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
    /* Basic types */
    typedef long long           ll;
    typedef long double         ld;
    typedef unsigned long long ull;
    /* STL containers */
    typedef vector <int>    vi;
    typedef vector <ll>     vll;
    typedef pair <int, int> pii;
    typedef pair <ll, ll>   pll;
    typedef vector < pii >  vpii;
    typedef vector < pll >  vpll;
    typedef vector <string> vs;
    typedef vector < vi >   vvi;
    typedef vector < vll >  vvll;
    typedef vector < vpii > vvpii;
    typedef set <int>       si;
/* Macros */
    /* Loops */
    #define fl(i, a, b)     for(int i(a); i <= (b); i ++)
    #define rep(i, n)       fl(i, 1, (n))
    #define loop(i, n)      fl(i, 0, (n) - 1)
    #define rfl(i, a, b)    for(int i(a); i >= (b); i --)
    #define rrep(i, n)      rfl(i, (n), 1)
    /* Algorithmic functions */
    #define srt(v)          sort((v).begin(), (v).end())
    /* STL container methods */
    #define pb              push_back
    #define mp              make_pair
    #define eb              emplace_back
    /* String methods */
    #define dig(i)          (s[i] - '0')
    #define slen(s)         s.length()
    /* Shorthand notations */
    #define fr              first
    #define sc              second
    #define re              return 
    #define sz(x)           ((int) (x).size())
    #define all(x)          (x).begin(), (x).end()
    #define sqr(x)          ((x) * (x))
    #define fill(x, y)      memset(x, y, sizeof(x))
    #define clr(a)          fill(a, 0)
    #define endl            '\n'
    /* Mathematical */
    #define IINF            0x3f3f3f3f
    #define LLINF           1000111000111000111LL
    #define PI              3.14159265358979323
    /* Debugging purpose */
    #define trace1(x)                cerr << #x << ": " << x << endl
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
    /* Fast Input Output */
    #define high_functioning_sociopath                  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
/* Constants */
    const ll MOD = 1000000007LL;
    const ll MAX = 100010LL;
/* Templates */

template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; x %= m; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

vvll adj(205);
queue<ll> q;
int vis[205];
bool pos;
ll xtr;


void bfs(ll x){
        pos = 1;
        if(adj[x].size() == 0){
            //cout<<x<<" ";
            xtr++;
            return;
        }
        q.push(x);
        vis[x] = 0;
        //pos = 1;
        while(!q.empty() && pos){
            ll c = q.front();
            q.pop();
            //if(q.empty()) continue;
            //if(adj[c].size() == 0) continue;
            for (int i = 0; i < adj[c].size(); ++i)
            {
                if(vis[adj[c][i]] == -1){
                    vis[adj[c][i]] = 1-vis[c];
                    q.push(adj[c][i]);
                }
                else if(vis[adj[c][i]] == vis[c]){
                    pos = false;
                    break;
                }
            }
        }
}

void clearq()
{
   while(!q.empty()) q.pop();
}

int main(){

    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif*/

    high_functioning_sociopath;    

    ll t, v, e, a, b;
    cin>>t;
    while(t--){
        cin>>v>>e;
        //q.clear();
        //for (int i = 0; i < q.size(); ++i) q.pop();
        clearq();
        xtr = 0;
        for (int i = 0; i < 205; ++i) adj[i].clear();
        //vvll adj(v);
        for (int i = 0; i < e; ++i)
        {
            //cout<<"j\n";
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        //int vis[v];
        memset(vis,-1,sizeof vis);
        //queue<ll> q;
        
        for (int i = 0; i < v; ++i)
        {
            if(vis[i] == -1){
                bfs(i);
                if(!pos) break;
            }
        }

        ll cnt1 = 0, cnt0 = 0;
        if(!pos) cout<<-1<<"\n";
        else{
            // ll cnt1 = 0, cnt0 = 0;
            for (int i = 0; i < v; ++i)
            {
                if(vis[i] == 0) cnt0++;
                if(vis[i] == 1) cnt1++;
            }
            cout<<min(cnt1,cnt0)+xtr<<"\n";
        }
        //cout<<min(cnt1,cnt0)<<"\n";
    }
    

    return 0;
}
