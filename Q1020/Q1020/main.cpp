//
//  main.cpp
//  Q1020
//
//  Created by Pumpkin Lee on 2/1/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
};

Node *analyse(int postorder[], int inorder[], int length) {
    if (length <= 0) {
        return NULL;
    }
    
    Node *root = new Node();
    memset(root, 0, sizeof(Node));
    root->key = postorder[length - 1];
    
    int rootPos = -1;
    int rootKey = root->key;
    for (int i=0; i<length; ++i) {
        if (inorder[i] == rootKey) {
            rootPos = i;
            break;
        }
    }
    root->left = analyse(postorder, inorder, rootPos);
    root->right =  analyse(postorder + rootPos, inorder + rootPos + 1, length - rootPos - 1);
    return root;
}

int main(int argc, const char * argv[])
{
    int n;
    scanf("%d", &n);
    
    int *postorder = new int[n];
    int *inorder = new int[n];
    for (int i=0; i<n; ++i) {
        int k;
        scanf("%d", &k);
        postorder[i] = k;
    }
    for (int i=0; i<n; ++i) {
        int k;
        scanf("%d", &k);
        inorder[i] = k;
    }
    
    Node *root = analyse(postorder, inorder, n);
    queue<Node *> printQueue;
    printQueue.push(root);
    bool isBegin = true;
    while (!printQueue.empty()) {
        Node *n = printQueue.front();
        if (isBegin) {
            isBegin = false;
        } else {
            printf(" ");
        }
        printf("%d", n->key);
        printQueue.pop();
        if (n->left) {
            printQueue.push(n->left);
        }
        if (n->right) {
            printQueue.push(n->right);
        }
    }
    
    delete [] postorder;
    delete [] inorder;
    
    return 0;
}

// 处理好递归公式
