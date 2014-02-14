//
//  main.cpp
//  Q1025
//
//  Created by Pumpkin Lee on 1/28/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

class Testee {
public:
    Testee(char *id, int loc, int score) {
        this->id = id;
        this->loc = loc;
        this->score = score;
    }
    
    ~Testee() {
        delete[] id;
    }
    
    char *id;
    int loc;
    int score;
    int localRank, globalRank;
};

bool scoreCompare(const Testee *t1, const Testee *t2) {
    if (t1->score == t2->score) {
        return strcmp(t1->id, t2->id) < 0;
    } else {
        return t1->score > t2->score;
    }
}

int main(int argc, const char * argv[])
{
    int nLocation = 0;
    scanf("%d", &nLocation);
    
    vector<Testee *> database;
    for (int idxLoc = 1; idxLoc <= nLocation; ++idxLoc) {
        int nTestee = 0;
        scanf("%d", &nTestee);
        
        vector<Testee *> testees;
        for (int i = 0; i < nTestee; ++i) {
            char *id = new char[14];
            int score = 0;
            scanf("%s %d", id, &score);
            testees.push_back(new Testee(id, idxLoc, score));
        }
        
        sort(testees.begin(), testees.end(), scoreCompare);
        int score = -1;
        int rank = 1;
        for (int k = 0; k < testees.size(); ++k) {
            Testee *t = testees.at(k);
            if (score != t->score) {
                score = t->score;
                rank = k + 1;
            }
            t->localRank = rank;
        }
        
        database.insert(database.end(), testees.begin(), testees.end());
    }
    
    sort(database.begin(), database.end(), scoreCompare);
    int score = -1;
    int rank = 1;
    for (int k = 0; k < database.size(); ++k) {
        Testee *t = database.at(k);
        if (score != t->score) {
            score = t->score;
            rank = k + 1;
        }
        t->globalRank = rank;
    }
    
    printf("%lu\n", database.size());
    for (int k = 0; k < database.size(); ++k) {
        Testee *t = database.at(k);
        printf("%s %d %d %d\n", t->id, t->globalRank, t->loc, t->localRank);
    }
    
    return EXIT_SUCCESS;
}
