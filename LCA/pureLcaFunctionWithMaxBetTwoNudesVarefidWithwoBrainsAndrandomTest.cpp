#include<bits/stdc++.h>
#define ll long long
#define llu unsigned long long
#define pb push_back
#define f(n) for(ll i=0;i<n;i++)
#define ina for(ll i=0;i<n;i++)cin>>a[i];
#define all(v) v.begin(),v.end()
#define YES prllf("YES\n")
#define NO prllf("NO\n")
#define fastio std::ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
vector<ll>tree[200005];
vector<pair<ll,ll> >treeWithWeight[200005];
ll sparse[21][200005];
ll sparseMax[21][200005];
ll level[200005];

void dfsSparse(ll s, ll p)
{
    sparse[0][s]=p;
    level[s]= level[p]+1;
    for(ll x: tree[s])
    {
        if(x==p)
            continue;
        dfsSparse(x,s);
    }

}

void dfsSparseWithWeight(ll s, ll p)
{
    for(auto x: treeWithWeight[s])
    {
        ll child = x.first;
        ll weight = x.second;
        if(child==p)
            continue;
        sparseMax[0][child]= weight;
        dfsSparseWithWeight(child,s);
    }

}

void buildSparseTable(ll n,ll s=1,ll p=0)
{
    dfsSparse(s,p);
    for(ll j=1; j<=20; j++)
        for(ll i=1; i<=n; i++)
        {
            ll par = sparse[j-1][i];
            sparse[j][i]= sparse[j-1][par];
        }
}

void buildMaxWeightSparseTable(ll n,ll s=1,ll p=0)
{
    buildSparseTable(n);
    dfsSparseWithWeight(s,p);
    for(ll j=1; j<=20; j++)
        for(ll i=1; i<=n; i++)
        {
            ll par = sparse[j-1][i];
            if(!sparse[j][i])
                continue;
            sparseMax[j][i]= max(sparseMax[j-1][i],sparseMax[j-1][par]);
        }
}

ll findNthParentFromSparse(int node, int n)
{
    for(int i=0; i<=20; i++)
    {
        if(n & (1<<i))
        {
            node = sparse[i][node];
        }
    }
    return node;
}

ll findMaxWeightNthParentFromSparse(int node, int n)
{
    ll mx=0;
    for(int i=0; i<=20; i++)
    {
        if(n & (1<<i))
        {
            mx=max(mx,sparseMax[i][node]);
            node = sparse[i][node];
        }
    }
    return mx;
}

ll findLca(int a,int b)
{
    if(level[a]<level[b])
        swap(a,b);
    ll d = level[a]-level[b];
    a= findNthParentFromSparse(a,d);

    if(a==b)
        return a;

    for(int i=20; i>=0; i--)
    {
        if(sparse[i][a]!=sparse[i][b])
        {
            a = sparse[i][a];
            b = sparse[i][b];
        }
    }
    return sparse[0][a];

}

ll findMaxWeightBetweenTwoNodes(ll x,ll y)
{
    ll lca = findLca(x,y);
    ll n1 = level[x]-level[lca];
    ll mx1 = findMaxWeightNthParentFromSparse(x,n1);
    ll n2 = level[y]-level[lca];
    ll mx2 = findMaxWeightNthParentFromSparse(y,n2);
    cout<<n1<<" "<<n2<<" "<<mx1<<" "<<mx2<<endl;
    return max(mx1,mx2);
}

int main()
{
    fastio;

    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        tree[x].pb(y);
        tree[y].pb(x);
        treeWithWeight[x].pb({y,z});
        treeWithWeight[y].pb({x,z});
    }
    //buildSparseTable(n);
    buildMaxWeightSparseTable(n);

    return 0;
}

/*
6 7
1 2 1
2 3 2
2 4 6
4 5 4
5 6 5
1 5 10
4 6 10
*/
/*
6 6
1 2 1
2 3 2
3 4 6
4 5 4
5 6 5
1 5 10
*/
/*
4 6
1 2 1
1 3 2
1 4 3
2 3 4
2 4 5
3 4 6
*/
/*
9 8
1 2
2 3
1 4
1 6
6 5
4 7
7 8
8 9
*/
/*
11 10
1 2 2
2 3 4
1 4 1
1 6 2
6 5 3
4 7 2
7 8 7
8 9 3
4 10 6
10 11 4
*/




