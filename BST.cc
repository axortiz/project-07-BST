/**
 * Project 7: Binary Search Tree
 * @file BST.cc

 * @author Alexis Ortiz
 * @date April, 13, 2023

 */
#include <iostream>
#include <vector>
#include <string>
#include "class.h"

int main() {
    Binary_Search_Tree bst;
    vector<int> keys;
    int key;
    int num_keys;
    string remove_method;
    cout << "How many numbers will be on the tree?" << endl;
    cin >> num_keys;
    cout << "Insert a list of numbers: ";
    for(int i = 0 ; i<num_keys ; i++){
        cin >> key;
        bst.insert(key);
    }
    int normal_r;
    cout << "Which number would you like to remove? " << endl;
    cin >> normal_r;
    cout << "Which remove method would you like to use? " << endl;
    cin >> remove_method;
    if(remove_method == "JR"){
        bst.JR_remove(normal_r);
    }
    else if(remove_method == "Normal"){
        bst.normal_remove(normal_r);
    }
}   