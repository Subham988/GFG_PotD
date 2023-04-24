class Solution{
	int [] nearestSmallestTower(int [] arr){
		//Write your code here
			int[] ans = new int[arr.length];
		
		Stack<Integer> stk1 = new Stack<>();
		
		for(int i=0; i<arr.length; i++){
		    
		    while(!stk1.empty()){
		        if(arr[stk1.peek()] >= arr[i]){
		            stk1.pop();
		        }
		        else{ break; }
		    }
		    if(stk1.empty()){ ans[i] = Integer.MAX_VALUE; }
		    else{ ans[i] = stk1.peek(); }
		    stk1.push(i);
		    
		}
		
		
		Stack<Integer> stk2 = new Stack<>();
		
		for(int i=arr.length-1; i>=0; i--){
		    
		    while(!stk2.empty()){
		        if(arr[stk2.peek()] >= arr[i]){
		            stk2.pop();
		        }
		        else{ break; }
		    }
		    if(!stk2.empty()){ 
		        
		        if(ans[i] == Integer.MAX_VALUE){ ans[i] = stk2.peek(); }
		        else{
		            int dis1 = i-ans[i];
		            int dis2 = stk2.peek()-i;
		            
		            if(dis1 > dis2){
		                ans[i] = stk2.peek();
		            }
		            else if(dis1 == dis2){
		                if(arr[ans[i]] > arr[stk2.peek()]){ ans[i] = stk2.peek(); }
		            }
		        }
		    }
		    stk2.push(i);
		    
		}
		
		for(int i=0; i<arr.length; i++){
		    if(ans[i] == Integer.MAX_VALUE){ ans[i] = -1; }
		}
		
		return ans;
	}
}