//
//  main.cpp
//  aa
//
//  Created by ray on 2021/4/21.
//

#include <iostream>
#include "Vector.h"
using namespace std;
int main(int argc, const char * argv[])
{
    int k;
    cin>>k;
    char a;
    
    while(k)
    {
        k--;
        
        Vector v1,v2;
        double wo;
        while(cin>>a)
        {
            if(a=='+')
            {
                cin>>v1>>v2;
                cout<<v1+v2;
                break;
            }
            else if(a=='-')
            {
                cin>>v1>>v2;
                cout<<v1-v2;
                break;
            }
            else if(a=='*')
            {
                cin>>v1>>wo;
                cout<<(v1*wo);
                break;
            }
            else if (a=='^')
            {
                cin>>v1>>v2;
                cout<<(v1^v2);
                break;
            }
        }
    }
    return 0;
}
