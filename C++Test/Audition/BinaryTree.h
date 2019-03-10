#ifndef BINARYTREE
#define BINARYTREE

/**
 * 实现简单二叉树类，实现插入，删除和后序遍历
 */

struct _Binary_Tree_Node_Base {
    typedef _Binary_Tree_Node_Base* base_node;
    base_node* parent;
    base_node* right;
    base_node* left;

    static min(base_node ptr)
    {
        while (ptr->left != nullptr) {
            ptr = ptr->left;
        }
        return ptr;
    }

    static max(base_node ptr) {
        while () {

        }
    }
};


template<class T>
struct _Binary_Tree_Node : public _Binary_Tree_Node_Base
{
    typedef _Binary_Tree_Node<T>* link_type;
    T value;
};

struct _Binary_Tree_Iterator_Base
{
    typedef _Binary_Tree_Node_Base::base_node base_ptr;
    base_ptr node;

    void increment()
    {
        if (node->right != nullptr) {
            node = node->right;
            while (node->left != nullptr) {
                node = node->left;
            }
        }
        else {
            base_ptr temp = node->parent;
            while (temp->right == node) {
                node = temp;
                temp = temp->parent;
            }

            if (node->right != temp) {
                node = temp;
            }
        }
    }

    void decrement()
    {
        while (node->left != nullptr) {

        }
    }

};





#endif // BINARYTREE

