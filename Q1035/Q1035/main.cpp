//
//  main.cpp
//  Q1035
//
//  Created by Pumpkin Lee on 1/29/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct Team {
    
    Team() {
        isModified = false;
    }
    
    bool check() {
        if (isModified) return true;
        
        for (int i = 0; i < sizeof(password) / sizeof(password[0]); ++i) {
            if (password[i] == '1') {
                password[i] = '@';
                isModified = true;
            } else if (password[i] == '0') {
                password[i] = '%';
                isModified = true;
            } else if (password[i] == 'l') {
                password[i] = 'L';
                isModified = true;
            } else if (password[i] == 'O') {
                password[i] = 'o';
                isModified = true;
            }
        }
        return isModified;
    }
    
    bool isModified;
    char name[11];
    char password[11];
};

int main(int argc, const char * argv[])
{
    int nTeam;
    scanf("%d", &nTeam);
    
    vector<Team> teams;
    int nModified = 0;
    for (int i = 0; i < nTeam; ++i) {
        Team t;
        scanf("%s %s", t.name, t.password);
        
        if (t.check()) ++nModified;
        teams.push_back(t);
    }
    
    if (nModified <= 0) {
        if (teams.size() == 1) {
            printf("There is 1 account and no account is modified\n");
        } else {
            printf("There are %ld accounts and no account is modified\n", teams.size());
        }
    } else {
        printf("%d\n", nModified);
        for (vector<Team>::iterator it = teams.begin(); it != teams.end(); ++it) {
            if (!(*it).isModified) continue;
            printf("%s %s\n", (*it).name, (*it).password);
        }
    }
    
    return 0;
}

