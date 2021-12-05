/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void find_next(Node* tr)
    {
        if(tr->left!=NULL)
        {
            //if(tr->val==3) cout<<"aaaaa"<<endl;
            tr->left->next=tr->right;
            if(tr->next!=NULL)
            {
                tr->right->next=tr->next->left;
                find_next(tr->next);
            }
            
        }
    }
    void h_tree(Node* tr)
    {
        if(tr!=NULL)
        {
            find_next(tr);
            h_tree(tr->left);
        }
    }
    
    Node* connect(Node* root) {
        h_tree(root);
        return root;
    }
};
