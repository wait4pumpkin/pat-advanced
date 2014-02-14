//
//  main.cpp
//  Q1033
//
//  Created by Pumpkin Lee on 2/2/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Station {
    bool operator < (const Station &s) const {
        if (distance == s.distance) {
            return price < s.price;
        }
        return distance < s.distance;
    }
    
    double price;
    double distance;
};

int main(int argc, const char * argv[])
{
    double capacity, targetDistance, runPerUnit;
    int nStation;
    scanf("%lf %lf %lf %d", &capacity, &targetDistance, &runPerUnit, &nStation);
    
    vector<Station> stations;
    for (int i=0; i<nStation; ++i) {
        Station s;
        scanf("%lf %lf", &s.price, &s.distance);
        stations.push_back(s);
    }
    stations.push_back(Station { 0., targetDistance });
    sort(stations.begin(), stations.end());
    
    if (stations[0].distance > 0) {
        printf("The maximum travel distance = %.02lf\n", 0.);
        return 0;
    }
    
    double maxDistance = capacity * runPerUnit;
    double gas = 0.;
    double amount = 0.;
    int pos = 0;
    while (true) {
        Station &s = stations[pos];
        // 直接可到达
        if (gas * runPerUnit >= targetDistance - s.distance) {
            break;
        }
        
        vector<Station> buffer;
        int nextCheap = -1;
        int mostCheap = -1;
        double price = INT32_MAX;
        for (int k=pos+1; k<stations.size(); ++k) {
            Station &nextStation = stations[k];
            if (nextStation.distance - s.distance <= maxDistance) {
                buffer.push_back(nextStation);
                if (nextCheap < 0 && nextStation.price <= s.price) {
                    nextCheap = k;
                }
                if (nextStation.price < price) {
                    price = nextStation.price;
                    mostCheap = k;
                }
            }
        }
        // 没有下一个加油站，就是不可达
        if (buffer.size() <= 0) {
            printf("The maximum travel distance = %.02lf\n", s.distance + maxDistance);
            return 0;
        }
        // 策略
        // 去第一个比当前便宜的油站，且不要加满
        // 否则去下一个最便宜的油站，且加满
        double add = 0.;
        if (stations[mostCheap].price > s.price) {
            add = capacity - gas;
            pos = mostCheap;
            gas = capacity - (stations[mostCheap].distance - s.distance) / runPerUnit;
//            printf("A ");
        } else {
            add = (stations[nextCheap].distance - s.distance) / runPerUnit - gas;
            pos = nextCheap;
            gas = 0.;
//            printf("V ");
        }
        amount += add * s.price;
        
//        printf("%d %lf %lf\n", pos, amount, gas);
    }
    printf("%.02lf\n", amount);
    
    return 0;
}

// 把目的地也当做是一个station
// 特殊情况，0处没有油站
// 贪心算法，关键在于想清楚策略，见注释
