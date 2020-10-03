#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll mark[1006]={0};
ll primeary[1006];

void prime ()
{
    int k=0;
    int i, j,sizee=sqrt(1006);
    for(i=3;i<=sizee;i++)
        for(j=i*i;j<=1006;j+=2*i)
        {
            mark[j]=1;
        }
        primeary[k]=1;
        primeary[++k]=2;
        for(i=3;i<1006;i+=2)
            if(mark[i]==0)
            primeary[++k]=i;

}


int main()
{
    int t,n,p;
    prime();
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;

        for(int j=0;primeary[j] <=n && primeary[j]!=0;j++)
            cout<<primeary[j]<<endl;
        cout<<endl;
    }

}
