//
//  main.cpp
//  uva1339
//
//  Created by ray on 2021/1/9.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<string>
#include<algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(int argc, const char * argv[])
{
    string s1,s2;
    int a1[26]={0},a2[26]={0};
    while(cin>>s1>>s2)
    {
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        for(int i=0;i<s1.length();i++)
        {
            a1[s1[i]-'A']++;
        }
        for(int i=0;i<s2.length();i++)
        {
            a2[s2[i]-'A']++;
        }
        bool f=true;
        sort(a1,a1+26);
        sort(a2,a2+26);
        for(int i=0;i<26;i++)
        {
            if(a1[i]!=a2[i])
            {
                f=false;
                break;
            }
        }
        
        if(f)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}
