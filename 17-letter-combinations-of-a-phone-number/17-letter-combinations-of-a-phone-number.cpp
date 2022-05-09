class Solution {
public:
    
    string buttons[11] = {"",
                         "","abc","def",
                         "ghi","jkl","mno",
                         "pqrs","tuv","wxyz"};
    
    int visited[11][4] = {0, };
    vector<string> ans;
    
    vector<string> letterCombinations(string digits) {
        
        if (digits.length() == 0) 
            return ans;
        
        for(int i = 0; i < buttons[digits[0] - '0'].length(); i++){
            search(digits, "", 0, i);
            memset(visited,0,sizeof(visited));
        }
        
        return ans;
    }
    
    void search(string digits, string letters, int digitIdx, int letterIdx) {
        
        int button = digits[digitIdx] - '0';
        visited[digitIdx][letterIdx] = 1;
        letters += buttons[button][letterIdx];
        
        // base case
        if(letters.length() == digits.length()){
            ans.push_back(letters);
            return;
        }
        
        for(int i = digitIdx + 1; i < digits.length();i++){
            
            int nextButton = digits[i] - '0';
            
            for(int j = 0; j < buttons[nextButton].length(); j++){
                
                if(visited[i][j]) continue;
                
                search(digits, letters, i, j);
                visited[i][j] = 0;
            }
        }
    }
};