//226. Invert Binary Tree - https://leetcode.com/problems/invert-binary-tree/description/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL || (root->left == NULL & root->right == NULL)return root;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
    }
};


//104. Maximum Depth of Binary Tree - https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)return 0;
        int lr = maxDepth(root->left);
        int ri = maxDepth(root->right);
        return 1 + max(lr,ri);
    }
};

//543. Diameter of Binary Tree - https://leetcode.com/problems/diameter-of-binary-tree/description/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)return 0;
        int diameter = 0;
        treeHeight(root,diameter)
        return diameter;
    }

    int treeHeight(TreeNode* root, int& diameter)
    {
        if(root == NULL)return diameter;
        int lf = treeHeight(root->left,diameter);
        int ri = treeHeight(root->right,diameter);
        int diameter = max(diameter,lf+ri);
        return 1 + max(lf,ri);
    }
};

//110. Balanced Binary Tree - https://leetcode.com/problems/balanced-binary-tree/description/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1
    }

    int checkBalance(TreeNode* root)
    {
        if(root == NULL)return 0;
        int lf = checkBalance(root->left);
        if(lf == -1)return -1;
        int ri = checkBalance(root->right);
        if(ri == -1)return -1;
        if(abs(lf - ri) > 1)return -1;
        return 1 + max(lf,ri);

    }
};


//100. Same Tree - https://leetcode.com/problems/same-tree/description/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)return true;
        if(!p || !q)return false;
        if(p->val != q->val)return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

//572. Subtree of Another Tree - https://leetcode.com/problems/subtree-of-another-tree/description/
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL)return false;
        if(checkEqual(root,subRoot))return true
        return isSubtree(root->right,subRoot) || isSubtree(root->left,subRoot);
    }
    
    bool checkEqual(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL)return true;
        else if(root == NULL || subRoot == NULL)return false;
        else if(root->val != subRoot->val)return false;
        else
        {
            return checkEqual(root->left,subRoot->left) && checkEqual(root->right,subRoot->right);
        }
    }
};


//235. Lowest Common Ancestor of a Binary Search Tree - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)return root;
        TreeNode* left = lowestCommonAncestor(root->left,  p,  q);
        TreeNode* right = lowestCommonAncestor( root->right,  p,  q);
        if(left == NULL)
            return right;
        else if(right == NULL)
            return left;
        else
            return root;
        
    }
};


//102. Binary Tree Level Order Traversal - https://leetcode.com/problems/binary-tree-level-order-traversal/description/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<int> q;
        if(root == NULL)return null;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for(int i = 0 ; i< size; i++)
            {
                TreeNode* temp = q.first();
                q.push(temp->left,temp->right);
                q.pop();
                level.push(temp->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};


//199. Binary Tree Right Side View - https://leetcode.com/problems/binary-tree-right-side-view/description/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)return {};
        queue<TreeNode*> q;
        while(!q.empty())
        {
            int size =  q.size();
            bool flag = true;
            for(int i = 0 ; i < size; i++)
            {
                auto t = q.front();
                q.pop();
                if(flag)
                {
                    flag = false;
                    ans.push_back(t->val);
                }
                if(t->right)q.push_back(t->right);
                if(t->left)q.push_back(t->left);
            }
        }
        return ans;
    }
};


//1448. Count Good Nodes in Binary Tree - https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
class Solution {
public:
    int dfs(TreeNode* root, int maxVal) {
        if(root == NULL) return 0;
        int res = 0;
        if(root->val >= maxVal) {
            res = 1;
            maxVal = root->val;
        }
        res += dfs(root->left, maxVal);
        res += dfs(root->right, maxVal);
        return res;
    }
    
    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return dfs(root, root->val);
    }
};

//98. Validate Binary Search Tree - https://leetcode.com/problems/validate-binary-search-tree/description/

class Solution {
public:
    bool dfs(TreeNode* root, long long minVal, long long maxVal) {
        if (root == NULL) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return dfs(root->left, minVal, root->val) && dfs(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};

//230. Kth Smallest Element in a BST - https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

class Solution
{
    public:

    void inorder(Node *root, int K, int& cnt, int& ans)
    {
        if(root == NULL)return;
        inorder(root->right,K,cnt,ans);
        cnt++;
        if(cnt==K)
        {
            ans = root->data;
            return; 
        }
        inorder(root->left,K,cnt,ans);
    }



    int kthLargest(Node *root, int K)
    {
        if(root == NULL)return -1;
        int cnt = 0;
        int ans = -1;
        inorder(root,K,cnt,ans);
        return ans;
    }
};


//124. Binary Tree Maximum Path Sum - https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
class Solution {
public:

    int solve(TreeNode* root, int& maxi)
    {
        if(root == NULL)return NULL;
        int li = max(0,solve(root->left,maxi));
        int ri = max(0,solve(root->right,maxi));
        maxi = max(maxi,li + ri + root->val);
        return root->val + max(li,ri);
    }


    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};

//105. Construct Binary Tree from Preorder and Inorder Traversal - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd,map<int,int>m)
    {
        if(preStart > preEnd || inStart > inEnd)return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = m[root->val];
        int numsLeft = inRoot - inStart;
        root->left = solve(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1,m);
        root->right = solve(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd,m);
        return root;
    }



    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart = 0, preEnd = preorder.size()-1;
        int inStart = 0, inEnd = inorder.size()-1;
        map<int,int> m;
        for(int i = 0; i < preorder.size(); i++)
            m[inorder[i]] = i;
        TreeNode* root = solve(preorder,preStart,preEnd,inorder,inStart,inEnd,m);
        return root;
    }
};

//297. Serialize and Deserialize Binary Tree - https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp == NULL) {
                ans += "#,";
            } else {
                ans += to_string(temp->val) + ',';
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            // Left child
            if (getline(s, str, ',')) {
                if (str == "#") {
                    temp->left = NULL;
                } else {
                    TreeNode* leftNode = new TreeNode(stoi(str));
                    temp->left = leftNode;
                    q.push(leftNode);
                }
            }

            // Right child
            if (getline(s, str, ',')) {
                if (str == "#") {
                    temp->right = NULL;
                } else {
                    TreeNode* rightNode = new TreeNode(stoi(str));
                    temp->right = rightNode;
                    q.push(rightNode);
                }
            }
        }
        return root;
    }
};

