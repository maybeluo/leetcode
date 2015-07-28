class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        myQueue.push(x);
        int n = myQueue.size();
        for(int i = 1; i < n; i++ ) {
            int tmp = myQueue.front();
            myQueue.pop();
            myQueue.push(tmp);
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if( !myQueue.empty() )
            myQueue.pop();
    }

    // Get the top element.
    int top() {
        if( !myQueue.empty() )
            return myQueue.front();
        else return -1;
    }

    // Return whether the stack is empty.
    bool empty() {
        return myQueue.empty();
    }
    
    Stack() {}
    
private:
    queue<int> myQueue;
};
