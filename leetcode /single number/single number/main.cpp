//
//  main.cpp
//  cf.a
//
//  Created by ray on 2020/10/20.
//  Copyright © 2020年 ray. All rights reserved.
//

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
int main(int argc, const char * argv[])
{
    int t;
     cin>>t;
    int prime[150]={0};
    prime[1]=1;
    for(int i=2;i<=13;i++)
    {
        if(prime[i]==0)
        {
            for(int j=2;i*j<=144;j++)
            {
                prime[i*j]=1;
            }
        }
    }
    
    int list[105];
    for(int q=1;q<=t;q++)
    {
        int n,fin1,fin2;
        cin>>n;
        if(n==1)
        {
            cout<<"2"<<endl;
            continue;
        }
        for(int i=0;i<n-2;i++)
        {
            list[i]=1;
        }
        fin1=1;
        fin2=127-(n-1);
        while(prime[fin1]==0||prime[fin2]==0)
        {
            fin1++;
            fin2--;
        }
        list[n-2]=fin1;
        list[n-1]=fin2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<list[(i+j)%n];
                if(j!=n-1)cout<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
