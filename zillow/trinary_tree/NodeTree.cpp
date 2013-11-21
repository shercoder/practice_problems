#include "NodeTree.h"

#include <iostream>
using std::cout;

NodeTree::NodeTree() : m_root(NULL) {}

NodeTree::~NodeTree() {
    clearTree(m_root);
}

bool NodeTree::isEmpty() const {
    return (m_root == NULL);
}

void NodeTree::insert(const int& new_data) {
    insertNode(m_root, new_data);
}

bool NodeTree::remove(const int& target) {
    if (isEmpty()) return false;
    return removeNode(m_root, m_root, target);
}

/**
 * Caveat: Only problem with this solution is that the middle child will
 *          look like a singly linked list if continue to get the same value.
 */
void NodeTree::insertNode(Node*& subroot, const int& new_data) {
    if (subroot == NULL) {
        subroot = new Node(new_data);
    } else {
        if (new_data < subroot->getValue()) {
            insertNode(subroot->getLeftChild(), new_data);
        } else if (new_data == subroot->getValue()) {
            insertNode(subroot->getMiddleChild(), new_data);
        } else {
            insertNode(subroot->getRightChild(), new_data);
        }
    }
}

bool NodeTree::removeNode(Node*& subroot, Node*& parent, const int& target) {
    if (subroot == NULL) {
        return false;
    } else if (target < subroot->getValue()) {
        return removeNode(subroot->getLeftChild(), subroot, target);
    } else if (target > subroot->getValue()) {
        return removeNode(subroot->getRightChild(), subroot, target);
    } else {
        // Go all the way down until find the last middle node and then delete it
        if (subroot->getMiddleChild() != NULL) {
            Node* nodeToDelete = subroot;
            while(nodeToDelete->getMiddleChild() != NULL) {
                parent = nodeToDelete;
                nodeToDelete = nodeToDelete->getMiddleChild();
            }
            delete nodeToDelete;
            nodeToDelete = NULL;
            parent->setMiddleChild(NULL);
        } else if (subroot->getRightChild() != NULL) {
            // find replacement value and then delete replacement node
            Node *successor = findSuccessor(subroot->getRightChild());
            subroot->setValue(successor->getValue());
            return removeNode(subroot->getRightChild(), subroot, subroot->getValue());
        } else {
            // no middle or right
            // simply delete the node and make it's left child the subroot (root)
            Node* nodeToDelete = subroot;
            subroot = subroot->getLeftChild();
            delete nodeToDelete;
            nodeToDelete = NULL;
        }
    }
    return true;
}

Node* NodeTree::findSuccessor(Node* subroot) {
    // find the smallest child from the right side to replace current root
    if (subroot != NULL) {
        Node* nodeToFind = subroot;
        while(nodeToFind->getLeftChild() != NULL) {
            nodeToFind = nodeToFind->getLeftChild();
        }
        return nodeToFind;
    }
    return subroot;
}

void NodeTree::print() {
    inOrderTraverse(m_root);
}

void NodeTree::inOrderTraverse(Node* subroot) {
    if (subroot != NULL) {
        inOrderTraverse(subroot->getLeftChild());
        inOrderTraverse(subroot->getMiddleChild());
        cout << subroot->getValue() << ' ';
        inOrderTraverse(subroot->getRightChild());
    }
}

void NodeTree::clearTree(Node* subroot) {
    if (subroot != NULL) {
        clearTree(subroot->getLeftChild());
        clearTree(subroot->getMiddleChild());
        clearTree(subroot->getRightChild());
        delete subroot;
        subroot = NULL;
    }
}