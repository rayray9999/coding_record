//
//  main.cpp
//  uva10566(math)
//
//  Created by ray on 2019/1/28.
//  Copyright © 2019年 ray. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<iomanip>
using namespace std;
int main(int argc, const char * argv[])
{
    double a,b,c;
    while(cin>>a>>b>>c)
    {
        double ma=min(a,b),low=0,mid;
        while(low<=ma)
        {
            mid=(ma+low)/2.0;
            
    double com=(sqrt(a*a-mid*mid)*sqrt(b*b-mid*mid))/(sqrt(a*a-mid*mid)+sqrt(b*b-mid*mid));
            if(abs(com-c)<0.00001)
            {
                break;
            }
            else if(com<c)
            {
                ma=mid;
            }
            else
            {
                low=mid;
            }
        }
        cout<<fixed<<setprecision(3)<<mid<<endl;
    }
    return 0;
}
