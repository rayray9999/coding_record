//
//  main.cpp
//  uva11991
//
//  Created by ray on 2019/1/25.
//  Copyright © 2019年 ray. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
const int maxn=1000005;
vector<int> vec[maxn];
int main(int argc, const char * argv[])
{
    int n,t;
    while(cin>>n>>t)
    {
        for(int i=0;i<=maxn;i++) vec[i].clear();
        for(int i=1;i<=n;i++)
        {
            int k;
            cin>>k;
            vec[k].push_back(i);
        }
        
        for(int i=1;i<=t;i++)
        {
            int v,k;
            cin>>k>>v;
            if(k<=vec[v].size()) cout<<vec[v][k-1]<<endl;
            else cout<<"0"<<endl;
        }
        }
    return 0;
}
