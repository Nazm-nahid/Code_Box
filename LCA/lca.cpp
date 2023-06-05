#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define f(n) for(ll i=0;i<n;i++)
#define ina for(ll i=0;i<n;i++)cin>>a[i];
#define all(v) v.begin(),v.end()
#define YES printf("YES\n")
#define NO printf("NO\n")
#define fastio std::ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
/*speedup
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
using namespace std;

ll par[1005],vis[1005];

int lca(int x, int y, int n){

	for(int i=1;i<=n;i++) vis[i] = 0;

	vis[x] = 1;

	while(par[x]!=x){
		vis[x] = 1;
		x = par[x];
	}

	vis[x] = 1;

	while(vis[y]!=1) y = par[y];

	return y;
}

int main(){
	ll t,cs=0;
	ll n,m,q,x,y,i,j,k;
	cin>>t;
	while(t--){
		cout<<"Case "<<++cs<<":"<<endl;
        cin>>n;
		for(i=1;i<=n;i++) par[i] = i;

		for(i=1;i<=n;i++){
			cin>>m;
			for(j=0;j<m;j++){
				cin>>x;
				par[x] = i;
			}
		}
		cin>>q;
		while(q--){
			cin>>x>>y;
			cout<<lca(x,y,n)<<endl;
		}
	}
	return 0;
}
