//
//  main.cpp
//  Q1051
//
//  Created by Pumpkin Lee on 1/30/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
    int capacity, n, kPop;
    scanf("%d %d %d", &capacity, &n, &kPop);
    
    vector<int> stack;
    for (int idxPop=0; idxPop<kPop; ++idxPop) {
        int pos = 1;
        bool isVaild = true;
        for (int i=0; i<n; ++i) {
            int num;
            scanf("%d", &num);
            if (!isVaild) continue;
            
            if (num > stack.size()) {
                for (; pos<=num; ++pos) {
                    stack.push_back(pos);
//                    printf("Push: %d\n", pos);
                }
            }
            
            if (stack.size() > capacity) {
                isVaild = false;
                continue;
            }
            
            if (stack.back() == num) {
                stack.pop_back();
//                printf("Pop: %d\n", num);
            } else {
                isVaild = false;
                continue;
            }
        }
        
        if (isVaild) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        stack.clear();
    }
    
    return 0;
}

// 根据序列做栈操作
