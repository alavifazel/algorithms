/* > Binary Search Tree (BST) implementation in (modern) C++
 */


#ifndef BST_HEADER
#define BST_HEADER

#include <memory>
#include <queue>

using std::shared_ptr;
using std::make_shared;
using std::queue;

namespace BST {
    template <typename KeyType, typename ValueType>
    class BST {
        private:
        struct Node; // forward decl

        public:
            BST();
            void put(KeyType key, ValueType value);
            ValueType get(KeyType key);
            void remove(KeyType key);
            shared_ptr<Node> maximum(shared_ptr<Node> x);
            shared_ptr<Node> maximum();
            shared_ptr<Node> minimum(shared_ptr<Node> x);
            shared_ptr<Node> minimum();
            KeyType floor(KeyType key);
            KeyType ceiling(KeyType key);
            size_t size() { return root.size(); } 
            size_t rank(KeyType key);
            queue<KeyType> keys();

            void delMininum();
            void delMaximum();
            void delNode(KeyType key);
        private:
            shared_ptr<Node> root;

            size_t size(shared_ptr<Node> x){ return (x == nullptr ? 0 : x->count); } // ?
            shared_ptr<Node> put(shared_ptr<Node> x, KeyType key, ValueType value);

            shared_ptr<Node> floor(KeyType key, shared_ptr<Node> x);
            shared_ptr<Node> ceiling(KeyType key, shared_ptr<Node> x);

            size_t rank(KeyType key, shared_ptr<Node> x); 
            void inorder_traversal(shared_ptr<Node>, queue<KeyType> &q);
            
            shared_ptr<Node> delMininum(shared_ptr<Node> x);
            shared_ptr<Node> delMaximum(shared_ptr<Node> x);
            shared_ptr<Node> delNode(shared_ptr<Node> x, KeyType key);
    };

    template <typename KeyType, typename ValueType>
    struct BST<KeyType,ValueType>::Node {
            Node(){}
            Node(KeyType key, ValueType value): key(key), value(value), left(nullptr), right(nullptr) {}

            KeyType key;
            ValueType value;
            shared_ptr<Node> left, right;

            // Count variable keeps track of number of connected nodes beneath our node.
            // It simplifies the implemenation of size() and rank() methods.
            size_t count;
    };

    #include "BST_impl.h"
}

#endif
