//
//  main.cpp
//  uva10102
//
//  Created by ray on 2021/1/16.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
struct p
{
    int x;
    int y;
    
};
int main(int argc, const char * argv[])
{
    int n;
    
    while(cin>>n)
    {
        vector <p> st,en;
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                char a;
                p gg;
                cin>>a;
                if(a=='1')
                {
                    
                    gg.x=i;
                    gg.y=j;
                    st.push_back(gg);
                }
                else if(a=='3')
                {
                    gg.x=i;
                    gg.y=j;
                    en.push_back(gg);
                }
            }
        }
        int max=-1;
        for(int i=0;i<st.size();i++)
        {
            int min=-1;
            for(int j=0;j<en.size();j++)
            {
                if(abs(st[i].x-en[j].x)+abs(st[i].y-en[j].y)<min||min==-1)
                {
                    min=abs(st[i].x-en[j].x)+abs(st[i].y-en[j].y);
                }
            }
            if(min>max)max=min;
        }
        cout<<max<<endl;
    }
    
    return 0;
}
