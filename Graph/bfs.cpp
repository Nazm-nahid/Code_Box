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


vector<int>v[200003];
int vis[200003],lev[200003],par[200003];

void bfs(int s,int n)
{

    queue<int>q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int parent =q.front();
        q.pop();

        for(auto child: v[parent])
        {
            if(vis[child]==0)
            {
                vis[child]=1;
                q.push(child);
                lev[child]= lev[parent]+1;
                par[child]=parent;
            }
        }
    }

}

int main()
{
    fastio;

            int n,m; cin>>n>>m;
            for(int i=0;i<=n;i++) {vis[i]=0;lev[i]=0;par[i]=-1;}
            for(int i=0;i<=n;i++) v[i].clear();


            for(int i=0;i<m;i++)
            {
               int x,y; cin>>x>>y;
               v[x].pb(y);
               v[y].pb(x);
            }

            bfs(0,n);



    return 0;
}



