//
//  main.cpp
//  Q1060
//
//  Created by Pumpkin Lee on 1/29/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

struct FloatNumber {
    FloatNumber(char *data, int nDigit) {
        char *p = data;
        int dotPos = 0;
        while (*p == '0') ++p;
        if (*p == '.') {
            while (*++p == '0') --dotPos;
            if (*p == '\0') dotPos = 0;
        } else {
            while (*p != '\0') {
                if (*p++ == '.') {
                    break;
                }
                ++dotPos;
            }
        }
        k = dotPos;

        p = data;
        while (*p == '0' || *p == '.') ++p;
        int i = 0, idx = 0;
        for (; i < nDigit && *p != '\0';) {
            if (*p != '.') {
                num[idx++] = *p;
                ++i;
            }
            ++p;
        }
        while (i++ < nDigit) {
            num[idx++] = '0';
        }
        num[idx] = '\0';
    }
    
    bool operator == (const FloatNumber &f) const {
        if (k != f.k) return false;
        return strcmp(num, f.num) == 0;
    }
    
    char num[128];
    int k;
};

int main(int argc, const char * argv[])
{
    int nDigit;
    scanf("%d", &nDigit);
    
    char a[128], b[128];
    scanf("%s %s", a, b);
    
    FloatNumber numA(a, nDigit);
    FloatNumber numB(b, nDigit);
    
    if (numA == numB) {
        printf("YES 0.%s*10^%d", numA.num, numA.k);
    } else {
        printf("NO 0.%s*10^%d 0.%s*10^%d", numA.num, numA.k, numB.num, numB.k);
    }
    
    return 0;
}

// 特殊情况，有效位数较多最后要补零
// 0.几的情况
// 指数是负的情况
// 0.0的情况
// 000.的情况
// 0001前导零