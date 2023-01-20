//
//  main.cpp
//  uva11340
//
//  Created by ray on 2021/1/16.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<string>
#include<memory.h>
#include<stdlib.h>
#include <iomanip>
#include<map>
using namespace std;

int main(int argc, const char * argv[])
{
    int N;
    cin>>N;
    while(N--)
    {
        map<char,int> m;
        map<char, int>::iterator it;
        int k;
        cin>>k;
        for(int i=0;i<k;i++)
        {
            int o;
            char q;
            cin>>q>>o;
            m[q]=o;
        }
        cin>>k;
        string s;
        double ans=0;
        cin.ignore();
        for(int i=0;i<k;i++)
        {
            getline(cin,s);
            
            for(int j=0;j<s.length();j++)
            {
                it=m.find(s[j]);
                if(it!=m.end())
                {
                    ans+=m[s[j]];
                }
            }
        }
        cout<<fixed<<setprecision(2)<<ans/100;
        cout<<"$"<<endl;
        
    }
    return 0;
}
