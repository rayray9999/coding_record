//
//  main.cpp
//  toj54
//
//  Created by ray on 2018/12/7.
//  Copyright © 2018年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    int a;
    while(cin>>a)
    {
        if(a==0)
        {
            break;
        }
        int la[27]={0};
        string str;
        for(int i=1;i<=a;i++)
        {
            int s,len;
            cin>>str;
            s=(int)str[0]-'a';
            len=str.length()-1;
            la[s]++;
            s=(int)str[len]-'a';
            la[s]++;
        }
        bool k=true;
        for(int i=0;i<=25;i++)
        {
            if(la[i]%2!=0)
            {
                k=false;
                break;
            }
        }
        if(k)
        {
            cout<<"OK"<<endl;
        }
        else
        {
            cout<<"NG"<<endl;
        }
    }
    
    return 0;
}
