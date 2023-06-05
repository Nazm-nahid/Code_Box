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

vector<pair<int,int> >v[200003];
vector<pair<int,int> >ans[200003];
int dist[200003];


void kruskal(int s,int n)
{

    priority_queue< pair< int,int> >q;
    q.push({0,s});
    dist[s]=0;
    while(!q.empty())
    {

        int parent =q.top().second;
        int parentDist = dist[q.top().second];
        q.pop();

        for(auto child: v[parent])
        {
            if( dist[child.first]> (parentDist+child.second) )
            {
                dist[child.first]= parentDist+child.second;
                q.push({child.second,child.first});
            }
        }
    }

}

int main()
{
    fastio;

            int n,m; cin>>n>>m;
            for(int i=0;i<=n;i++) {dist[i]=INT_MAX;}
            for(int i=0;i<=n;i++) v[i].clear();

            int x,y,z;

            for(int i=0;i<m;i++)
            {
               cin>>x>>y>>z;
               v[x].pb({y,z});
               v[y].pb({x,z});
            }

            dijkstra(1,n);
            for(int i=1;i<=n;i++) cout<<dist[i]<<" "; cout<<endl;

    return 0;
}
