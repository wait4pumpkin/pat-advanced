//
//  main.cpp
//  Q1058
//
//  Created by Pumpkin Lee on 1/29/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Currency {
    
    Currency operator +(const Currency &c) const {
        Currency sum;
        sum.knut = (knut + c.knut) % 29;
        sum.sickle = sickle + c.sickle + (knut + c.knut) / 29;
        int plusone = sum.sickle / 17;
        sum.sickle %= 17;
        
        char tmp[25];
        int idx = 24;
        const char *p = galleon + strlen(galleon) - 1;
        const char *q = c.galleon + strlen(c.galleon) - 1;
        while (p >= galleon && q >= c.galleon) {
            int a = (*p--) - '0';
            int b = (*q--) - '0';
            int c = a + b + plusone;
            plusone = c / 10;
            c %= 10;
            tmp[idx--] = c + '0';
        }
        if (p >= galleon) {
            int a = (*p--) - '0' + plusone;
            plusone = a / 10;
            a %= 10;
            tmp[idx--] = a + '0';
        } else if (q >= c.galleon) {
            int a = (*q--) - '0' + plusone;
            plusone = a / 10;
            a %= 10;
            tmp[idx--] = a + '0';
        }
        if (plusone > 0) {
            tmp[idx--] = plusone + '0';
        }
        
        int cnt = 0;
        for (++idx; idx < sizeof(tmp) / sizeof(tmp[0]); ++idx) {
            sum.galleon[cnt++] = tmp[idx];
        }
        sum.galleon[cnt] = '\0';
        
        return sum;
    }
    
    void print() {
        printf("%s.%d.%d", galleon, sickle, knut);
    }
    
    char galleon[10];
    int sickle;
    int knut;
};

int main(int argc, const char * argv[])
{
    char aStr[25], bStr[25];
    scanf("%s %s", aStr, bStr);
    
    Currency a;
    char *p = strtok(aStr, ".");
    strcpy(a.galleon, aStr);
    a.sickle = atoi(strtok(NULL, "."));
    a.knut = atoi(strtok(NULL, "."));
    
    Currency b;
    p = strtok(bStr, ".");
    strcpy(b.galleon, bStr);
    b.sickle = atoi(strtok(NULL, "."));
    b.knut = atoi(strtok(NULL, "."));
    
    Currency c = a + b;
    c.print();
    
    return 0;
}

//进位要细致