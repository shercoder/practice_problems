#include "Node.h"

Node::Node(const int& new_value)
: m_value(new_value), m_left(NULL), m_middle(NULL), m_right(NULL)
{}

Node::~Node() {
}

void Node::setValue(int value) {
    m_value = value;
}

void Node::setLeftChild(Node* left) {
    m_left = left;
}

void Node::setMiddleChild(Node* middle) {
    m_middle = middle;
}

void Node::setRightChild(Node* right) {
    m_right = right;
}

int Node::getValue() const {
    return m_value;
}

Node*& Node::getLeftChild() {
    return m_left;
}

Node*& Node::getMiddleChild() {
    return m_middle;
}

Node*& Node::getRightChild() {
    return m_right;
}

