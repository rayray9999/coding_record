//
//  main.cpp
//  toj275
//
//  Created by ray on 2021/1/23.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int main(int argc, const char * argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<long long,vector<long long>,less<long long>> qmax;
    priority_queue<long long,vector<long long>,greater<long long>> qmin;
    bool f=true;
    int n;
    cin>>n;
    while(n--)
    {
        long long k;
        cin>>k;
        if(qmax.size()==qmin.size())
        {
            if(qmin.size()==0||qmin.top()>=k)
            {
                qmax.push(k);
            }
            else
            {
                qmax.push(qmin.top());
                qmin.pop();
                qmin.push(k);
            }
            cout<<qmax.top()<<".000000"<<endl;
        }
        else
        {
            if(qmax.top()>k)
            {
                qmin.push(qmax.top());
                qmax.pop();
                qmax.push(k);
            }
            else
            {
                qmin.push(k);
            }
                if((qmax.top()+qmin.top())%2==0)
                {
                    cout<<(qmax.top()+qmin.top())/2<<".000000"<<endl;
                }
                else
                {
                    cout<<(qmax.top()+qmin.top())/2<<".500000"<<endl;
                }
            
        }
    }
    return 0;
}
