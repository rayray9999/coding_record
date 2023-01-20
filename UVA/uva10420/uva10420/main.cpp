//
//  main.cpp
//  uva10420
//
//  Created by ray on 2020/9/28.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[])
{
    string ss[2001],nam;
    int n;
    cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ss[i];
            getline(cin,nam);
        }
        sort(ss,ss+n);
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=i;j<n;j++)
            {
                if(ss[i]!=ss[j])
                {
                    break;
                }
                count++;
                i=j;
            }
            cout<<ss[i]<<" "<<count<<endl;
        }
    
    
    
    
    
    
    return 0;
}
