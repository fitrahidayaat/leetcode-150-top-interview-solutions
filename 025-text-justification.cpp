class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        string temp = "";
        vector<vector<string>> strvec; 
        for(int i = 0; i < n; i++) {
            if(temp.size() + words[i].size() < maxWidth) {
                if(temp == "") {
                    temp = words[i];
                    strvec.push_back({words[i]});
                }
                else {
                    temp = temp + " " + words[i];
                    strvec[strvec.size() - 1].push_back(words[i]);
                }
            } else {
                strvec.push_back({words[i]});
                temp = words[i];
            }
        }
        
        for(int i = 0; i < strvec.size(); i++) {
            int len = strvec[i].size();
            int countWords = 0;
            for(int j = 0; j < len; j++) {
                countWords += strvec[i][j].size();
            }
            
            if(i == strvec.size() - 1 || strvec[i].size() == 1) {
                string temp = "";
                for(int j = 0; j < len; j++) {
                    if(temp == "") {
                        temp = strvec[i][j];
                    } else {
                        temp = temp + " " + strvec[i][j];
                    }
                }
                
                int leftOver = maxWidth - temp.size();
                for(int j = 0; j < leftOver; j++) temp += ' ';
                ans.push_back(temp);
            } else {
                int space = maxWidth - countWords;
                int gap = space/(len-1);
                int left = space%(len-1);
                
                string temp = "";
                
                for(int j = 0; j < len; j++) {
                    if(temp == "") {
                        temp = strvec[i][j];
                    } else if(left) {
                        for(int k = 0; k < gap + 1; k++) {
                            temp += " ";
                        }
                        temp += strvec[i][j];
                        left--;
                    } else {
                        for(int k = 0; k < gap; k++) {
                            temp += " ";
                        }
                        temp += strvec[i][j];
                    }
                }

                ans.push_back(temp);
            }
        }
        return ans;
    }
};