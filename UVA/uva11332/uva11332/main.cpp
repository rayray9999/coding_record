//
//  main.cpp
//  uva11332
//
//  Created by ray on 2020/9/29.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    string s;
    while(cin>>s)
    {
        if(s[0]=='0')break;
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            sum=sum+s[i]-'0';
            while(sum>=10)
            {
                sum=(sum%10)+1;
                
            }
            
        }
        cout<<sum<<endl;
    }
    return 0;
}
