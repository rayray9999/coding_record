#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char * argv[])
{
    int arr[501],n,t;
    cin>>t;
    while(t--)
    {
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        sort(arr+1,arr+n+1);
        for(int i=1;i<=n;i++)
        {
            ans+=abs(arr[i]-arr[(n+1)/2]);
        }
       
        cout<<ans<<endl;
    }
    
    return 0;
}
