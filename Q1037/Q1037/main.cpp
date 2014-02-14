//
//  main.cpp
//  Q1037
//
//  Created by Pumpkin Lee on 1/29/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
    vector<int> coupons;
    vector<int> products;
    
    int nCoupon;
    scanf("%d", &nCoupon);
    for (int i = 0; i < nCoupon; ++i) {
        int coupon;
        scanf("%d", &coupon);
        coupons.push_back(coupon);
    }
    
    int nProduct;
    scanf("%d", &nProduct);
    for (int i = 0; i < nProduct; ++i) {
        int product;
        scanf("%d", &product);
        products.push_back(product);
    }
    
    sort(coupons.begin(), coupons.end());
    sort(products.begin(), products.end());
    int sum = 0;
    int i = static_cast<int>(coupons.size()) - 1, j = 0, k = static_cast<int>(products.size()) - 1;
    for (; i >= 0 && k >= 0; --i) {
        if (coupons[i] > 0 && products[k] > 0) {
            sum += coupons[i] * products[k--];
        } else {
            break;
        }
    }
    
    for (int t = 0; t <= i && j <= k; ++t) {
        if (coupons[t] * products[j] < 0) {
            break;
        }
        sum += coupons[t] * products[j++];
    }
    
    printf("%d", sum);
    
    return 0;
}
