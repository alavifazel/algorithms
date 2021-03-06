#include "BST.h"

template <typename Key, typename Value>
BST<Key,Value>::BST() { }

template <typename Key, typename Value>
void BST<Key,Value>::put(Key key, Value value) {
    root = put(root, key, value); 
}

// put impl
template <typename Key, typename Value>
shared_ptr<typename BST<Key,Value>::Node> BST<Key,Value>::put(shared_ptr<typename BST<Key,Value>::Node> x,
                                                     Key key, Value value)
{
    // If key is in the tree, set the new value; else add a new node. 
    if(x == nullptr) return make_shared<BST<Key, Value>::Node>(key,value);
    Key compare = (key - x->key);
    if(compare < 0)
        x->left = put(x->left, key, value); // Recursively inserting on the left (valid in C++ since the pointer is pointing to a shared_ptr resource).
    else if(compare > 0)
        x->right = put(x->right, key, value); // Rescursively inserting on right.
    else
        x->value = value; // It was the node itself. Setting value.

    // The following code recursively increases the count variable of the nodes (from bottom up)
    x->count = 1 + size(x->left) + size(x->right);
    
    return x;
}

// get impl
template <typename Key, typename Value>
Value BST<Key,Value>::get(Key key) {
    auto x = root;
    while(x != nullptr) {
        int compare = (key - x->key);
        if(compare < 0) root = x->left;
        if(compare > 0) root = x->right;
        else            return x->value;
    }
    // Didn't find this key, returning nullptr.
    return nullptr;
}

// maximum impl
template <typename Key, typename Value>
shared_ptr<typename BST<Key,Value>::Node> 
BST<Key,Value>::maximum() {
    maximum(root);
}

template <typename Key, typename Value>
shared_ptr<typename BST<Key,Value>::Node> 
BST<Key,Value>::maximum(shared_ptr<Node> x) {
    while(x != nullptr) {
        x = x->left;
    }
    return x;
}

// minimum impl
template <typename Key, typename Value>
shared_ptr<typename BST<Key,Value>::Node> 
BST<Key,Value>::minimum() {
    minmum(root);
}

template <typename Key, typename Value>
shared_ptr<typename BST<Key,Value>::Node> 
BST<Key,Value>::minimum(shared_ptr<Node> x) {
    while(x != nullptr) {
        x = x->right;
    }
    return x;
}

// floor impl: Largest key in tree such that it is <= to our key
template <typename Key, typename Value>
Key BST<Key,Value>::floor(Key key) {
    auto x = floor(key, root);
    if(x == nullptr) return 0; // fix
    return x->key;
}

template <typename Key, typename Value>
shared_ptr<typename BST<Key,Value>::Node> 
BST<Key,Value>::floor(Key key, shared_ptr<Node> x) {
    if(x == nullptr) return nullptr; // If we don't add this line, we hit Seg Fault on the last element of the tree.
    Key compare = (key - x->key);
    if(compare == 0) return x;
    else if (compare < 0) return floor(key, x->left);
    
    // Note: We don't compare x->right to nullptr, but floor(key, x->right) to it.
    // The logic behind this function is this: When we are looking for the floor value of a key,
    // If the key's value is less than the given node's key, it should definitely be on the left nodes of our node.
    // Else it can 'possibly' on the right nodes but not necassarily (when there is a key smaller or equal to our key in right nodes).
    if(floor(key, x->right) != nullptr)
        return floor(key, x->right); 
    else
        return x;
}

// ceiling impl: Smallest key in tree such that it is >= to our key
template <typename Key, typename Value>
Key BST<Key,Value>::ceiling(Key key) {
    auto x = ceiling(key, root);
    if(x == nullptr) return 0;
    return x->key;
}

template <typename Key, typename Value>
shared_ptr<typename BST<Key,Value>::Node> 
BST<Key,Value>::ceiling(Key key, shared_ptr<Node> x) {
    // Similar procedure as floor function
    if(x == nullptr) return nullptr;
    Key compare = (key - x->key);
    if(compare == 0) return x;
    else if (compare > 0) return ceiling(key, x->right);
    
    if(ceiling(key, x->left) != nullptr)
        return ceiling(key, x->left); 
    else
        return x;
}

// rank impl 
template <typename Key, typename Value>
size_t BST<Key,Value>::rank(Key key) {
    return rank(key, root);
}

template <typename Key, typename Value>
size_t BST<Key,Value>::rank(Key key, shared_ptr<Node> x) {

    if(key == nullptr) return 0;
    Key compare = (key - key);

    if(compare < 0)         return rank(key, x->left);
    else if(compare > 0)    return 1 + size(x->left) + rank(key, x->right);
    else if(compare == 0)   return size(key, x);
}

// 'keys' method impl (uses inorder_traversal to obtain the keys)
template <typename Key, typename Value>
queue<Key> BST<Key,Value>::keys() {
    queue<Key> q;
    inorder_traversal(root, q);
    return q;
}

template <typename Key, typename Value>
void BST<Key,Value>::inorder_traversal(shared_ptr<Node> x, queue<Key> &q) {
    if(x == nullptr) return; // Base case
    inorder_traversal(x->left, q);
    q.push(x->key); // Enqueue
    inorder_traversal(x->right, q);
}

// del operations impl
template <typename Key, typename Value>
void BST<Key,Value>::delMininum() {
    root = delMininum(root); // Retrieves the new root and assigns it to 'root' member variable
}

template <typename Key, typename Value>
void BST<Key,Value>::delMaximum() {
    root = delMaximum(root); 
}

template <typename Key, typename Value>
shared_ptr<typename BST<Key,Value>::Node>
BST<Key,Value>::delMininum(shared_ptr<Node> x) {
    if(x == nullptr) return x->right;
    x->left = delMininum(x->left);

    // Updates the size counts from bottom up (because it get's called when the above recursion hits the base case)
    x->count = 1 + size(x->left) + size(x->right);
    return x; 
}

template <typename Key, typename Value>
shared_ptr<typename BST<Key,Value>::Node>
BST<Key,Value>::delMaximum(shared_ptr<Node> x) {
    if(x == nullptr) return x->left;
    x->right = delMininum(x->right);

    x->count = 1 + size(x->left) + size(x->right);
    return x; 
}

template <typename Key, typename Value>
void BST<Key,Value>::delNode(Key key) {
    root = delNode(root, key);
}

template <typename Key, typename Value>
shared_ptr<typename BST<Key,Value>::Node>
BST<Key,Value>::delNode(shared_ptr<Node> x, Key key) {
    if(x == nullptr) return nullptr;
    int compare = (key - x->key);
    if(compare < 0) x->left = delNode(x->left, key);
    else if(compare > 0) x->right = delNode(x->right, key);
    else {
        if(x->right == nullptr) return x->left;
        if(x->left == nullptr) return x->right;

        auto t = x;
        x = minimum(t->right);
        x->right = delMininum(x->right);
        x->left = t->left;
    }
    x->count = 1 + size(x->left) + size(x->right);
    return x;
}
