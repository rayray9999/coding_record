//
//  main.cpp
//  B. Ehab and subtraction
//
//  Created by ray on 2018/12/8.
//  Copyright © 2018年 ray. All rights reserved.
//

#include <iostream>
#include<algorithm>
using namespace std;
int li[100005];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>li[i];
    }
    sort(li+1,li+n+1);
    long long sum=li[1];
    cout<<li[1]<<endl;
    k--;
    for (int i=2;i<=n;i++)
    {
        if(k==0)
        {
            break;
        }
        if(sum<li[i])
        {
            cout<<li[i]-sum<<"\n";
            sum=li[i];
            k--;
        }
        
    }
    for(int i=1;i<=k;i++)
    {
        cout<<"0"<<"\n";
    }
    return 0;
}
