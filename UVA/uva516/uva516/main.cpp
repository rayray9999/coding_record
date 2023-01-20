//
//  main.cpp
//  uva516
//
//  Created by ray on 2020/9/28.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[])
{
    int a[33000]={0};
    a[1]=-1;
    for(int i=2;i<=sqrt(33000);i++)
    {
        if(a[i]==-1) continue;
        for(int j=i;i*j<=33000;j++)
        {
            a[i*j]=-1;
        }
    }
    string s;
    stringstream ss;
    while(getline(cin,s))
    {
        if(s[0]=='0')break;
        long long sum=1;
        int num,w;
        stringstream ss(s);
        while(ss>>num)
        {
            ss>>w;
            for(int i=1;i<=w;i++)
            {
                sum*=num;
            }
        }
        sum-=1;
        bool f=false;
        for(int i=32767;i>=2;i--)
        {
            if(a[i]==0)
            {
                if(sum%i==0)
                {
                    int g=0;
                    if(f!=false)
                    {
                        cout<<" ";
                        
                    }
                    f=true;
                    cout<<i;
                    while(sum%i==0)
                    {
                        g++;
                        sum/=i;
                    }
                    cout<<" "<<g;
                }
            }
        }
        cout<<endl;
    }
    
}
