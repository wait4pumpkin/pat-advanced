//
//  main.cpp
//  Q1063
//
//  Created by Pumpkin Lee on 2/2/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[])
{
    int nSet;
    scanf("%d", &nSet);
    
    vector<set<long>> numSets;
    for (int i=0; i<nSet; ++i) {
        int n;
        scanf("%d", &n);
        set<long> nums;
        for (int k=0; k<n; ++k) {
            long num;
            scanf("%ld", &num);
            nums.insert(num);
        }
        numSets.push_back(nums);
    }
    
    int nQuery;
    scanf("%d", &nQuery);
    for (int i=0; i<nQuery; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        set<long> &setA = numSets[a - 1];
        set<long> &setB = numSets[b - 1];
        vector<long> intersectionSet, unionSet;
        set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(), back_inserter(intersectionSet));
        set_union(setA.begin(), setA.end(), setB.begin(), setB.end(), back_inserter(unionSet));
        
        printf("%.01lf%%\n", (double)intersectionSet.size() / unionSet.size() * 100);
    }
    
    return 0;
}

// set的操作
