#include<iostream>
using namespace std;
int pri[10000005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ti;
    cin>>ti;
    pri[1]=1;
    for(long long i=2;i<=10000004;i++)
    {
        if(pri[i]==0)
        {
            for(long long j=i+i;j<=10000004; j+=i)
            {
                
                pri[j]=i;
                
            }
            pri[i]=i;
        }
    }
    for(int i=1;i<=ti;i++)
    {
        int co,pr1,pr2;
        cin>>co;
        pr1=pri[co];
        while((co/pr1)*pr1==co)
        {
            co=co/pr1;
        }
        pr2=pri[co];
        cout<<pr2<<" "<<pr1<<endl;
    }
    
    return 0;
}
