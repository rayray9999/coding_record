//
//  main.cpp
//  toj225
//
//  Created by 端木竣偉 on 2018/11/2.
//  Copyright © 2018年 端木竣偉. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    long long a,pla,tim=0,len,now;
    cin>>a;
    cin>>len>>now;
    pla=now+len;
    for(int i=2;i<=a;i++)
    {
        cin>>len>>now;
        if(pla<now)
        {
            tim=a-i+1;
            break;
        }
        else
        {
            pla=max(pla,now+len);
        }
    }
    if(tim==0)
    {
        cout<<"hurray"<<endl;
    }
    else
    {
        cout<<tim<<endl;
    }
    return 0;
}
