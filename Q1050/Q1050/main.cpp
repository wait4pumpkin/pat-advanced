//
//  main.cpp
//  Q1050
//
//  Created by Pumpkin Lee on 1/30/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAX_LENGTH 100000

int main(int argc, const char * argv[])
{
    char s1[MAX_LENGTH], s2[MAX_LENGTH];
    fgets(s1, MAX_LENGTH, stdin);
    fgets(s2, MAX_LENGTH, stdin);
    
    bool flag[512];
    memset(flag, 0, sizeof(flag));
    char *p = s2;
    do {
        flag[*p] = true;
    } while (*++p);
    
    p = s1;
    do {
        if (!flag[*p]) {
            printf("%c", *p);
        }
    } while (*++p);
    printf("\n");
    
    return 0;
}

// 注意数组大小，要保证够容量