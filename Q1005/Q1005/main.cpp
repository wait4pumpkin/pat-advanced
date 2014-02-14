//
//  main.cpp
//  Q1005
//
//  Created by Pumpkin Lee on 1/30/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    char num[256];
    scanf("%s", num);
    
    char *p = num;
    int sum = 0;
    do {
        sum += *p++ - '0';
    } while (*p);
    
    const char *lookup[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    
    sprintf(num, "%d", sum);
    p = num;
    printf("%s", lookup[*p++ - '0']);
    while (*p) {
        printf(" %s", lookup[*p++ - '0']);
    }
    
    return 0;
}

