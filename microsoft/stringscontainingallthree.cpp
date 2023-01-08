class Solution 
{
        public:
        int numberOfSubstrings(string s) 
        {
            // this is a classic sliding window problem
            int ans=0,i=0,j=0; //here i is right pointer and j is left pointer
            vector<int>v(3,0);
            for(int i=0;i<s.length();i++)
            {
                v[s[i]-'a']++;
                while(v[0]>0 && v[1]>0 && v[2]>0 && i>=j)
                {
                    v[s[j]-'a']--;
                    ans+=s.length()-i;
                    j++;
                }
            }
            return ans;
        }
};