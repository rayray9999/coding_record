//
//  main.cpp
//  uva514
//
//  Created by ray on 2021/1/17.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<stack>
using namespace std;
int main(int argc, const char * argv[])
{
    int n,a[1000];
    
    while(cin>>n)
    {
        if(n==0)break;
        bool ff=true;
        while(ff)
        {
            int t=1;
            stack <int> st;
            
            for(int i=1;i<=n;i++)
            {
                cin>>a[i];
                if(a[i]==0)
                {
                    ff=false;
                    break;
                }
            }
            if(!ff)
            {
                cout<<endl;
                break;
            }
            bool f=true;
            for(int i=1;i<=n;i++)
            {
                int k=a[i];
                bool ok=false;
                while(!ok)
                {
                    if(t==k)
                    {
                        t++;
                        ok=true;
                    }
                    else
                    {
                        if(!st.empty())
                        {
                            if(st.top()==k)
                            {
                                st.pop();
                                ok=true;
                            }
                            else
                            {
                                st.push(t);
                                t++;
                            }
                        }
                        else
                        {
                            st.push(t);
                            t++;
                        }
                    }
                    if(t>n+1)
                    {
                        f=false;
                        break;
                    }
                }
                if(!f)break;
            }
            if(f)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
            
        }
        
        
    }
    return 0;
}
