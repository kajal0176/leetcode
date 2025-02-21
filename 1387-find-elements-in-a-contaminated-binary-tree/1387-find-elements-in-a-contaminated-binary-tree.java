/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class FindElements {
  TreeNode root;
  HashSet<Integer>hs=new HashSet<>();
    public FindElements(TreeNode root) {
        this.root=root;
        TreeNode curr=this.root;
        root.val=0;
        Queue<TreeNode>q=new LinkedList<>();
        q.add(curr);
        hs.add(0);
        while(q.size()>0){
            int n=q.size();
            //TreeNode nd=q.remove();
             for(int i=0;i<n;i++){
                TreeNode nd=q.remove();
                hs.add(nd.val);
                int v=nd.val;
                if(nd.left!=null){
                    nd.left.val=2*v+1;
                    q.add(nd.left);
                }
                if(nd.right!=null){
                    nd.right.val=2*v+2;
                    q.add(nd.right);
                }
             }
        }
    }
    
    public boolean find(int target) {
        if(hs.contains(target)){
            return true;
        }
        return false;
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */