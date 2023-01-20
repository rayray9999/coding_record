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
    int n,m;
    int stu[50005],book[50005],summ=0;
    while(cin>>n>>m)
    {
        summ++;
        int sum=n;
        if(n==0&&m==0)
        {
            break;
        }
        memset(book,0,sizeof(0));
        for(int i=1;i<=n;i++)
        {
            stu[i]=i;
        }
        for(int i=1;i<=m;i++)
        {
            int s1,s2;
            cin>>s1>>s2;
            if(stu[s1]!=stu[s2])
          {
            if(book[s1]==0&&book[s2]==0)
            {
                book[s1]=1;
                book[s2]=1;
                stu[s2]=stu[s1];
                sum--;
            }
            else
            {
                book[s1]=1;
                book[s2]=1;
                int us;
                us=stu[s2];
                for(int j=n;j>=1;j--)
                {
                    if(stu[j]==us)
                    {
                        stu[j]=stu[s1];
                    }
                }
                sum--;
            }
          }
        }
        cout<<"Case "<<summ<<": "<<sum<<endl;
    }
    return 0;
}
