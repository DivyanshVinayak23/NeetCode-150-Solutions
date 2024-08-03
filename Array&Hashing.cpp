//Array & Hashing

//217. Contains Duplicate - https://leetcode.com/problems/contains-duplicate/description/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            if(m.find(nums[i]) != m.end())
                return true;
            m[nums[i]]++;
        }
        return false;
    }
};

//242. Valid Anagram - https://leetcode.com/problems/valid-anagram/
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
		sort(t.begin(),t.end());
		return s == t;
    }
};

//1. Two Sum - https://leetcode.com/problems/two-sum/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int val = target - nums[i];
            for(int k = i + 1; k < nums.size();k++){
                if(nums[k] == val){
                    ans.push_back(i);
                    ans.push_back(k);
                    break;
                }
            }
        }
        return ans;
    }
};
//49. Group Anagrams - https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {
        std::vector<std::vector<std::string>> ans;
        std::map<std::string, std::vector<int>> m;
        std::vector<std::string> temp = strs; 

        for (int i = 0; i < strs.size(); i++)
        {
            std::sort(temp[i].begin(), temp[i].end());
            m[temp[i]].push_back(i);
        }

        for (auto& ele : m)
        {
            std::vector<std::string> group;
            for (int i : ele.second)  
            {
                group.push_back(strs[i]);
            }
            ans.push_back(group);
        }

        return ans;
    }
};

//347. Top K Frequent Elements - https://leetcode.com/problems/top-k-frequent-elements/description/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        auto compare = [&m](int a, int b) {
        return m[a] > m[b];
    };
    priority_queue<int, vector<int>, decltype(compare)> pq(compare);

    
    for (const auto& pair : m) {
        pq.push(pair.first);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
    }
};

//271 - Encode and Decode Strings - https://leetcode.com/problems/encode-and-decode-strings/description/

class Solution {
public:
    string encode(vector<string>& strs) {
        string ans = "";
        for (string ele : strs) {
            if (ans == "")
                ans += ele;
            else {
                ans += " ";
                ans += ele;
            }
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string word = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                ans.push_back(word);
                word = "";
            } else {
                word += s[i];
            }
        }
        if (!word.empty()) {
            ans.push_back(word);
        }
        return ans;
    }
};

//238. Product of Array Except Self - https://leetcode.com/problems/product-of-array-except-self/description/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
        if(n<1)
            return output;
        
        int product = 1;
        for(int i=0;i<n;++i)
        {
            product *= nums[i];
            output.push_back(product);            
        }
        product = 1;
        for(int i=n-1;i>0;--i)
        {
            output[i] = output[i-1]*product;
            product *= nums[i];
        }
        output[0] = product;
        
        return output;
    }
};

//36. Valid Sudoku - https://leetcode.com/problems/valid-sudoku/description/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }

                char value = board[r][c];
                int boxIndex = (r / 3) * 3 + (c / 3);

                if (rows[r].count(value) || cols[c].count(value) || boxes[boxIndex].count(value)) {
                    return false;
                }

                rows[r].insert(value);
                cols[c].insert(value);
                boxes[boxIndex].insert(value);
            }
        }

        return true;        
    }
};

//128. Longest Consecutive Sequence - https://leetcode.com/problems/longest-consecutive-sequence/description/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        if(nums.size <= 1) return nums.size();
        for(int i = 0 ; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        int longest = 1;
        for(auto ele : s)
        {
            if(s.find(ele - 1) == s.end())
            {
                int cnt = 1;
                while(s.find(ele + 1) != s.end())
                {
                    cnt++;
                    ele++;
                }
            }
            longest = max(cnt,longest);
        }
    }
};


