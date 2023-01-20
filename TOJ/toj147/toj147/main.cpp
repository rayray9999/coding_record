//
//  main.cpp
//  toj147
//
//  Created by ray on 2019/1/22.
//  Copyright © 2019年 ray. All rights reserved.
//

#include <iostream>
#include<sstream>
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
#include <stdio.h>
using namespace std;
int arr[100005];
int main(int argc, const char * argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,ans=-1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    if(n<=100)
    {
        int a=0,b=1,c=2;
        while(arr[a]+arr[b]<=arr[c])
        {
            if(b-a>1)
            {
                a++;
            }
            else if(c-b>1)
            {
                b++;
            }
            else
            {
                c++;
            }
        }
        ans=arr[a]+arr[b]+arr[c];
    }
    else
    {
    bool anf=false;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i-1]) continue;
        int *po;
        int key,li;
        for(int j=i+1;j<n;j++)
        {
            key=abs(arr[i]-arr[j]);
            li=arr[i]+arr[j];
            if(ans!=-1&&ans<li)
            {
                anf=1;
                break;
            }
            bool f2=false;
            bool f1=false;
            po=upper_bound(arr,arr+n,key);
            while(*po<li&&*po!=0)
            {
                if(ans!=-1&&ans<li+*po) break;
                
                if(*po==arr[i]&&!f1)
                {
                    f1=1;
                }
                else if(*po==arr[j]&&!f2)
                {
                    f2=1;
                }
                else
                {
                    if(ans==-1||ans>li+*po)
                    {
                        ans=li+*po;
                    }
                    break;
                }
                po++;
            }
            
        }
        
        if(anf) break;
    }
    }
    cout<<ans<<endl;
    return 0;
}
