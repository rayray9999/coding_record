//
//  main.cpp
//  uva11000
//
//  Created by ray on 2020/10/10.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    long long n,l[100][2],ma=0;
    l[0][0]=0;
    l[0][1]=1;
    while(cin>>n)
    {
        if(n==-1)break;
        long long m=l[ma][0],g=l[ma][1]-l[ma][0]-1;
        if(ma<n)
        {
            for(int i=ma+1;i<=n;i++)
            {
                long long k;
                k=m;
                m=g+m+1;
                g=k;
                l[i][0]=m;
                l[i][1]=m+g+1;
            }
            g++;
            cout<<m<<" "<<m+g<<endl;
            ma=n;
        }
        else
        {
            cout<<l[n][0]<<" "<<l[n][1]<<endl;
        }
        
    }
    
    return 0;
}
