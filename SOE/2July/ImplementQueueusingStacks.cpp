class MyQueue {
    public:
        stack<int>s1,s2;
        MyQueue() {
            
        }
        
        void push(int x) {
            s1.push(x);
        }
        
        int pop() {
          if(!s2.empty()) {
            int result = s2.top();
            s2.pop();
            return result;
          }
          else{
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            int result = s2.top();
            s2.pop();
            return result;
          }
        }
        
        int peek() {
            if (s2.empty()) {
                // Transfer all elements from s1 to s2 if s2 is empty
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            return s2.top();
    
        }
        
        bool empty() {
            return s2.empty()&& s1.empty();
        }
    };
    
    /**
     * Your MyQueue object will be instantiated and called as such:
     * MyQueue* obj = new MyQueue();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->peek();
     * bool param_4 = obj->empty();
     */