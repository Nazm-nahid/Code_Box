#include<bits/stdc++.h>

using namespace std;

bool isprime[1000003];
vector <int> prime;

void sieve()
{
    isprime[1]=1;
    for(int i=4;i<=100000;i+=2)isprime[i]=1;

    for(int i=3;i*i<=100000;i+=2)
    {
        if(isprime[i]==0)
        {
            for(int j=i*i;j<=100000;j+=i+i)
        {

            isprime[j]=1;

        }
        }

    }
}




int main()
{
    sieve();

    for(int i=2;i<=100000;i++)
    {
        printf("%d: ",i);
        set<int>ak;
        for(int j=1;j*j<=i;j++)
        {
             if(i%j==0)
             {
                 if(!isprime[j])
                 ak.insert(j);
                if(!isprime[i/j])
                ak.insert(i/j);
             }
        }

        for(auto u: ak){
            printf("%d ",u);
         }
          printf("\n");
    }
    return 0;

}
