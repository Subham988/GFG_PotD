class Solution{
    static int ladoos(Node root, int home, int k){
        // Your code goes here
           Map<Node, Node> map = new HashMap<>();
        Queue<Node> q = new LinkedList<>();
        map.put(root, null);
        q.add(root);
        Node bheemsHome = null;
        
        while(!q.isEmpty()){
            int size = q.size();
            while(size-- > 0){
                Node curr = q.poll();
                if(curr.data == home){
                    bheemsHome = curr;
                }
                if(curr.left != null){
                    map.put(curr.left, curr);
                    q.add(curr.left);
                }
                
                if(curr.right != null){
                    map.put(curr.right, curr);
                    q.add(curr.right);
                }
            }
        }
        
        
         Queue<Pair> bheem = new LinkedList<>();
        bheem.add(new Pair(bheemsHome, 0));
        // bheem.add(bheemsHome);
        int ans = 0;
        Set<Node> visited = new HashSet<>();
        visited.add(bheemsHome);
        
        while(!bheem.isEmpty()){
            int size = bheem.size();
            while(size-- > 0){
                Pair curr = bheem.poll();
                ans += curr.node.data;
                if(curr.node.left != null && curr.dist < k && !visited.contains(curr.node.left)){
                    bheem.add(new Pair(curr.node.left, curr.dist+1));
                    visited.add(curr.node.left);
                }
                
                if(curr.node.right != null && curr.dist < k && !visited.contains(curr.node.right)){
                    bheem.add(new Pair(curr.node.right, curr.dist+1));
                    visited.add(curr.node.right);
                }
                
                if(map.get(curr.node) != null && curr.dist < k && !visited.contains(map.get(curr.node))){
                    bheem.add(new Pair(map.get(curr.node), curr.dist+1));
                    visited.add(map.get(curr.node));
                }
            }
        }
        return ans;
    }
}
class Pair{
    Node node;
    int dist;
    
    Pair(Node n, int d){
        node = n;
        dist = d;
    }
}
