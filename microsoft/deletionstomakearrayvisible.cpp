class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) 
    {
        //first off we sort both the vectors , it makes the divisibility checking more efficient and the number of deletions easier
        sort(nums.begin(), nums.end());
        sort(numsDivide.begin(), numsDivide.end());
        int count=0;
        int gcd=numsDivide[0];
        // the concept of greatest common divisor is used here as, if the number in our array is divisible by the entire numsDivide vector then it is also divisible by its gcd and this method further reduces the number of loops to check divisibility exponentially.
        for(int i=1; i<numsDivide.size(); i++){
            gcd=__gcd(gcd,numsDivide[i]);
        }
        for(int i=0; i<nums.size(); i++){
            if(gcd%nums[i]==0)
            {
                return count;
            }
            count++;
        }
        return -1;
    }
};