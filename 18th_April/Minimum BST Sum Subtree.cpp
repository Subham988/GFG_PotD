class Solution {
public:

    int f(Node * root, int & sum,int & minlen,int& mini,int &maxi, bool &flag, int target){
        if (root==NULL)
            return 0;
        int rightsum=0,leftsum=0;
        bool rightflag=true, leftflag=true;
        int rightmini=1e9,leftmini=1e9;
        int rightmaxi=-1e9,leftmaxi=-1e9;
        
        int leftlen=f(root->left,leftsum,minlen,leftmini,leftmaxi,leftflag,target);
        int rightlen=f(root->right,rightsum,minlen,rightmini,rightmaxi,rightflag,target);
        
        sum=root->data+leftsum+rightsum;
        int currlen=leftlen+rightlen+1;
        maxi=max(root->data,max(rightmaxi,leftmaxi));
        mini=min(root->data,min(rightmini,leftmini));
        
        flag=false;
        if(root->data>leftmaxi && root->data<rightmini && leftflag && rightflag){
            flag=true;
        }
        if(currlen <minlen && target==sum && flag)
        {
            minlen=currlen;
        }
        return currlen;
    }
    int minSubtreeSumBST(int target, Node *root) {
        // code here
        int sum=0,minlen=1e9,mini=1e9,maxi =-1e9;
        bool flag=true;
        f(root,sum,minlen,mini,maxi,flag,target);
        
        return minlen==1e9 ? -1 : minlen;
    }
};