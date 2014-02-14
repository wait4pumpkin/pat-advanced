//
//  main.cpp
//  Q1042
//
//  Created by Pumpkin Lee on 1/29/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

struct Card {
    char tag;
    int num;
};

void shuffleCards(vector<Card> &src, vector<Card> &dst, vector<int> &orders) {
    for (int i = 0; i < orders.size(); ++i) {
        int pos = orders[i];
        dst[pos] = src[i];
    }
}

int main(int argc, const char * argv[])
{
    int n;
    scanf("%d", &n);
    
    vector<int> orders;
    for (int i = 0; i < 54; ++i) {
        int order;
        scanf("%d", &order);
        orders.push_back(order - 1);
    }
    
    vector<Card> cards;
    char tag[] = { 'S', 'H', 'C', 'D' };
    for (int i = 0; i < sizeof(tag) / sizeof(tag[0]); ++i) {
        for (int j = 1; j <= 13; ++j) {
            cards.push_back(Card { tag[i], j });
        }
    }
    cards.push_back(Card { 'J', 1 });
    cards.push_back(Card { 'J', 2 });
    
    vector<Card> result(cards);
    for (int i = 0; i < n; ++i) {
        shuffleCards(cards, result, orders);
        cards.swap(result);
    }
    
    printf("%c%d", cards[0].tag, cards[0].num);
    for (int i = 1; i < 54; ++i) {
        printf(" ");
        printf("%c%d", cards[i].tag, cards[i].num);
    }
    
    return 0;
}

//注意规则和swap