//
//  main.cpp
//  uva10370
//
//  Created by ray on 2018/12/13.
//  Copyright © 2018年 ray. All rights reserved.
//
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int arr[1005];
int main(int argc, const char * argv[])
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int a;
        double sum=0,p=0;
        cin>>a;
        memset(arr,0,sizeof(arr));
        for(int j=1;j<=a;j++)
        {
            int k;
            cin>>k;
            arr[j]=k;
            sum=sum+k;
        }
        sum=sum/a;
        sort(arr+1,arr+a+1);
        for(int j=a;j>0;j--)
        {
            if(arr[j]<=sum)
            {
                break;
            }
            p=p+1;
        }
        p=(p/a)*100;
        cout<<fixed<<setprecision(3)<<p<<"%"<<endl;
        
    }
   
    return 0;
}
