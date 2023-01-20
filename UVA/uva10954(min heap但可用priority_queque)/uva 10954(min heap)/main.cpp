//
//  main.cpp
//  uva 10954(min heap)
//
//  Created by ray on 2019/1/28.
//  Copyright © 2019年 ray. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int main(int argc, const char * argv[])
{
    int n;
    while(cin>>n)
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        if(n==0) break;
        for(int i=1;i<=n;i++)
        {
            int k;
            cin>>k;
            pq.push(k);
        }
        int ti=0;
        for(int i=1;i<n;i++)
        {
            int a,b;
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            ti+=a+b;
            a+=b;
            pq.push(a);
        }
        pq.pop();
        cout<<ti<<endl;
    }
    return 0;
}
