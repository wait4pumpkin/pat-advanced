//
//  main.cpp
//  Q1062
//
//  Created by Pumpkin Lee on 2/1/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Person {
    
    bool operator < (const Person &p) const {
        if (state == p.state) {
            if (virtue + talent == p.virtue + p.talent) {
                if (virtue == p.virtue) {
                    return id < p.id;
                }
                return virtue > p.virtue;
            }
            return virtue + talent > p.virtue + p.talent;
        }
        return state < p.state;
    }
    
    int id;
    int virtue;
    int talent;
    int state;
};

int main(int argc, const char * argv[])
{
    int nPerson, lowRank, highRank;
    scanf("%d %d %d", &nPerson, &lowRank, &highRank);
    
    vector<Person> people;
    for (int i=0; i<nPerson; ++i) {
        int id, virtue, talent, state;
        scanf("%d %d %d", &id, &virtue, &talent);
        if (virtue < lowRank || talent < lowRank) {
            continue;
        }
        
        if (virtue >= highRank && talent >= highRank) {
            state = 1;
        } else if (virtue >= highRank && talent < highRank) {
            state = 2;
        } else if (virtue < highRank && talent < highRank && virtue >= talent) {
            state = 3;
        } else {
            state = 4;
        }
        people.push_back(Person { id, virtue, talent, state });
    }
    
    sort(people.begin(), people.end());
    printf("%ld\n", people.size());
    for (int i=0; i<people.size(); ++i) {
        Person &p = people[i];
        printf("%08d %d %d\n", p.id, p.virtue, p.talent);
    }
    
    return 0;
}

