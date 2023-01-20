//
//  main.cpp
//  uva11997
//
//  Created by ray on 2021/1/27.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;
long long a[750],ans[750]={0};
struct custom_type {
    long long val;
    int pos;
    
    bool operator < (const custom_type &B) const {
        return val > B.val; // min heap
    }
};
void go(int k)
{
    priority_queue<custom_type> pq;
    for(int i=0;i<k;i++)
    {
        pq.push({ans[i]+a[0],0});
    }
    for(int i=0;i<k;i++)
    {
        custom_type c=pq.top();
        ans[i]=c.val;
        pq.pop();
        pq.push({c.val-a[c.pos]+a[c.pos+1],c.pos+1});
        
    }
}
int main(int argc, const char * argv[])
{
    int k;
    while(cin>>k)
    {
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                cin>>a[j];
            }
            sort(a,a+k);
            if(i==0)
            {
                for(int g=0;g<k;g++)
                {
                    ans[g]=a[g];
                    
                }
            }
            else
            {
                go(k);
            }
        }
        cout<<ans[0];
        for(int i=1;i<k;i++)cout<<" "<<ans[i];
        cout<<endl;
    }
    return 0;
}
