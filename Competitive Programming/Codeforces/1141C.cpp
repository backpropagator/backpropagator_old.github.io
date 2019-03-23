#include <bits/stdc++.h>
#define FASTIO
#define endl "\n" // Since endl forces a buffer flush which slows down large I/O operations.
#define ff first
#define ss second
#define pb push_back
#define input(c, n)             \
	for (int i = 0; i < (n); i++) \
		cin >> (c)[i];
#define exit_message(s) return 0 * printf(s)
#define show(c)           \
	for (auto i : (c))      \
		cout << i << " "; \
	cout << "\n";
#define display(c, n)           \
	for (int i = 0; i < (n); i++) \
		cout << (c)[i] << " ";    \
	cout << "\n";
#define forl(i, a, n) for (int (i) = (a); (i) < (n); (i)++)
#define dugbe(k) cout << "-\t> " << #k << " = " << k << "\n";

/* TIPS FOR DEBUGGING
 * Check if values are not overflowing (use long long where required)
 * Check if ranges are inclusive or not.
 * Check properly if greedy will work or not before using it.
 * Check EDGE CASES!! Seriously, even in 2B, saving 8 points by being
 * 2 minutes faster will bite you in the ass if you don't make sure
 * it works on edge cases.
 * Keep adding to this list.
*/

using namespace std;
typedef long long ll;
typedef pair<int, int> pr;
typedef pair<ll, ll> prll;
typedef vector<int> vi;
typedef vector<ll> vill;
typedef vector<pr> vpr;
ifstream in("input.txt");
const ll mod = 1e9 + 7;
const int N = 1e5 + 5;
const long double eps = 1e-7;

ll mod_pow(ll a, ll b)
{
	if (b == 0)
		return 1LL;

	ll res = mod_pow(a, b >> 1);
	res = (res * res) % mod;
	if (b & 1LL)
		res = (res * a) % mod;

	return res;
}

vector<char> seive(ll n){
	vector<char> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
    	if (is_prime[i]) {
        	for (int j = i * i; j <= n; j += i)
            	is_prime[j] = false;
    	}
	}
	return is_prime;
}

int32_t main()
{
#ifdef FASTIO
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#endif
	// freopen("in.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ll n;
	cin>>n;
	ll q[n-1], v[n-1];
	ll s = 0;
	for (int i = 0; i < n-1; ++i)
	{
		cin>>q[i];
		s += q[i];
	}
	ll sv = 0;
	for (int i = 0; i < n-1; ++i)
	{
		v[i] = s;
		s -= q[i];
		sv += v[i];
	}
	ll p[n];

	p[n-1] = (sv + ((n*(n+1))/2));
	p[n-1] /= n;
	ll t = p[n-1];
	bool pos = true;

	if((t*n - sv) != ((n*(n+1))/2)) pos = false;

	for (int i = 0; i < n-1; ++i)
	{
		p[i] = t - v[i];
		//cout<<p[i]<<" ";
		if(p[i] <= 0){ pos = false;
			break;}
	}
	/*cout<<p[n-1];
	cout<<"\n";*/
	if(pos){
		for (int i = 0; i < n; ++i)
		{
			cout<<p[i]<<" ";
		}
		cout<<"\n";
	}else{
		cout<<"-1"<<"\n";
	}

	return 0;
}