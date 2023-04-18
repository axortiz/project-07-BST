#ifndef CLASS_H
#define CLASS_H
#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;
    Node(int new_key, Node* new_parent);
};
class Binary_Search_Tree {
private:
    Node* root;
public:
    Binary_Search_Tree();
    bool empty();
    void insert(int new_key);
    void recursive_insert(Node* current, int new_key);
    void display();
    void recursive_display(Node* current);
    Node* locate(int key);
    Node* recursive_locate(int key, Node* current);
    Node* largest_to_left(Node* n);
    void normal_remove(int n);
    void JR_remove(int n);
    int height(Node* n);
};
// 25 15 35 5 20 3 10 8
#endif