#include<bits/stdc++.h>
#define ll long long
#define llu unsigned long long
#define pb push_back
#define f(n) for(ll i=0;i<n;i++)
#define ina for(ll i=0;i<n;i++)cin>>a[i];
#define all(v) v.begin(),v.end()
#define YES printf("YES\n")
#define NO printf("NO\n")
#define fastio std::ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;


vector<int>v[2003];
int vis[2003],in[2003],low[2003];
int t=0;

void dfs(int s,int p)
{
    vis[s]=1;
    in[s]=low[s]=t;
    t++;
    for(int child: v[s])
        {
            if(child==p) continue;
            if(vis[child]==1)
            {
                low[s]= min(low[s],in[child]);
            }
            else
            {
                dfs(child,s);
                if(low[child]>in[s]) cout<<s<<"-"<<child<<" is a bridge"<<endl;
                low[s]= min(low[s],low[child]);
            }
        }

}

int main()
{
    fastio;

            int n,m; cin>>n>>m;

            for(int i=0;i<m;i++)
            {
               int x,y; cin>>x>>y;
               v[x].pb(y);
               v[y].pb(x);
            }

            dfs(1,-1);

    return 0;
}




