class Solution {
    public:
        void trycombination(int open,int close,vector<string>&res,string str) {
           if(open ==0 && close == 0) {
            res.push_back(str);
            return ;
           }
    
           if(open> 0 ) {
            str.push_back('(');
            trycombination(open-1,close,res,str);
            str.pop_back();
           }
           if(open<close && close >0) {
            str.push_back(')');
            trycombination(open,close-1,res,str);
            str.pop_back();
           }
        }
        vector<string> generateParenthesis(int n) {
            vector<string>res;
            trycombination(n,n,res,"");
            return res;
        }
    };