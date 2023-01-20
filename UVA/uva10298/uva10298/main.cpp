//
//  main.cpp
//  uva10298
//
//  Created by ray on 2021/1/23.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;
int a[1000000]={0};
int main(int argc, const char * argv[])
{
    string s;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>s;
        long long len=s.length();
        for(int i=1;i<len;i++)
        {
            a[i]=0;
            int j=a[i-1];
            while(j>0&&s[i]!=s[j])
            {
                j=a[j-1];
            }
            if(s[i]==s[j])a[i]=j+1;
        }
        if((len-a[len-1])!=0&&len%(len-a[len-1])==0)
        {
            cout<<len-a[len-1]<<endl;
        }
        else
        {
            cout<<len<<endl;
        }
        if(i!=t)cout<<endl;
    }
    return 0;
}
