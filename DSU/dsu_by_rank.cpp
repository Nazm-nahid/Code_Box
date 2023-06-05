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

struct DisjointSet {
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int maxSize) {
        parent.resize(maxSize);
        rank.resize(maxSize);
        for (int i = 0; i < maxSize; i++) {
            parent[i] = i;
            rank[i] = 1;
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
            if (rank[a] < rank[b])
                swap(a, b); // marge smaller into bigger
            parent[b] = a;
            rank[a] += rank[b];
        }
    }
};


int main()
{
    fastio;



    return 0;
}







