#ifndef NODE_TREE_H
#define NODE_TREE_H

#include "Node.h"

class NodeTree {
    public:
        NodeTree();
        ~NodeTree();

        bool isEmpty() const;
        void insert(const int& new_data);
        bool remove(const int& target);
        void print();

    private:
        void insertNode(Node*& subroot, const int& new_data);
        bool removeNode(Node*& subroot, Node*& parent, const int& target);
        Node* findSuccessor(Node* subroot);
        void inOrderTraverse(Node* subroot);
        void clearTree(Node* subroot);

        const NodeTree& operator=(const NodeTree&);
        NodeTree(const NodeTree&);

        /* Private Variables */
        Node *m_root;
};

#endif