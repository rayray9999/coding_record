//
//  main.cpp
//  pc:Mishka and the Last Exam
//
//  Created by ray on 2018/12/15.
//  Copyright © 2018年 ray. All rights reserved.
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
using namespace std;
long long a[200005];
int main(int argc, const char * argv[])
{
    long long n,k;
    cin>>n;
    long long l,b;
    cin>>k;
    l=0;
    b=k;
    a[n]=b;
    for(int i=1;i<=n/2-1;i++)
    {
        cin>>k;
        if(k>b)
        {
            if(k-b<l)
            {
                b=k-l;
            }
            else
            {
                l=k-b;
            }
        }
        else
        {
            b=k-l;
        }
        a[i+1]=l;
        a[n-i]=b;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<a[i];
        if(i!=n) cout<<" ";
    }
    cout<<endl;
    return 0;
}
