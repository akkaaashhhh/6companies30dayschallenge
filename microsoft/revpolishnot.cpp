class Solution {
public:
    int evalRPN(vector<string>& tokens)
     {
        stack<long> s;
        for(int i=0;i<tokens.size();i++)  
            {   
                if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/") // if its a operand we have to get the first two elements of the stack and do the operation//this if exists because only if it is an operand do we have to pop the first two elements in the stack
                {
                    long int a=s.top();
                    s.pop();
                    long int b=s.top();
                    s.pop();
                    if(tokens[i]=="+")
                        s.push(a+b);
                    else if(tokens[i]=="-")
                        s.push(b-a);
                    else if(tokens[i]=="*")
                        s.push(a*b);
                    else if(tokens[i]=="/")
                        s.push(b/a);
                }
                else // if its not an operand we just push the element into the stack after converting into integer using the stoi function in c++
                    s.push(stoi(tokens[i]));
            }
        return s.top();
    }

};