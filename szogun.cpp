#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) cout << #x << " = " << x << endl;
#define vc vector
#define pii pair<int,int> 
#define pll pair<ll,ll> 

const ll mod = 998244353;

void dfs(int &v, vc<int> &l, vc<int> &r, vc<ll> &dp)
{
	if(v==-1) return;
	dfs(l[v], l, r, dp);
	dfs(r[v], l, r, dp);
	ll lf=(l[v]==-1)? 1: ((dp[l[v]] +1)%mod);
	ll rg=(r[v]==-1)? 1:((dp[r[v]] +1)%mod);
	dp[v]=(lf*rg)%mod;
	
}
void solve()
{
    int n;
    cin >> n;

    vc<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    vc<int> par(n,-1);
    vc<int> r(n,-1);
    vc<int> l(n,-1);
    stack<int> stk;

    for(int i=0; i<n; ++i)
    {
        int last=-1;
        while(not stk.empty() and a[stk.top()]>a[i])
        {
            last=stk.top();
            stk.pop();
        }

        if(not stk.empty())
        {
            par[i]=stk.top();
            r[stk.top()]=i;
        }

        if(last!=-1)
        {
            par[last]=i;
			l[i]=last;
        }
		
    }

	int root=0;
	for(int i=0; i<n; ++i) 
		if(par[i]==-1) root=i;

	vc<ll> dp(n,1);
	dfs(root, l,r,dp);
	cout << dp[root]%mod;
}

int main() 
{
    fast;
    int t=1;
    //cin >> t;
    while(t--) 
    solve();
    return 0;
}
