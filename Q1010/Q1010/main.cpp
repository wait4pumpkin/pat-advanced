//
//  main.cpp
//  Q1010
//
//  Created by Pumpkin Lee on 1/31/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <cassert>

using namespace std;

inline int char2int(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    } else {
        return -1;
    }
}

inline int64_t extract(vector<int> &digits, size_t radix) {
    int64_t num = 0;
    int64_t base = 1;
    for (int k=static_cast<int>(digits.size()-1); k>=0; --k) {
        num += digits[k] * base;
        base *= radix;
    }
    return num;
}

int main(int argc, const char * argv[])
{
    char aStr[16], bStr[16];
    int tag;
    int64_t radix;
    scanf("%s %s %d %lld", aStr, bStr, &tag, &radix);
    

    char *p = (tag == 1 ? aStr : bStr);
    int length = static_cast<int>(strlen(p));
    int64_t a = 0, base = 1;
    for (long i=length-1; i>=0; --i) {
        a += char2int(p[i]) * base;
        base *= radix;
    }
    
    p = (tag == 1 ? bStr : aStr);
    length = static_cast<int>(strlen(p));
    int64_t minRadix = 2;
    for (int i=0; i<length; ++i) {
        int k = char2int(p[i]);
        if (k + 1 > minRadix) {
            minRadix = k + 1;
        }
    }
    
    vector<int> digits(length);
    for (int k=length-1; k>=0; --k) {
        digits[k] = char2int(p[k]);
    }
    
    bool isFound = false;
    int64_t low = minRadix, high = max(minRadix, a + 1);
    for (radix=low; radix<=100; ++radix) {
        int64_t num = extract(digits, radix);
        if (num == a) {
            isFound = true;
            break;
        }
    }
    
    if (!isFound) {
        low = 100;
        radix = low;
        while (low <= high) {
            int64_t num = extract(digits, radix);
            if (num > a) {
                high = radix - 1;
            } else if (num < a) {
                low = radix + 1;
            } else {
                isFound = true;
                break;
            }
            radix = low + ((high - low) >> 1);
        }
    }
    
    if (isFound) {
        printf("%lld\n", radix);
    } else {
        printf("Impossible\n");
    }

    return 0;
}

// 注意题目提到的十位数，加上每位数最大可能为35，必须用64位int
// 要确定好上下限，否则会超时
// 还有一组数据依然超时，只能用二分法
// 用二分法要特别注意，要求输出的是最小解，而不是其中一个解
// 直接先顺序扫了小的radix再二分，卡了很久
