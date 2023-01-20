//
//  main.cpp
//  uva11876(埃式篩)
//
//  Created by ray on 2019/1/27.
//  Copyright © 2019年 ray. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#define maxn  1000000
using namespace std;
int pri[maxn+5],arr[maxn+5];
int main(int argc, const char * argv[])
{
    
    for(int i=1;i<=maxn;i++)
    {
        for(int j=i;j<=maxn;j+=i) pri[j]++;
    }
    arr[1]=1;
    for(int i=2;i<=maxn;i++)
    {
        
        arr[i]=arr[i-1]+pri[arr[i-1]];
    }
    int a;
    cin>>a;
    for(int i=1;i<=a;i++)
    {
        int d,k;
        cin>>d>>k;
        int *c,*b;
        b=lower_bound(arr+1, arr+maxn,d);
        c=lower_bound(arr+1, arr+maxn,k);
        int a=c-b;
        if(*c==k) a++;
        cout<<"Case "<<i<<": "<<a<<endl;
    }
    
    
    return 0;
}
