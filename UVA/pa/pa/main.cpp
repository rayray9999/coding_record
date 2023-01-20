#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
    int a[1005]={0},pri[500],poi=2;
    pri[1]=1;
    for(int i=2;i<=1000;i++)
    {
        if(a[i]==-1)
        {
            continue;
        }
        pri[poi]=i;
        poi++;
        for(int j=i;j*i<=1000;j++)
        {
            a[i*j]=-1;
        }
    }
    int n,c;
    while(cin>>n>>c)
    {
        int ma,st;
        for(int i=1;i<poi;i++)
        {
            if(pri[i]>n)
            {
                ma=i-1;
                break;
            }
        }
        if(n>=997) ma=poi-1;
        cout<<n<<" "<<c<<":";
        if(ma%2==0)
        {
            st=ma/2;
            if(2*c>=ma)
            {
                for(int i=1;i<=ma;i++)
                {
                   
                    cout<<" "<<pri[i];
                }
            }
            else
            {
                for(int i=st-c+1;i<=(st+c);i++)
                {
                    
                    cout<<" "<<pri[i];
                }
            }
        }
        else
        {
            st=ma/2+1;
            if(2*c-1>=ma)
            {
                for(int i=1;i<=ma;i++)
                {
                    
                    cout<<" "<<pri[i];
                }
            }
            else
            {
                for(int i=st-c+1;i<=(st+c-1);i++)
                {
                    
                    cout<<" "<<pri[i];
                }
            }
            
        }
        cout<<endl;
        cout<<endl;
    }
    return 0;
}
