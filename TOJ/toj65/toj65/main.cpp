//
//  main.cpp
//  toj65
//
//  Created by ray on 2019/1/27.
//  Copyright © 2019年 ray. All rights reserved.
//

#include <iostream>
#include <stdlib.h> /* 亂數相關函數 */
#include <time.h>   /* 時間相關函數 */
using namespace std;
int main(int argc, const char * argv[])
{
    srand( time(NULL) );
    int x = rand();
    cout<<x%2<<endl;
    return 0;
}
