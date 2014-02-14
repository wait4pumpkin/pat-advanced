//
//  main.cpp
//  1022
//
//  Created by Pumpkin Lee on 2/1/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_LENGTH 128

struct Book {
    int id;
    char title[MAX_LENGTH];
    char author[MAX_LENGTH];
    char keywords[5][11];
    char publisher[MAX_LENGTH];
    int year;
};

int main(int argc, const char * argv[])
{
    int nBook;
    scanf("%d", &nBook);
    
    vector<Book *> database;
    multimap<string, Book *> titleMap;
    multimap<string, Book *> authorMap;
    multimap<string, Book *> keywordMap;
    multimap<string, Book *> publisherMap;
    multimap<int, Book *> yearMap;
    for (int i=0; i<nBook; ++i) {
        Book *b = new Book();
        
        char *temp = new char[MAX_LENGTH];
        
        scanf("%d\n", &b->id);
        
        fgets(temp, MAX_LENGTH, stdin);
        temp[strlen(temp) - 1] = '\0';
        strcpy(b->title, temp);
        titleMap.insert(pair<string, Book *>(string(b->title), b));
        
        fgets(temp, MAX_LENGTH, stdin);
        temp[strlen(temp) - 1] = '\0';
        strcpy(b->author, temp);
        authorMap.insert(pair<string, Book *>(string(b->author), b));
        
        fgets(temp, MAX_LENGTH, stdin);
        temp[strlen(temp) - 1] = '\0';
        char *p = strtok(temp, " ");
        int idx = 0;
        while (p) {
            strcpy(b->keywords[idx], p);
            keywordMap.insert(pair<string, Book *>(string(b->keywords[idx++]), b));
            p = strtok(NULL, " ");
        }
        
        fgets(temp, MAX_LENGTH, stdin);
        temp[strlen(temp) - 1] = '\0';
        strcpy(b->publisher, temp);
        publisherMap.insert(pair<string, Book *>(string(b->publisher), b));
        
        scanf("%d", &b->year);
        yearMap.insert(pair<int, Book *>(b->year, b));
    }
    
    int nQuery;
    scanf("%d", &nQuery);

    for (int i=0; i<nQuery; ++i) {
        int type;
        char temp[MAX_LENGTH];
        scanf("%d: ", &type);
        fgets(temp, MAX_LENGTH, stdin);
        temp[strlen(temp) - 1] = '\0';
        
        printf("%d: %s\n", type, temp);
        vector<int> result;
        switch (type) {
            case 1:
                for (multimap<string, Book *>::iterator it=titleMap.lower_bound(string(temp));
                     it!=titleMap.upper_bound(string(temp)); ++it) {
                    result.push_back((*it).second->id);
                }
                break;
                
            case 2:
                for (multimap<string, Book *>::iterator it=authorMap.lower_bound(string(temp));
                     it!=authorMap.upper_bound(string(temp)); ++it) {
                    result.push_back((*it).second->id);
                }
                break;
                
            case 3:
                for (multimap<string, Book *>::iterator it=keywordMap.lower_bound(string(temp));
                     it!=keywordMap.upper_bound(string(temp)); ++it) {
                    result.push_back((*it).second->id);
                }
                break;
                
            case 4:
                for (multimap<string, Book *>::iterator it=publisherMap.lower_bound(string(temp));
                     it!=publisherMap.upper_bound(string(temp)); ++it) {
                    result.push_back((*it).second->id);
                }
                break;
                
            case 5:
                for (multimap<int, Book *>::iterator it=yearMap.lower_bound(atoi(temp));
                     it!=yearMap.upper_bound(atoi(temp)); ++it) {
                    result.push_back((*it).second->id);
                }
                break;
                
            default:
                break;
        }
        
        sort(result.begin(), result.end());
        if (result.size() <= 0) {
            printf("Not Found\n");
        } else {
            for (int i=0; i<result.size(); ++i) {
                printf("%07d\n", result[i]);
            }
        }
    }
    
    return 0;
}

// 注意fgets的换行符
// multimap用法
