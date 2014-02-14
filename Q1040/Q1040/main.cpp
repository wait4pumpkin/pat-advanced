//
//  main.cpp
//  Q1040
//
//  Created by Pumpkin Lee on 2/9/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <climits>

#define MAX_LENGTH 1024

int main(int argc, const char * argv[])
{
    char str[MAX_LENGTH];
    fgets(str, MAX_LENGTH, stdin);
    
    char strRev[MAX_LENGTH];
    size_t length = strlen(str);
    str[length - 1] = 0;
    --length;
    
    char *src = str + length - 1;
    char *dst = strRev;
    while (src >= str) {
        *dst++ = *src--;
    }
    *dst = 0;
    
    int table[2][MAX_LENGTH];
    memset(table, 0, sizeof(table));
    int maxLength = 1;
    
    for (int j=0; j<length; ++j) {
        table[0][j] = (str[0] == strRev[j] ? 1 : 0);
    }
    
    for (int i=1; i<length; ++i) {
        int now = i % 2;
        int pre = (i + 1) % 2;
        table[now][0] = (str[i] == strRev[0] ? 1 : 0);
        for (int j=1; j<length; ++j) {
            if (str[i] == strRev[j]) {
                table[now][j] = table[pre][j-1] + 1;
            } else {
                table[now][j] = 0;
            }
            
            if (table[now][j] > maxLength) {
                maxLength = table[now][j];
            }
        }
    }
    
    printf("%d\n", maxLength);
    
    return 0;
}

// 程序思路，原字符串和reverse字符串求最长公共子序列
// 测试集不完整，123hjk321应该是1不是3
// 这个是错的，应该是直接顺序扫描比较即可，因为子串不能错位
