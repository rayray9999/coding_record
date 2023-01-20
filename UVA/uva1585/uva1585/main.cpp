//
//  main.cpp
//  uva1585
//
//  Created by ray on 2021/1/8.
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
        int ans=0,pre=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='O')
            {
                pre++;
                ans+=pre;
            }
            else
            {
                pre=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
