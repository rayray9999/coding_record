//
//  main.cpp
//  BIT
//
//  Created by ray on 2021/1/28.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<algorithm>
using namespace std;
int a[100005],b[100005];
long long bit[100005];
long long bbit[100005];
int n;
void add(long long *r,int k,long long pl)
{
    while(k<=n)
    {
        r[k]+=pl;
        k+=k&-k;
    }
}
long long sum(long long *r,int k)
{
    long long s=0;
    while(k>0)
    {
        s+=r[k];
        k-=k&-k;
    }
    return s;
}
int main(int argc, const char * argv[])
{
    long long ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    long long l=unique(b,b+n)-b;
    for(int i=0;i<n;i++)
    {
        a[i]=lower_bound(b,b+l,a[i])-b+1;
    }
    
    for(int i=0;i<n;i++)
    {
        add(bit,a[i],1);
        long long o=sum(bit,n)-sum(bit,a[i]);
        add(bbit,a[i],o);
        ans=ans+sum(bbit,n)-sum(bbit,a[i]);
    }
    cout<<ans<<endl;
    return 0;
}
