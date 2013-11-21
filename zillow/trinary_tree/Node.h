#ifndef NODE_H
#define NODE_H

#ifndef NULL
#define NULL 0
#endif

class Node {
    public:
        Node(const int& new_value);
        ~Node();

        void setValue(int value);
        void setLeftChild(Node* left);
        void setMiddleChild(Node* middle);
        void setRightChild(Node* right);

        int getValue() const;
        Node*& getLeftChild();
        Node*& getMiddleChild();
        Node*& getRightChild();

    private:
        int m_value;
        Node* m_left;
        Node* m_middle;
        Node* m_right;

        const Node& operator=(const Node&);
        Node(const Node&);
};

#endif
