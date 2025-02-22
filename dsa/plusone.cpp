/*
here after declaring the class Solution, we have to write the function plusOne which takes a vector of integers 
as input and returns a vector of integers as output. The function should add 1 to the input vector and return 
the output vector. If the input vector is [1,2,3], the output vector should be [1,2,4]. If the input vector is [1,2,9],
 the output vector should be [1,3,0]. If the input vector is [9,9,9], the output vector should be [1,0,0,0].
*/

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int n = digits.size();
    
            for(int i=n-1;i>=0;i--){
                if(digits[i]<9){
                    digits[i]++;
                    return digits;
                }else{
                    digits[i] = 0;
                }
    
            }
            digits.insert(digits.begin(),1);
            return digits;
        }
    };