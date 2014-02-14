//
//  main.cpp
//  Q1057
//
//  Created by Pumpkin Lee on 2/6/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

struct Stack {
    int median() const {
        return middle;
    }
    
    void push(int num) {
        buffer.push_back(num);
        
        if (buffer.size() <= 1) {
            middle = num;
        } else {
            if (left.size() == right.size()) {
                right.insert(middle);
            } else {
                left.insert(middle);
            }
            middle = num;
            if (middle < *(left.begin())) {
                left.insert(middle);
                middle = *(left.begin());
                left.erase(left.begin());
            }
            if (middle > *(right.begin())) {
                right.insert(middle);
                middle = *(right.begin());
                right.erase(right.begin());
            }
        }
    }
    
    int pop() {
        int num = buffer.back();
        buffer.pop_back();
        
        if (buffer.size() <= 0) return num;
        
        if (num == middle) {
            if (left.size() < right.size()) {
                middle = *(right.begin());
                right.erase(right.begin());
            } else {
                middle = *(left.begin());
                left.erase(left.begin());
            }
            return num;
        }
        
        multiset<int>::iterator it = left.find(num);
        if (it != left.end()) {
            if (left.size() < right.size()) {
                left.insert(middle);
                middle = *(right.begin());
                right.erase(right.begin());
            }
            left.erase(it);
            return num;
        }
        
        it = right.find(num);
        if (it != right.end()) {
            if (left.size() == right.size()) {
                right.insert(middle);
                middle = *(left.begin());
                left.erase(left.begin());
            }
            right.erase(it);
            return num;
        }
        
        return num;
    }
    
    size_t size() {
        return buffer.size();
    }
    
    vector<int> buffer;
    int middle;
    multiset<int, greater<int>> left;
    multiset<int, less<int>> right;
};

int main(int argc, const char * argv[])
{
    int nOp;
    scanf("%d", &nOp);
    
    Stack stack;
//    
//    vector<int> data;
//    vector<int> tmp;
//    int num;
//    for (int i=0; i<2048; ++i) {
//        switch (rand() % 2) {
//            case 0:
//                num = rand() % 10;
//                stack.push(num);
//                data.push_back(num);
//                printf("Push %d\n", num);
//                
//                tmp = data;
//                sort(tmp.begin(), tmp.end());
//                assert(tmp[(tmp.size() - 1) / 2] == stack.median());
//                
//                break;
//                
//            case 1:
//                if (data.size() > 1) {
//                    stack.pop();
//                    data.pop_back();
//                    printf("Pop\n");
//                    
//                    tmp = data;
//                    sort(tmp.begin(), tmp.end());
//                    assert(tmp[(tmp.size() - 1) / 2] == stack.median());
//                }
//                break;
//                
//            default:
//                break;
//        }
//    }
    
    char buffer[128];
    for (int i=0; i<nOp; ++i) {
        scanf("%s", buffer);
        if (!strcmp(buffer, "Pop")) {
            if (stack.size() <= 0) {
                printf("Invalid\n");
            } else {
                printf("%d\n", stack.pop());
            }
        } else if (!strcmp(buffer, "PeekMedian")) {
            if (stack.size() <= 0) {
                printf("Invalid\n");
            } else {
                printf("%d\n", stack.median());
            }
        } else {
            int num;
            scanf("%d", &num);
            stack.push(num);
        }
    }
    
    return 0;
}

// 注意erase传入的是iterator，否则会把所有相同的索引删除
// 利用multiset实现红黑树
// 注释的是自动测试
