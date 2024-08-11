//121. Best Time to Buy and Sell Stock - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l  = 0 , r = 1;
        int mProfit = 0;
        while(r < prices.size())
        {
            if(prices[l] < prices[r])
            {
                int profit = prices[r] - prices[l];
                mProfit = max(profit,mProfit);
            }
            else
                l = r;
            r++;
        }
        return mProfit;
    }
};


//3. Longest Substring Without Repeating Characters - https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int n = s.length();
        int maxLength = 0;
        unordered_map<char, int> m;
        
        while (r < n) {
            if (m.find(s[r]) != m.end() && m[s[r]] >= l) {
                l = m[s[r]] + 1;
            }
            maxLength = max(maxLength, r - l + 1);
            m[s[r]] = r;
            r++;
        }
        
        return maxLength;
    }
};


//424. Longest Repeating Character Replacement - https://leetcode.com/problems/longest-repeating-character-replacement/description/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0 , right = 0, maxFrequency = 0, maxLen = 0;
        int hash[26] = {0};
        while(right < s.length())
        {
            hash[s[right] - 'A']++;
            if(hash[s[right]] - 'A' > maxFrequency)
            {
                maxFrequency = max(maxFrequency,hash[s[right] - 'A']);
            }
            if((right - left + 1) - maxFrequency > k )
            {
                hash[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen , right - left + 1);
            right++;
        }
        return maxLen; 
    }
};


//567. Permutation in String - https://leetcode.com/problems/permutation-in-string/
class Solution {
public:
    
    // check the window has all the characters present the str1
    
    bool is_check(vector<int>& mp1, vector<int>& mp2)
    {
        for(int i = 0; i < 26; i++)
        {
            if(mp1[i] != mp2[i])
                return false;
        }
        
        return true;
    }
    
    bool checkInclusion(string str1, string str2) {
        
        int n1 = str1.size();
        
        int n2 = str2.size();
        
        vector<int> mp1(26, 0);
        
        vector<int> mp2(26, 0);
        
        // store the count of all characters of str1 in mp1
        
        for(int i = 0; i < n1; i++)
        {
            mp1[str1[i] - 'a']++;
        }
        
        // apply sliding window
        
        // here we can take n1 as the size of sliding window
        
        for(int i = 0; i < n2; i++)
        {
            if(i < n1)
            {
                mp2[str2[i]- 'a']++;
            }
            else
            {
                if(is_check(mp1, mp2))
                    return true;
                
                mp2[str2[i - n1] - 'a']--;
                
                mp2[str2[i] - 'a']++;
            }
        }
        
        if(is_check(mp1, mp2))
            return true;
        
        return false;
    }
};

//76. Minimum Window Substring - https://leetcode.com/problems/minimum-window-substring/
class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> m;
        for(char c : t) {
            m[c]++;
        }

        int minLength = 1e9;
        int cnt = 0;
        int startPoint = 0;
        int l = 0, r = 0;

        while(r < s.length()) {
            if(m[s[r]] > 0) {
                cnt++;
            }
            m[s[r]]--; // Decrease the count for the character
            r++;

            while(cnt == t.length()) {
                if(minLength > r - l) {
                    minLength = r - l;
                    startPoint = l;
                }
                
                m[s[l]]++; // Restore the count of the left character
                if(m[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
        }

        if(minLength == 1e9) return ""; // No valid window found
        return s.substr(startPoint, minLength);
    }
};
//239. Sliding Window Maximum - https://leetcode.com/problems/sliding-window-maximum/description/
class Solution {
public:
vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            if(!q.empty() && q.front() == i - k)q.pop_front();
            while(!q.empty() && nums[q.back()] < nums[i])q.pop_back();
            q.push_back(i);
            if(i >= k - 1)ans.push_back(nums[q.front()]);

        }
        return ans;
    }
};