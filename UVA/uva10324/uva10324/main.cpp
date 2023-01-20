//
//  main.cpp
//  uva10324
//
//  Created by ray on 2021/1/15.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;
int a[1000005]={0};
int main(int argc, const char * argv[])
{
    string s;
    int l=1;
    while(cin>>s)
    {
        a[0]=s[0]-'0';
        for(int i=1;i<s.length();i++)
        {
            a[i]=a[i-1]+s[i]-'0';
            
        }
        int k;
        cin>>k;
        cout<<"Case "<<l<<":"<<endl;
        for(int i=1;i<=k;i++)
        {
            int st,en;
            cin>>st>>en;
            int a1,b1;
            if(st==0)
            {
                a1=0;
            }
            else
            {
                a1=a[st-1];
            }
            b1=a[en];
            if((b1-a1)==en-st+1||b1-a1==0)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
            
        }
        l++;
    }
    return 0;
}
