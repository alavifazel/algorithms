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
    template <typename Key, typename Value>
    class BST {
        private:
        struct Node; // forward decl

        public:
            BST();
            void put(Key key, Value value);
            Value get(Key key);
            void remove(Key key);
            shared_ptr<Node> maximum(shared_ptr<Node> x);
            shared_ptr<Node> maximum();
            shared_ptr<Node> minimum(shared_ptr<Node> x);
            shared_ptr<Node> minimum();
            Key floor(Key key);
            Key ceiling(Key key);
            size_t size() { return root.size(); } 
            size_t rank(Key key);
            queue<Key> keys();

            void delMininum();
            void delMaximum();
            void delNode(Key key);
        private:
            shared_ptr<Node> root;

            size_t size(shared_ptr<Node> x){ return (x == nullptr ? 0 : x->count); } // ?
            shared_ptr<Node> put(shared_ptr<Node> x, Key key, Value value);

            shared_ptr<Node> floor(Key key, shared_ptr<Node> x);
            shared_ptr<Node> ceiling(Key key, shared_ptr<Node> x);

            size_t rank(Key key, shared_ptr<Node> x); 
            void inorder_traversal(shared_ptr<Node>, queue<Key> &q);
            
            shared_ptr<Node> delMininum(shared_ptr<Node> x);
            shared_ptr<Node> delMaximum(shared_ptr<Node> x);
            shared_ptr<Node> delNode(shared_ptr<Node> x, Key key);
    };

    template <typename Key, typename Value>
    struct BST<Key,Value>::Node {
            Node(){}
            Node(Key key, Value value): key(key), value(value), left(nullptr), right(nullptr) {}

            Key key;
            Value value;
            shared_ptr<Node> left, right;

            // Count variable keeps track of number of connected nodes beneath our node.
            // It simplifies the implemenation of size() and rank() methods.
            size_t count;
    };

    #include "BST_impl.h"
}

#endif
