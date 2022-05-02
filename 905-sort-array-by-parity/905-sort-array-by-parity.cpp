class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> evenArray, oddArray;
        
        for(int num : nums){
            if(num%2 == 0)
                evenArray.push_back(num);
            else
                oddArray.push_back(num);
        }
        
        for(int oddNum : oddArray)
            evenArray.push_back(oddNum);
        
        return evenArray;
    }
};