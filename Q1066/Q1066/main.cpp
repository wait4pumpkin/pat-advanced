//
//  main.cpp
//  Q1066
//
//  Created by Pumpkin Lee on 2/10/14.
//  Copyright (c) 2014 Pumpkin Lee. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node {
    
    Node(int num) {
        value = num;
        left = right = NULL;
        height = 0;
    }
    
    int value;
    int height;
    Node *left;
    Node *right;
};

struct Tree {
    
    Tree() {
        root = NULL;
    }
    
    void push(int num) {
        root = add(root, num);
    }
    
    Node* add(Node *root, int num) {
        if (!root) {
            root = new Node(num);
            return root;
        }
        if (num < root->value) {
            root->left = add(root->left, num);
            if (height(root->left) - height(root->right) > 1) {
                if (num < root->left->value) {
                    root = rightRotate(root);
                } else {
                    root->left = leftRotate(root->left);
                    root = rightRotate(root);
                }
            }
        } else {
            root->right = add(root->right, num);
            if  (height(root->right) - height(root->left) > 1) {
                if (num >= root->right->value) {
                    root = leftRotate(root);
                } else {
                    root->right = rightRotate(root->right);
                    root = leftRotate(root);
                }
            }
        }
        root->height = max(height(root->left), height(root->right)) + 1;
        return root;
    }
    
    Node* rightRotate(Node *root) {
        Node *newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;
        root = newRoot;
        
        root->right->height = max(height(root->right->left), height(root->right->right)) + 1;
        return root;
    }
    
    Node* leftRotate(Node *root) {
        Node *newRoot = root->right;
        root->right = newRoot->left;
        newRoot->left = root;
        root = newRoot;
        
        root->left->height = max(height(root->left->left), height(root->left->right)) + 1;
        return root;
    }
    
    int height(Node *n) {
        if (n == NULL) return -1;
        else return n->height;
    }
    
    Node *root;
};

int main(int argc, const char * argv[])
{
    int n;
    scanf("%d", &n);
    
    Tree tree;
    for (int i=0; i<n; ++i) {
        int num;
        scanf("%d", &num);
        tree.push(num);
    }
    
    printf("%d\n", tree.root->value);
    
    return 0;
}

// 熟悉旋转，注意旋转时的子树
// 回调的时候要更新高度
