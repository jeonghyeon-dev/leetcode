class Solution {
public:
    
    map<char, string> buttons = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };
    
    vector<string> ans;
    
    vector<string> letterCombinations(string digits) {
        
        if (digits.length() == 0) 
            return ans;
        
        search(digits,"", 0);
        
        return ans;
    }
    
    void search(string digits, string currentLetters, int idx) {
        
        // base case
        if(idx == digits.length()){
            ans.push_back(currentLetters);
            return;
        }
        
        char currentButton = digits[idx];
        string letter = buttons[currentButton];
        for(int i = 0; i < letter.length();i++){
            search(digits, currentLetters + letter[i], idx + 1);
        }
    }
};