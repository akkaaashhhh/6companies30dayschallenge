class Solution {
public:
    int maxRotateFunction(vector<int>& nums) 
    {
            int n=nums.size();
            int arrsum=0,sumofrots=0;
            for(int i=0;i<n;i++)
                {
                    arrsum+=nums[i];    //this calculates the sum of the elements in the array
                    sumofrots+=nums[i]*i; //calculates sum of f(0)
                }
            int maximumsum=sumofrots; // we set that as the initial maximum sum
            for(int i=0;i<n;i++)
            {
                sumofrots+=(arrsum-nums[n-i-1]*n); //calculate the sum of the new f(n) in reference with f(n-1) 
                maximumsum=max(maximumsum,sumofrots); // check if that is a higher maximum than our current maximum
            }
            return maximumsum;
    }
};