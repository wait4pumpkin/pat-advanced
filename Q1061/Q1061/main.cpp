//
//  main.cpp
//  Q1061
//
//  Created by Pumpkin Lee on 2/5/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_LENGTH 128

inline int char2int(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    } else {
        return -1;
    }
}

inline int en2pos(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 26;
    } else {
        return -1;
    }
}

int main(int argc, const char * argv[])
{
    char string[4][MAX_LENGTH];
    fgets(string[0], MAX_LENGTH, stdin);
    fgets(string[1], MAX_LENGTH, stdin);
    fgets(string[2], MAX_LENGTH, stdin);
    fgets(string[3], MAX_LENGTH, stdin);
    
    bool flag[1024];
    memset(flag, -1, sizeof(flag));
    const char *weekdayStr[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
    
    char *pa = string[0];
    char *pb = string[1];
    int firstFound = -1;
    int secondFound = -1;
    for (; *pa && *pb; ++pa, ++pb) {
        if (*pa != *pb) continue;
        if (firstFound < 0 && *pa >= 'A' && *pa <= 'G') {
            firstFound = *pa - 'A';
        } else if (firstFound >= 0) {
            if (*pa >= '0' && *pa <= '9') {
                secondFound = *pa - '0';
                break;
            } else if (*pa >= 'A' && *pa <= 'N') {
                secondFound = *pa - 'A' + 10;
                break;
            }
        }
    }
    
    pa = string[2];
    pb = string[3];
    int thirdFound = 0;
    for (; *pa && *pb; ++pa, ++pb, ++thirdFound) {
        if (*pa != *pb) continue;
        if ((*pa >= 'A' && *pa <= 'Z') || (*pa >= 'a' && *pa <= 'z')) {
            break;
        }
    }
    
    printf("%s %02d:%02d\n", weekdayStr[firstFound], secondFound, thirdFound);
    
    return 0;
}

// 理解好题目是关键
