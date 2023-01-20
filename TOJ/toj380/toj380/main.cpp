#include<iostream>
using namespace std;
long long arr[33][1025];
int main()
{
    int a;
    cin>>a;
    arr[0][0]=1;
    for(int i=1;i<=a;i++)
    {
        int sum=0,w,n;
        for(int j=10;j>=0;j--)
        {
            int g;
            cin>>g;
            if(j==10)
            {
                w=g;
                n=1<<(g-1);
            }
            else
            {
                sum=sum+(g<<j);
            }
        }
        for(int j=30;j>=0;j--)
        {
           if((j>>(w-1))%2!=1)
           {
               for(int k=1023;k>=0;k--)
               {
                   if(arr[j][k]>0) arr[j|n][k|sum]=(arr[j|n][k|sum]+arr[j][k])%1000000007;
               }
           }
            
        }
    }
    
    cout<<arr[31][1023]<<endl;
    
    return 0;
}
