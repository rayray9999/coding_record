//
//  main.cpp
//  uva11351
//
//  Created by ray on 2020/10/18.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        int n,k,ans=0,human=1;
        cin>>n>>k;
        while(human<n)
        {
            human++;
            ans=(ans+k)%human;
        }
        cout<<"Case "<<cas<<": "<<ans+1<<endl;
        cas++;
    }
    return 0;
}
