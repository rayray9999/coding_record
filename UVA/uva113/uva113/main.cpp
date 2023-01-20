//
//  main.cpp
//  uva113
//
//  Created by ray on 2021/1/9.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<math.h>
using namespace std;
int main(int argc, const char * argv[])
{
    double a,b;
    while(cin>>a>>b)
    {
        double c=pow(b,1/a);
        int k=c;
        if(c-k>=0.5)
        {
            k++;
        }
        cout<<k<<endl;
    }
    return 0;
}
