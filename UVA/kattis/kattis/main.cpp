//
//  main.cpp
//  kattis
//
//  Created by ray on 2021/1/28.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<stdio.h>
#include <deque>
#include<iomanip>
#include<queue>
#include<memory.h>
#include<algorithm>
#include<sstream>
#include<string>
#include<math.h>
#include<stack>
#include<map>
#include<vector>
#include<set>
using namespace std;
int p[500005]={0};

int main(int argc, const char * argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long le=0,a[2000][2],ans=0,st;
    int n,c;
    cin>>n>>c;
    st=n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
        if(a[i][0]>0)
        {
            if(st==n)st=i;
        }
        else
        {
            a[i][0]=abs(a[i][0]);
            a[i][1]=abs(a[i][1]);
            ans+=a[i][0]*(a[i][1]/c);
            a[i][1]%=c;
            if(a[i][1]-le>0)
            {
                a[i][1]-=le;
                ans+=a[i][0];
                le=c-a[i][1];
            }
            else
            {
                le-=a[i][1];
            }
        }
    }
    le=0;
    for(int i=n-1;i>=st;i--)
    {
        ans+=a[i][0]*(a[i][1]/c);
        a[i][1]%=c;
        if(a[i][1]-le>0)
        {
            a[i][1]-=le;
            ans+=a[i][0];
            le=c-a[i][1];
        }
        else
        {
            le-=a[i][1];
        }
    }
    cout<<ans*2<<endl;
    return 0;
}
