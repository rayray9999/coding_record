//
//  main.cpp
//  pb:Letters Rearranging
//
//  Created by ray on 2018/12/15.
//  Copyright © 2018年 ray. All rights reserved.
//

#include <iostream>
#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(int argc, const char * argv[])
{
    int t,la[26]={0};
    cin>>t;
    while(t>=0)
    {
        bool fl=false;
        int k=0,sum=0,l;
        stack<char> sk;
        string str;
        getline(cin,str);
        memset(la,0,sizeof(la));
        l=str.length();
        for(int i=0;i<l;i++)
        {
            char j;
            int n;
            j=str[i];
            n=(int)j-'a';
            if(la[n]==0)
            {
                k++;
            }
            la[n]++;
            if(fl==false)
            {
                if((i+1)<=l/2)
                {
                        sk.push(j);
                }
                else
                {
                    if(l%2==0||(i+1)!=(l/2)+1)
                    {
                        if(j==sk.top())
                        {
                            sk.pop();
                        }
                        else
                        {
                            fl=true;
                        }
                    }
                }
            }
        }
        if(k==1)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            if(fl==true)
            {
                cout<<str<<endl;
            }
            else
            {
                for(int i=0;i<26;i++)
                {
                    for(int j=la[i];j>0;j--)
                    {
                        cout<<(char)(i+'a');
                    }
                }
                cout<<endl;
            }
        }
        
        t--;
    }
    
    return 0;
}
