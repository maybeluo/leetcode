// use a vector 'minPos' to record: the minimum value index in stack.
//  when push a new element into stack, if the new value is LESS than the current min, 
//    PUT its index into 'minPos'.
//  otherwise, just push it to the stack.

class MinStack {
public:
    vector<int> v, minPos;
    MinStack() {
        v.clear();
        minPos.clear();
    }
    
    void push(int x) {
        v.push_back(x);
        if( minPos.empty() || v[ minPos.back() ] >= x ) {
            minPos.push_back( v.size() - 1 );
        }
    }

    void pop() {
        if(v.empty()) return ;
        v.pop_back();
        if( minPos.back() >= v.size() ) {
            minPos.pop_back();
        }
    }

    int top() {
        if(v.empty()) return -1;
        return v.back();
    }

    int getMin() {
        if( minPos.empty() ) return -1;
        return v[ minPos.back() ];
    }
};
