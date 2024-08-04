//125. Valid Palindrome - https://leetcode.com/problems/valid-palindrome/description/

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;
            if (tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};


//167. Two Sum II - Input Array Is Sorted - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int l = 0;
        int r = numbers.size()- 1;
        int flag = false;
        while(!flag){
            if(numbers[l] + numbers[r] == target){
                ans.push_back(++l);
                ans.push_back(++r);
                flag = true;
            }
            else if(numbers[l] + numbers[r] > target)
                r--;
            else if(numbers[l] + numbers[r] < target)
                l++;
        }
        return ans;
    }
};

//15. 3Sum - https://leetcode.com/problems/3sum/description/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;
        for (int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        for(auto triplets : s)
            output.push_back(triplets);
        return output;
    }
};

//11. Container With Most Water - https://leetcode.com/problems/container-with-most-water/description/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0; 
        while (left < right) {
            int currentWater = (right - left) * min(height[left], height[right]);
            maxWater = max(currentWater, maxWater);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};

//42. Trapping Rain Water - https://leetcode.com/problems/trapping-rain-water/description/
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = 1;
        int maxWater = 0;
        while(left != height.size()-1)
        {
            while(height[right] >= height[left])right++;
            int temp = height[left];
            left++;
            while(left != right)
            {
                maxWater += temp - height[left];
                left++;
            }
            right++;
        }
        return maxWater;
    }
};


//42. Trapping Rain Water-https://leetcode.com/problems/trapping-rain-water/description/

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = 1;
        int maxWater = 0;
        while(left != height.size()-1)
        {
            while((height[right] >= height[left]) && right < height.size())right++;
            int temp = height[left];
            left++;
            while(left != right)
            {
                maxWater += temp - height[left];
                left++;
            }
            right++;
        }
        return maxWater;
    }
};

