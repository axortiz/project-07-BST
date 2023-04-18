#include "class.h"

Node::Node(int new_key, Node* new_parent) {
    key = new_key;
    left = nullptr;
    right = nullptr;
    parent = new_parent;
}
Binary_Search_Tree::Binary_Search_Tree() {
    root = nullptr;
}
bool Binary_Search_Tree::empty() {
    return root == nullptr;
}
void Binary_Search_Tree::insert(int new_key) {
    if (empty()) {
        root = new Node(new_key, nullptr);
        return;
    }
    recursive_insert(root, new_key);
    display();
}
void Binary_Search_Tree::recursive_insert(Node* current, int new_key) {
    if (current->key > new_key) {
        if (current->left == nullptr) {
            current->left = new Node(new_key, current);
            return;
        }
        recursive_insert(current->left, new_key);
    } else {
        if (current->right == nullptr) {
            current->right = new Node(new_key, current);
            return;
        }
        recursive_insert(current->right, new_key);
    }
}
void Binary_Search_Tree::display() {
    recursive_display(root);
    int depth = height(root);
    cout << "The height of the binary tree is: " << depth << endl;
}
void Binary_Search_Tree::recursive_display(Node* current) {
    cout << "key: " << current->key << " parent: ";
    if (current->parent != nullptr) {
        cout << current->parent->key << endl;
    } else {
        cout << "none" << endl;
    }
    if (current->left != nullptr) {
        recursive_display(current->left);
    }  
    if (current->right != nullptr) {
        recursive_display(current->right);
    } 
}
Node* Binary_Search_Tree::locate(int key) {
    return recursive_locate(key, root);
}
Node* Binary_Search_Tree::recursive_locate(int key, Node* current) {
    if (current == nullptr) {
        return nullptr;
    }
    if (current->key == key) {
        return current;
    } else if (current->key > key) {
        Node* value = recursive_locate(key, current->left);
        return value;
    } else {
        Node* value = recursive_locate(key, current->right);
        return value;
    }
}
Node* Binary_Search_Tree::largest_to_left(Node* n) {
    if (n->left == nullptr) {
        return nullptr;
    }
    Node* current = n->left;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}
void Binary_Search_Tree::normal_remove(int n) {//done
/*
uses the largest-to-left node's key to overwrite the 
key of the node that we are removing, then removes 
the largest-to-left node (which will have zero children 
or one child)

list of numbers: 25 15 35 5 20 3 10 8
*/
Node* key_to_remove = locate(n);// is 15
Node* largest_l = largest_to_left(key_to_remove);// is 10
if(largest_l != nullptr){
    key_to_remove->key = largest_l->key;
    Node* current = largest_l;
    if(current->left == nullptr && current->right == nullptr){// if the largest has no children
        if(current == current->parent->left){
            current->parent->left = nullptr;
        }
        else if(current == current->parent->right){
            current->parent->right = nullptr;
        }
    }
    while(current->left != nullptr){
        current->key = current->left->key;
        current = current->left;
    }
    current->parent->left = nullptr;
    current = largest_l;
    while(current->right != nullptr){
        current->key = current->right->key;
        current = current->right;
    }
    current->parent->right = nullptr;
    display();
}
else{
    if(key_to_remove->right == nullptr){
        if(key_to_remove == key_to_remove->parent->right){
            key_to_remove->parent->right = nullptr;
        }
        else{
            key_to_remove->parent->left = nullptr;
        }
        display();
    }
    else{
        Node* current = key_to_remove;
        while(current->right != nullptr){
            current = current->right;
        }
        display();
    }
}
}
void Binary_Search_Tree::JR_remove(int n) {
Node* key_to_remove = locate(n);
Node* largest_l = largest_to_left(key_to_remove);
Node* right_branch = key_to_remove->right;
if(largest_l != nullptr){
    if(key_to_remove != root){
        key_to_remove->left->parent = key_to_remove->parent;
        if(key_to_remove == key_to_remove->parent->left){
            key_to_remove->parent->left = key_to_remove->left;
        }
        if(key_to_remove == key_to_remove->parent->right){
            key_to_remove->parent->right = key_to_remove->left;
        }
        if(largest_l->right != nullptr){
            if(right_branch->key > largest_l->key){
                Node* current = largest_l;
                while(current->right != nullptr){
                    if(current->key > right_branch->key){
                        current = current->left;
                    }
                    else{
                        current = current->right;
                    }
                }
                current->right = right_branch;
            }
        }
        else{
            largest_l->right = right_branch;
            right_branch->parent = largest_l;
        }
        display();
    }
    else if(key_to_remove == root){
        if(largest_l->key < right_branch->key){
            largest_l->right = right_branch;
            right_branch->parent = largest_l;
        }
        else{
            largest_l->left = right_branch;
            right_branch->parent = largest_l;
        }
        key_to_remove = key_to_remove->left;
        key_to_remove->parent = nullptr;
        root = key_to_remove;
        display();
    }
}
else{
    if(key_to_remove->right == nullptr){
        if(key_to_remove == key_to_remove->parent->right){
            key_to_remove->parent->right = nullptr;
        }
        else{
            key_to_remove->parent->left = nullptr;
        }
        display();
    }
    else{
        Node* current = key_to_remove;
        while(current->right != nullptr){
            current = current->right;
        }
        display();
    }
}
}
int Binary_Search_Tree::height(Node* n){
    if(n == nullptr){
        return 0;
    }
    else{
        int height_of_left = height(n->left);
        int height_of_right = height(n->right);
    
        if(height_of_left > height_of_right){
            return height_of_left + 1;
        }
        else{
            return height_of_right + 1;
        }
    }
}