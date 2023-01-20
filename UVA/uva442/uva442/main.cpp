//
//  main.cpp
//  uva442
//
//  Created by ray on 2020/10/11.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
int arr[27][2];
struct matrix
{
    int row;
    int col;
};
int main(int argc, const char * argv[])
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char k;
        cin>>k;
        cin>>arr[k-'A'][0]>>arr[k-'A'][1];
    }
    string s;
    while(cin>>s)
    {
        stack <matrix> st;
        bool f=true;
        long long ans=0;
        if(s.size()==1)
        {
            cout<<"0"<<endl;
            continue;
        }
        for(int i=0;i<s.size();i++)
        {
            matrix stp1,stp2,stp;
            if(s[i]=='(')
            {
                continue;
            }
            else if(s[i]==')')
            {
                stp2=st.top();
                st.pop();
                stp1=st.top();
                st.pop();
                if(stp1.col==stp2.row)
                {
                    ans+=stp1.row*stp1.col*stp2.col;
                    stp.row=stp1.row;
                    stp.col=stp2.col;
                    st.push(stp);
                }
                else
                {
                    f=false;
                    break;
                }
                
            }
            else
            {
                stp.row=arr[s[i]-'A'][0];
                stp.col=arr[s[i]-'A'][1];
                st.push(stp);
            }
                
        }
        if(!f)
        {
            cout<<"error"<<endl;
        }
        else
        {
            cout<<ans<<endl;
        }
        if(!st.empty())st.pop();
    }
    
    return 0;
}
