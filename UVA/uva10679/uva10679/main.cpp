//
//  main.cpp
//  uva10679
//
//  Created by ray on 2021/1/23.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;
int main(int argc, const char * argv[])
{
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        int a[1005]={0};
        int k;
        cin>>k;
        while(k--)
        {
            string p;
            cin>>p;
            int len=p.length();
            for(int i=1;i<len;i++)
            {
                a[i]=0;
                int j=a[i-1];
                while(j>0&&p[i]!=p[j])
                {
                    j=a[j-1];
                }
                if(p[i]==p[j])a[i]=j+1;
            }
            int j=0;
            bool f=false;
            for(int i=0;i<s.length();i++)
            {
                if(s[i]==p[j])
                {
                    j++;
                    if(j==len)
                    {
                        f=true;
                        break;
                    }
                }
                else
                {
                    while(j>0&&s[i]!=p[j])
                    {
                        j=a[j-1];
                    }
                    if(s[i]==p[j])
                    {
                        j++;
                    }
                    else
                    {
                        j=0;
                    }
                    if(len-j>s.length()-i-1)break;
                }
            }
            if(f)
            {
                cout<<"y"<<endl;
            }
            else
            {
                cout<<"n"<<endl;
            }
        }
    }
    return 0;
}
