//
//  main.cpp
//  uva409
//
//  Created by ray on 2020/10/6.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;
int main(int argc, const char * argv[])
{
    int k,e,a[10000],fi[80],nu=1;
    string ss[80];
    while(cin>>k>>e)
    {
        int ma=0;
        memset(a,0,sizeof(a));
        memset(fi,0,sizeof(fi));
        string s;
        while(k--)
        {
            int sum=0;
            cin>>s;
            for(int i=0;i<s.size();i++)
            {
                sum+=(s[i]-'a'+1)*(i+1);
            }
            a[sum]=1;
        }
        cin.ignore();
        for(int h=1;h<=e;h++)
        {
            int k=1,ans=0;
            getline(cin,ss[h]);
            for(int i=0;i<ss[h].size();i++)
            {
                if(ss[h][i]>='a'&&ss[h][i]<='z')
                {
                    ans=ans+(ss[h][i]-'a'+1)*k;
                    k++;
                }
                else if(ss[h][i]>='A'&&ss[h][i]<='Z')
                {
                    ans=ans+(ss[h][i]-'A'+1)*k;
                    k++;
                }
                else
                {
                    if(ans<=10000)
                    {
                        if(a[ans]==1)fi[h]++;
                        ans=0;
                        k=1;
                    }
                }
                if(i==ss[h].size()-1)
                {
                    if(ans<=10000)
                    {
                        if(a[ans]==1)fi[h]++;
                    }
                }
            }
            if(fi[h]>ma)ma=fi[h];
        }
        cout<<"Excuse Set #"<<nu<<endl;
        for(int i=1;i<=e;i++)
        {
            if(fi[i]==ma)cout<<ss[i]<<endl;
        }
        cout<<endl;
        nu++;
    }
    
    return 0;
}
