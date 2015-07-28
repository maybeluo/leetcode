// A smart version: https://leetcode.com/discuss/44106/short-o-1-amortized-c-java-ruby
// O(1) amortized, impressive.
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stackOrder.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        peek(); // keep the queueOrder stack non-empty
        if( !queueOrder.empty() )
            queueOrder.pop();
    }

    // Get the front element.
    int peek(void) {
        if( queueOrder.empty() ) {
            while( !stackOrder.empty() ) {
                queueOrder.push( stackOrder.top() );
                stackOrder.pop();
            }
        }
        if( !queueOrder.empty() )
            return queueOrder.top();
        return -1;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stackOrder.empty() && queueOrder.empty();
    }
    
private:
    stack<int> stackOrder, queueOrder; // in stack order, in queue order 
};


// ungly version wrote by me...

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        
        stack<int> tmpStack;
        while( !tmpStack.empty() ) tmpStack.pop();
        while( !myStack.empty() ) {
            int t = myStack.top();
            tmpStack.push(t);
            myStack.pop();
        }
        myStack.push(x);
        while( !tmpStack.empty() ) {
            int t = tmpStack.top();
            myStack.push(t);
            tmpStack.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if( !myStack.empty() )
            myStack.pop();
    }

    // Get the front element.
    int peek(void) {
        if( !myStack.empty() )
            return myStack.top();
        return -1;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return myStack.empty();
    }
    
private:
    stack<int> myStack;
};
