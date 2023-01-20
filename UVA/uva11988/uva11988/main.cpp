//
//  main.cpp
//  uva11988
//
//  Created by ray on 2018/12/23.
//  Copyright © 2018年 ray. All rights reserved.
//

#include <iostream>
#include<sstream>

using namespace std;
int ne[100005];
char a[100005];
int main(int argc, const char * argv[])
{
    string s;
    while(cin>>s)
    {
        int cur=0,la=0;
        for(int i=1;i<=s.length();i++)
        {
            a[i]=s[i-1];
        }
        memset(ne,-1,sizeof(ne));
        for(int i=1;i<=s.length();i++)
        {
            if(a[i]=='[')
            {
                cur=0;
            }
            else if(a[i]==']')
            {
                cur=la;
            }
            else
            {
                ne[i]=ne[cur];
                ne[cur]=i;
                if(cur==la) la=i;
                cur=i;
            }
        }
    
        int k=0;
        while(ne[k]!=-1)
        {
            cout<<a[ne[k]];
            k=ne[k];
        }
        cout<<endl;
    }
    
    
    
    return 0;
}
