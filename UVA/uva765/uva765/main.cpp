//
//  main.cpp
//  uva765
//
//  Created by ray on 2020/10/4.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include<cstdio>
#include<cstring>

using namespace std;

int main(int argc, const char * argv[])
{
    map<int,string> ma;
    int arr[40005]={0},sanum=1,arnum=1,so[40005]={0};
    string s,ss,sa[40005],aa="\n";
    while(getline(cin,s))
    {
        if(s.size()==0)continue;
        s.insert(s.size(),aa);
        while(getline(cin,ss))
        {
            if(ss.size()==0)break;
            s.insert(s.size(),ss);
            s.insert(s.size(),aa);
        }
        if(s[0]=='[')
        {
            int k=1,sum=0,wa=0;
            for(int i=1;i<=3;i++)
            {
                if(s[i]==']')break;
                if(s[i]>='0'&&s[i]<='9')
                {
                    sum=sum+(s[i]-'0')*k;
                    k*=10;
                    wa++;
                }
            }
            s=s.assign(s,wa+1,s.size()-(wa+1));
            ma[sum]=s;
        }
        else
        {
            sa[sanum]=s;
            sanum++;
        }
    }
    for(int i=1;i<sanum;i++)
    {
        for(int j=0;j<sa[i].size();j++)
        {
            cout<<sa[i][j];
            if(sa[i][j]=='[')
            {
                int k=1,sum=0,wa=0;
                for(int g=j+1;g<=j+3;g++)
                {
                     if(sa[i][g]==']')break;
                    if(sa[i][g]>='0'&&sa[i][g]<='9')
                    {
                        sum=sum+(sa[i][g]-'0')*k;
                        k*=10;
                        wa++;
                    }
                }
                j+=wa;
                
                if(arr[sum]==0)
                {
                    arr[sum]=arnum;
                    so[arnum]=sum;
                    arnum++;
                }
                  cout<<arr[sum];
                
            }
        }
        if(arnum!=1||i!=sanum-1)cout<<endl;
    }
    
    
    for(int i=1;i<arnum;i++)
    {
        cout<<"["<<i<<ma[so[i]];
        if(i!=arnum-1)cout<<endl;
    }
    return 0;
}
