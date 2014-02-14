//
//  main.cpp
//  Q1070
//
//  Created by Pumpkin Lee on 1/30/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Mooncake {
    double amount;
    double price;
    
    bool operator < (const Mooncake &c) const {
        return price / amount < c.price / c.amount;
    }
};

int main(int argc, const char * argv[])
{
    int nCake;
    double demand;
    scanf("%d %lf", &nCake, &demand);
    
    vector<Mooncake> cakes;
    for (int i=0; i<nCake; ++i) {
        double amount;
        scanf("%lf", &amount);
        cakes.push_back(Mooncake { amount });
    }
    for (int i=0; i<nCake; ++i) {
        double price;
        scanf("%lf", &price);
        cakes[i].price = price;
    }
    
    sort(cakes.begin(), cakes.end());
    double sum = 0.;
    for (int i=nCake-1; i>=0 && demand>0; --i) {
        Mooncake &c = cakes[i];
        if (c.amount <= demand) {
            sum += c.price;
            demand -= c.amount;
        } else {
            sum += c.price / c.amount * demand;
            demand = 0;
        }
    }
    
    printf("%.02f", sum);
    
    return 0;
}

// 不要随便认为是整数

