// version 1. 
// monotonous queue, Time complexity: O(n)

class Node {
public:
   int v;
   int p;
   
   Node(int _v, int _p): v(_v), p(_p) {}
   
   friend bool operator < (const Node& a, const Node& b) {
     return a.v < b.v;
   }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  vector<int> ans;
  ans.clear();
  int n = nums.size();
  if(n < 1) return ans;
  
  deque<Node> myDeque;
  while( !myDeque.empty() ) myDeque.pop_back();
  
  // process 0 - k-1, first window
  for(int i = 0; i < k - 1; i++) {
	while( !myDeque.empty() ) {
	  Node tb = myDeque.back();
	  if( tb.v <= nums[i] ) myDeque.pop_back();
	  else break;
	}
	Node nt(nums[i], i);
	myDeque.push_back(nt);
  }
  
  for(int i = k - 1; i < n; i++) {
	// push in current element
	while( !myDeque.empty() ) {
	  Node tb = myDeque.back();
	  if( tb.v <= nums[i] ) myDeque.pop_back();
	  else break;
	}
	Node nt(nums[i], i);
	myDeque.push_back(nt);
	
	while( !myDeque.empty() ) {
	  Node tp = myDeque.front();
	  if( tp.p < i - k + 1 ) myDeque.pop_front();
	  else break;
	}
	Node tp = myDeque.front();
	ans.push_back(tp.v);
  }
  return ans;
}


// version 2. 
// heap, O(n*lgk)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    ans.clear();
    int n = nums.size();
    if(n < 1) return ans;
    
    priority_queue<Node> myQueue;
    while( !myQueue.empty() ) myQueue.pop();
    
    int i, j;
    for(i = 0; i < k - 1; i++) {
      Node nt(nums[i], i);
      myQueue.push(nt);
    }
    for(i = k - 1; i < n; i++) {
      Node nt(nums[i], i);
      myQueue.push(nt);
      
      Node tp = myQueue.top();
      while( tp.p < (i - k + 1) ) {
        myQueue.pop();
        if( myQueue.empty() ) break;
        tp = myQueue.top();
      }
      ans.push_back(tp.v);
    }
    return ans;
}
