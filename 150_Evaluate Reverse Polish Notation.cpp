Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


  class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int len=tokens.size();
        for(int i=0;i<len;i++)
        {
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/")
            {
                st.push(atoi(tokens[i].c_str()));
            }
            else
            {
                if(tokens[i]=="+")
                {
                    int a,b;
                    a=st.top();
                    st.pop();
                    b=st.top();
                    st.pop();
                    st.push(b+a);
                }
                else if(tokens[i]=="-")
                {
                    int a,b;
                    a=st.top();
                    st.pop();
                    b=st.top();
                    st.pop();
                    st.push(b-a);
                }
                else if(tokens[i]=="*")
                {
                    int a,b;
                    a=st.top();
                    st.pop();
                    b=st.top();
                    st.pop();
                    st.push(b*a);
                }
                else if(tokens[i]=="/")
                {
                    int a,b;
                    a=st.top();
                    st.pop();
                    b=st.top();
                    st.pop();
                    int c=b/a;
                    st.push(c);
                }
            }
        }
        return st.top();
    }
};