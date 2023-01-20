#include <iostream>
using namespace std;
short int p[1001],r[1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    short int t;
    cin>>t;
    while(t)
    {
        bool f=false;
        short int n;
        long long su=1;
        cin>>n;
        for(short int i=1;i<=n;i++)
        {
            cin>>p[i]>>r[i];
        }
        long long int sum=r[1];
        for(short int i=1;i<n&&!f;i++)
        {
            su*=p[i];
            while(sum%p[i+1]!=r[i+1])
            {
                sum+=su;
                if(sum>=955049953)
                {
                    f=true;
                    break;
                }
            }
        }
        if(f==true)
        {
            cout<<"-1"<<"\n";
        }
        else
        {
            cout<<sum<<"\n";
        }
        
        
        
        t--;
    }
    
    return 0;
}
