//
//  main.cpp
//  uva793
//
//  Created by 端木竣偉 on 2018/11/8.
//  Copyright © 2018年 端木竣偉. All rights reserved.
//

#include <iostream>
#include<sstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


int main(int argc, const char * argv[])
{
    int a;
    int se[1005],book[1005];
    cin>>a;
    while(a)
    {
        int com,su=0,un=0;
        cin>>com;
        for(int i=1;i<=com;i++)
        {
            se[i]=i;
        }
        memset(book,0,sizeof(book));
        string s;
        cin.ignore();
        while(getline(cin,s))
        {
            if(s.length()==0)
            {
                break;
            }
            char mat;
            int fir,sec;
            stringstream ss(s);
            ss>>mat;
            ss>>fir;
            ss>>sec;
            if(mat=='c')
            {
                if(se[fir]!=se[sec])
                {
                    if(book[fir]==0&&book[sec]==0)
                    {
                        book[sec]=1;
                        book[fir]=1;
                        se[sec]=se[fir];
                    }
                    else
                    {
                        book[sec]=1;
                        book[fir]=1;
                        if(se[fir]!=se[sec])
                        {
                            int k;
                            k=se[sec];
                            for(int i=com;i>=1;i--)
                            {
                                if(se[i]==k)
                                {
                                    se[i]=se[fir];
                                }
                            }
                        }
                    }
                    
                }
            }
            else
            {
                if(se[fir]!=se[sec])
                {
                    un++;
                }
                else
                {
                    su++;
                }
            }
        }
        cout<<su<<","<<un<<endl;
        if(a!=1)
        {
            cout<<endl;
        }
        
        
        
        a--;
    }
    return 0;
}
