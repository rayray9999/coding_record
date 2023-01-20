//
//  main.cpp
//  uva10193
//
//  Created by ray on 2020/10/5.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
#include<algorithm>
using namespace std;

int main(int argc, const char * argv[])
{
    int n,k;
    cin>>n;
    k=n;
    while(n--)
    {
        long long a=0,b=0,g=1;
        string s1,s2;
        cin>>s1>>s2;
        for(int i=s1.size()-1;i>=0;i--)
        {
            a=a+g*(s1[i]-'0');
            g*=2;
        }
        g=1;
        for(int i=s2.size()-1;i>=0;i--)
        {
            b=b+g*(s2[i]-'0');
            g*=2;
        }
        if(a<b)swap(a,b);
        while(a!=0&&b!=0)
        {
            a%=b;
            if(a<b)swap(a,b);
        }
        if(a==1)
        {
            cout<<"Pair #"<<k-n<<": Love is not all you need!"<<endl;
        }
        else
        {
            cout<<"Pair #"<<k-n<<": All you need is love!"<<endl;
        }
    }
    
    
    return 0;
}
