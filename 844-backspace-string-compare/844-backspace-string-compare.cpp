class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> firstStack, secondStack;
        // O(n)
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '#'){
                if(firstStack.empty()) continue;
                firstStack.pop();
                continue;
            }
            firstStack.push(s[i]);
        }
        
        for(int i = 0; i < t.length(); i++){
            if(t[i] == '#'){
                if(secondStack.empty()) continue;
                secondStack.pop();
                continue;
            }
            secondStack.push(t[i]);
        }
        
        if(firstStack.empty() && secondStack.empty()) return true;
        
        if(firstStack.size() != secondStack.size()) return false;
        
        while(!firstStack.empty()){
            
            if(firstStack.top() != secondStack.top())
                return false;
            
            firstStack.pop();
            secondStack.pop();
        }
        
        return true;
        
    }
};