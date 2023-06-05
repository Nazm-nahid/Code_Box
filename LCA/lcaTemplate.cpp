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

vector<int>adj[200005];
int level[200005];
int sparse[200005][20];


void dfs(int s,int p)
{
    sparse[s][0] = p;
    for(auto child:adj[s])
    {
        if(child==p) continue;
        level[child] = level[s]+1;
        dfs(child,s);
    }
}

void buildSparseTable(int n)
{
    for(int j=1;j<20;j++)
    {
        for(int i=1;i<=n;i++)
        {
            int par = sparse[i][j-1];
            if(par==0)continue;

            sparse[i][j]= sparse[par][j-1];
        }
    }
}

int lca(int x,int y)
{
    if(level[x]<level[y]) swap(x,y);
    int d = level[x]-level[y];
    int par=x,i=0;

    while(d)
    {
        if(d%2)
        {
            par=sparse[par][i];

        }
        i++;
        d/=2;
    }
    if(y==par) {return y;}
    int a,b;
    a=par,b=y,d=level[y];
    i = 20;
    while(i--)
    {
        if(sparse[a][i-1]!=sparse[b][i-1])
        {
            a=sparse[a][i-1];
            b=sparse[b][i-1];

        }
    }

    par = sparse[a][0];

    return par;

}


int main()
{
    fastio;

        int n; cin>>n;

            int x;

            for(int i=1;i<n;i++)
            {
               cin>>x;
               adj[i+1].pb(x+1);
               adj[x+1].pb(i+1);
               //cout<<i+1<<" "<<x+1<<endl;
            }

            dfs(1,0);
            buildSparseTable(n);


            int m; cin>>m;

            int lc;
           for(int i=0;i<m;i++)
            {
               cin>>x;

               if(i==0) lc = x+1;
               lc= lca(x+1,lc);
            }

            cout<<lc-1<<endl;

    return 0;
}

//https://www.hackerearth.com/problem/algorithm/lowest-common-ancestor/
