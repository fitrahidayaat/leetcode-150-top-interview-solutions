class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string cur = "";
        int n = path.size();
        int i = 0;

        while(i < n) {
            if(path[i] == '/') {
                if(cur == "..") {
                    if(!s.empty()) s.pop();
                } else if(cur != "" && cur != "."){
                    s.push(cur);
                }
                cur = "";
            } else {
                cur += path[i];
            }
            i++;
        }
        
        string ans = "";
        if(cur == "..") {
            if(!s.empty()) s.pop();
        } else if(cur != "" && cur != "."){
            s.push(cur);
        }
        
        while(!s.empty()) {
            if(ans == "") {
                ans = s.top();
            } else {
                ans = s.top() + "/" + ans;
            }
            
            s.pop();
        }
        return "/" + ans;
    }
};