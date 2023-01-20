#include<bits/stdc++.h>
using namespace std;
long long dp[45][25][505],ma[45][25];
int main()
{
    int bor,an;
    while(cin>>bor>>an)
    {
        memset(dp,0,sizeof(dp));
        memset(ma,0,sizeof(ma));
        if(bor==0)
        {
            break;
        }
        for(int i=1;i<=bor;i++)
        {
            for(int j=1;j<=bor-i+1;j++)
            {
                cin>>ma[i][j];
            }
        }
        for(int i=bor+1;i<=2*bor-1;i++)
        {
            for(int j=1;j<=i-bor+1;j++)
            {
                cin>>ma[i][j];
            }
        }
        for(int i=1;i<=bor;i++)
        {
            dp[2*bor-1][i][ma[2*bor-1][i]]++;
        }
        for(int i=2*bor-2;i>=bor;i--)
        {
            for(int j=1;j<=i+1-bor;j++)
            {
                for(int k=0;k<=an;k++)
                {
                    if(dp[i+1][j][k]!=0)
                    {
                        if(k+ma[i][j]<=an)
                        {
                            dp[i][j][k+ma[i][j]]=dp[i][j][k+ma[i][j]]+dp[i+1][j][k];
                        }
                    }
                    if(dp[i+1][j+1][k]!=0)
                    {
                        if(k+ma[i][j]<=an)
                        {
                            dp[i][j][k+ma[i][j]]=dp[i][j][k+ma[i][j]]+dp[i+1][j+1][k];
                        }
                    }
                    
                }
            }
        }
        for(int i=bor-1;i>=1;i--)
        {
            for(int j=1;j<=bor-i+1;j++)
            {
                for(int k=0;k<=an;k++)
                {
                    if(j==1)
                    {
                        if(dp[i+1][j][k]!=0)
                        {
                            if(k+ma[i][j]<=an)
                            {
                                dp[i][j][k+ma[i][j]]=dp[i][j][k+ma[i][j]]+dp[i+1][j][k];
                            }
                        }
                        
                    }
                    else if(j==bor-i+1)
                    {
                        if(dp[i+1][j-1][k]!=0)
                        {
                            if(k+ma[i][j]<=an)
                            {
                                dp[i][j][k+ma[i][j]]=dp[i][j][k+ma[i][j]]+dp[i+1][j-1][k];
                            }
                        }
                    }
                    else
                    {
                        if(dp[i+1][j][k]!=0)
                        {
                            if(k+ma[i][j]<=an)
                            {
                                dp[i][j][k+ma[i][j]]=dp[i][j][k+ma[i][j]]+dp[i+1][j][k];
                            }
                        }
                        if(dp[i+1][j-1][k]!=0)
                        {
                            if(k+ma[i][j]<=an)
                            {
                                dp[i][j][k+ma[i][j]]=dp[i][j][k+ma[i][j]]+dp[i+1][j-1][k];
                            }
                        }
                    }
                }
            }
        }
        
        long long sum=0,min=505,woo=505;
        for(int i=1;i<=bor;i++)
        {
            sum=dp[1][i][an]+sum;
            if(dp[1][i][an]!=0)
            {
                if(woo>i)
                {
                woo=i;
                min=ma[1][i];
                }
            }
        }
        cout<<sum<<endl;
        if(sum==0)
        {
            cout<<endl;
        }
        else
        {
            int now;
            char roa[40];
            now=an;
            woo--;
            cout<<woo<<" ";
            woo++;
            for(int i=1;i<bor;i++)
            {
                now=now-min;
                if(woo==1)
                {
                    roa[i]='R';
                    woo=1;
                    min=ma[i+1][woo];
                }
                else if(woo==(bor-i+1))
                {
                    roa[i]='L';
                    woo=woo-1;
                    min=ma[i+1][woo];
                }
                else
                {
                    if(dp[i+1][woo-1][now]!=0)
                    {
                        roa[i]='L';
                        woo=woo-1;
                        min=ma[i+1][woo];
                    }
                    else
                    {
                        roa[i]='R';
                        min=ma[i+1][woo];
                    }
                }
            }
            for(int i=bor;i<2*bor-1;i++)
            {
                now=now-min;
                
                 if(dp[i+1][woo][now]!=0)
                {
                    roa[i]='L';
                    min=ma[i+1][woo];
                }
                else
                {
                    roa[i]='R';
                    woo=woo+1;
                    min=ma[i+1][woo];
                }
                
            }
            for(int i=1;i<=2*bor-2;i++)
            {
                cout<<roa[i];
                
            }
            cout<<endl;
        }
                
                
                }
                
                return 0;
                }
