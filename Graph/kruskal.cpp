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

vector< pair< int, pair<int,int> > >v;
int sum=0;

struct DisjointSet {
    vector<int> parent;
    vector<int> Rank;

    DisjointSet(int maxSize) {
        parent.resize(maxSize);
        Rank.resize(maxSize);
        for (int i = 0; i <= maxSize; i++) {
            parent[i] = i;
            Rank[i] = 1;
        }
    }

    int find_set(int v) { // path compression
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b) { // union by rank
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (Rank[a] < Rank[b])
                swap(a, b); // marge smaller into bigger
            parent[b] = a;
            Rank[a] += Rank[b];
        }
    }
};

void kruskal(int n,int m)
{
    DisjointSet d(n);
    sort(all(v));
    for(int i=0;i<v.size();i++)
    {
        pair< int, pair<int,int> > cur = v[i];
        if(d.find_set(cur.second.first)!=d.find_set(cur.second.second))
        {
            sum+=cur.first;
            d.union_set(cur.second.first, cur.second.second);
        }
    }
}

int main()
{
    fastio;

            int n,m; cin>>n>>m;


            int x,y,z;

            for(int i=0;i<m;i++)
            {
               cin>>x>>y>>z;
               v.pb({z,{x,y}});
            }

            kruskal(n,m);

            cout<<sum<<endl;


    return 0;
}

/* Test Input
    6 9
    1 2 9
    1 6 6
    2 4 2
    2 3 14
    3 4 9
    3 5 1
    4 5 10
    4 6 11
    5 6 15
*/








