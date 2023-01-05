class Solution {
public:
    string getHint(string secret, string guess) 
    {
        unordered_map<int,int> bullsmap;
        unordered_map<int,int> cowsmap;
        long int bulls=0,cows=0;
        for(int i=0;i<secret.length();i++)
        {
                if(secret[i]==guess[i])
                            bulls++;
                else    
                {
                    bullsmap[secret[i]]++;
                    cowsmap[guess[i]]++;
                }
        }
        for(int i=0;i<100;i++)
        {
            cows+=min(bullsmap[i],cowsmap[i]);
        }
        string ans=to_string(bulls)+"A"+to_string(cows)+"B";
        return ans;
    }
        
};