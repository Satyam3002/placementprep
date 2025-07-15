class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;
        stack<int> st;
        for(int i =0;i<operations.size();i++) { 
            if( operations[i] != "+" && operations[i] != "D" && operations[i] != "C") {
                st.push(stoi(operations[i]));
            }
            else if ( operations[i] == "D") {
                st.push(2*st.top());
            } else if( operations[i]=="C") {
                st.pop();
            }  else {
               int first = st.top(); st.pop();
                int second = st.top();
                st.push(first);                 
                st.push(first + second);  
            }
            
        }
        
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;

    }
};