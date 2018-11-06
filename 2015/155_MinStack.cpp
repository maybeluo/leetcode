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


// another solution
class MinStack {
public:
    MinStack() {
        mx = 0x7fffffff;
        while(!s.empty()) s.pop();
    }
    
    void push(int x) {
        mx = min(x, mx);
        s.push( make_pair(x, mx) );
    }

    void pop() {
        s.pop();
        if(!s.empty())
            mx = s.top().second;
        else 
            mx = 0x7fffffff;
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }
    
private:
    int mx;
    stack< pair<int, int> > s;
};
