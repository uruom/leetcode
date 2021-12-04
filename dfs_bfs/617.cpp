/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void copy_root(TreeNode* tr,TreeNode* trc)
    {
        trc->val=tr->val;
        if(tr->right!=NULL)
        {
            TreeNode* trcr=(TreeNode*)malloc(sizeof(TreeNode)/sizeof(char));
            trcr->right=NULL;
            trcr->left=NULL;
            trc->right=trcr;
            copy_root(tr->right,trcr);
        }
        if(tr->left!=NULL)
        {
            TreeNode* trcl=(TreeNode*)malloc(sizeof(TreeNode)/sizeof(char));
            trcl->right=NULL;
            trcl->left=NULL;
            trc->left=trcl;
            copy_root(tr->left,trcl);
        }
    } 
    void add_root(TreeNode* tr1,TreeNode* tr2,TreeNode* tr)
    {
        if(tr1!=NULL&&tr2!=NULL)
        {
            tr->val=tr1->val+tr2->val;
            if(tr1->left!=NULL||tr2->left!=NULL)
            {
                TreeNode* trl=(TreeNode*)malloc(sizeof(TreeNode)/sizeof(char));
                trl->right=NULL;
                trl->left=NULL;
                tr->left=trl;
                add_root(tr1->left,tr2->left,trl);
            }
            if(tr1->right!=NULL||tr2->right!=NULL)
            {
                TreeNode* trr=(TreeNode*)malloc(sizeof(TreeNode)/sizeof(char));
                trr->right=NULL;
                trr->left=NULL;
                tr->right=trr;
                add_root(tr1->right,tr2->right,trr);
            }
        }
        else
        {
            if(tr1==NULL&&tr2==NULL)
            return ;
            else if(tr1==NULL)
                     copy_root(tr2,tr);
                 else
                     copy_root(tr1,tr);
        }

    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode)/sizeof(char));
        root->right=NULL;
        root->left=NULL;
        if(root1==NULL&&root2==NULL)
        return NULL;
        else
        add_root(root1,root2,root);
        return root;
        //创建树的节点的时候，注意有(TreeNode*)malloc(sizeof(TreeNode)/sizeof(char))，不能直接给
        //同时树节点如果有后续的节点，比如next，right,left之类的，要先赋值为空~？
        //其实不太理解为什么不可以直接用
    }
};
