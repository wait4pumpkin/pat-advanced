//
//  main.cpp
//  Q1056
//
//  Created by Pumpkin Lee on 2/1/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Player {
    int mice;
    int rank;
};

void compete(vector<Player *> &players, int split) {
    if (players.size() <= 1) {
        return;
    }
    
    int max = -1;
    int pos = -1;
    vector<Player *> next;
    for (int i=0; i<players.size(); ++i) {
        Player *p = players[i];
        if (p->mice > max) {
            max = p->mice;
            pos = i;
        }
        if ((i + 1) % split == 0 || i == players.size() - 1) {
            ++(players[pos]->rank);
            next.push_back(players[pos]);
            pos = -1;
            max = -1;
            continue;
        }
    }
    compete(next, split);
}

bool compareByRank(const Player *p1, const Player *p2) {
    return p1->rank > p2->rank;
}

int main(int argc, const char * argv[])
{
    int nPlayer, numSplit;
    scanf("%d %d", &nPlayer, &numSplit);
    
    vector<Player *> players;
    for (int i=0; i<nPlayer; ++i) {
        Player *p = new Player;
        int mice;
        scanf("%d", &mice);
        p->mice = mice;
        p->rank = 1;
        players.push_back(p);
    }
    
    vector<Player *> competition(players);
    for (int i=0; i<nPlayer; ++i) {
        int order;
        scanf("%d", &order);
        competition[i] = players[order];
    }
    compete(competition, numSplit);
    
    sort(competition.begin(), competition.end(), compareByRank);
    
    int last = -1;
    int rank = -1;
    for (int i=0; i<nPlayer; ++i) {
        Player *p = competition[i];
        if (p->rank != last) {
            last = p->rank;
            rank = i + 1;
        }
        p->rank = rank;
    }
    
    for (int i=0; i<nPlayer; ++i) {
        if (i != 0) printf(" ");
        printf("%d", players[i]->rank);
    }
    
    return 0;
}

// 注意最后一个组的处理
// 排名问题关键还是并列情况
// 理解第三行的排序 competition[i] = players[order];
