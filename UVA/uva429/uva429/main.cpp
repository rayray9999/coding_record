//
//  main.cpp
//  uva429
//
//  Created by ray on 2020/10/5.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;
int main(int argc, const char * argv[])
{
    int n;
    string s;
    cin>>n;
    while(n--)
    {
        while(cin>>s)
        {
            if(s[0]=='*')break;
        }
        cin.ignore();
        while(getline(cin,s))
        {
            int k;
            if(s.size()==0)break;
            for(int i=0;i<=20;i++)
            {
                if(s[i]==' ')k=i;
            }
            int ans=0;
            for(int i=0;i<k;i++)
            {
                
                if(s[i]!=s[i+k+1])ans++;
                
                
                cout<<s[i]<<" "<<s[i+k+1]<<endl;
            }
            cout<<s<<" "<<ans<<endl;
        }
        cout<<endl;
    }
    
    return 0;
}
