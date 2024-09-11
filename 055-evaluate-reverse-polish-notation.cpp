class Solution {
public:
    bool notOperator(string token) {
        return token != "+" && token != "-" && token != "*" && token != "/";
    }
    string evaluate(string num1, string num2, string operation) {
        int x = stoi(num1);
        int y = stoi(num2);
        int ans = 0;
        if(operation == "+") {
            ans = x + y;
        } else if(operation == "-") {
            ans = x - y;
        } else if(operation == "*") {
            ans = x*y;
        } else {
            ans = x/y;
        }
        
        return to_string(ans);
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        int n = tokens.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(notOperator(tokens[i])) {
                s.push(tokens[i]);
            } else {
                string num2 = s.top();
                s.pop();
                string num1 = s.top();
                s.pop();
                s.push(evaluate(num1, num2, tokens[i]));
            }
        }
        
        return stoi(s.top());
    }
};