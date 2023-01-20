//
//  main.cpp
//  uva11516(二分搜基地台變形)
//
//  Created by ray on 2019/1/26.
//  Copyright © 2019年 ray. All rights reserved.
//

#include <iostream>
#include <iostream>
#include<sstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include<iomanip>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int arr[100005];
int main(int argc, const char * argv[])
{
    int t,m,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>arr[i];
            arr[i]*=10;
        }
        sort(arr,arr+m);
        int l=0,h=((arr[m-1]+arr[0])/(n+1))+1,d;
        while(l<h)
        {
            if(l==h) break;
            int k=1,r=arr[0];
            d=(l+h)/2;
            r+=d*2;
            for(int i=1;i<m;i++)
            {
                if(arr[i]>r)
                {
                    r=arr[i]+2*d;
                    k++;
                }
            }
            if(k<=n)
            {
                h=d;
            }
            else
            {
                l=d+1;
            }
            
        }
        double ans=l;
        ans=ans/10;
        cout<<fixed<<setprecision(1)<<ans<<endl;
    }
    
    
    
    return 0;
}
