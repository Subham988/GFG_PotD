class Solution{
public:
    unordered_set<int> solve(Node* root, int k, int &ans){
        unordered_set<int> st;
        if(!root) return st;
        unordered_set<int> left=solve(root->left,k,ans);
        unordered_set<int> right=solve(root->right,k,ans);
        st.insert(left.begin(),left.end());
        st.insert(right.begin(),right.end());
        
        st.insert(root->data);
        
        if(st.size()<=k) ans++;
        return st;
    }
    int goodSubtrees(Node *root,int k){
        int ans=0;
        solve(root, k, ans);
        return ans;
    }
};