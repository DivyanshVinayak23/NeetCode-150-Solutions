//704. Binary Search - https://leetcode.com/problems/binary-search/description/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        for(int i = 0; i < nums.size(); i++){
            int index = (start + end)/2;
            if(nums[index] == target){
                return index;
                break;
            }
            if(nums[index] > target)
                end = index - 1;
            if(nums[index] < target)
                start = index + 1;
        }
        return -1;
    }
};

//74. Search a 2D Matrix - https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        int rLeft = 0, rRight = rows - 1, cLeft = 0, cRight = cols - 1;

        while (rLeft <= rRight && cLeft <= cRight) {
            int rMid = rLeft + (rRight - rLeft) / 2;
            int cMid = cLeft + (cRight - cLeft) / 2;
            
            if (matrix[rMid][cMid] == target) {
                return true;
            } else if (matrix[rMid][cMid] > target) {
                if (cMid > cLeft) {
                    cRight = cMid - 1;
                } else {
                    rRight = rMid - 1;
                    cRight = cols - 1; 
                }
            } else {
                if (cMid < cRight) {
                    cLeft = cMid + 1;
                } else {
                    rLeft = rMid + 1;
                    cLeft = 0;  
                }
            }
        }

        return false;
    }
};


//875. Koko Eating Bananas - https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
public:
    bool check(int mid, vector<int> piles ,int h)
    {
        int total = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            total += ceil(piles/mid);
        }
        if(total <= h)return true;
        else
            return false;
    }




    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element<piles.begin(),piles.end()>;
        int ans =0;
        while(left < right)
        {
            int mid = left + (right - left)/2;
            if(check(mid,piles,h))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};


//153. Find Minimum in Rotated Sorted Array - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(mid < right && nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            if(mid < right && nums[mid] < nums[mid - 1])
                return nums[mid];
            if(nums[mid] <= nums[start])
                right = mid - 1;
            else
                start = mid + 1;
        }
        return nums[0];      
    }
};

//33. Search in Rotated Sorted Array - https://leetcode.com/problems/search-in-rotated-sorted-array/description/
class Solution {
     int search(int[] nums, int target) {
        int pivot = findPivot(nums);

        // if you did not find a pivot, it means the array is not rotated
        if (pivot == -1) {
            // just do normal binary search
            return binarySearch(nums, target, 0 , nums.length - 1);
        }

        // if pivot is found, you have found 2 asc sorted arrays
        if (nums[pivot] == target) {
            return pivot;
        }

        if (target >= nums[0]) {
            return binarySearch(nums, target, 0, pivot - 1);
        }

        return binarySearch(nums, target, pivot + 1, nums.length - 1);
    }

     int binarySearch(int[] arr, int target, int start, int end) {
        while(start <= end) {
            // find the middle element
//            int mid = (start + end) / 2; // might be possible that (start + end) exceeds the range of int in java
            int mid = start + (end - start) / 2;

            if (target < arr[mid]) {
                end = mid - 1;
            } else if (target > arr[mid]) {
                start = mid + 1;
            } else {
                // ans found
                return mid;
            }
        }
        return -1;
    }

    // this will not work in duplicate values
     int findPivot(int[] arr) {
        int start = 0;
        int end = arr.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            // 4 cases over here
            if (mid < end && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            if (mid > start && arr[mid] < arr[mid - 1]) {
                return mid-1;
            }
            if (arr[mid] <= arr[start]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }

     int findPivotWithDuplicates(int[] arr) {
        int start = 0;
        int end = arr.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            // 4 cases over here
            if (mid < end && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            if (mid > start && arr[mid] < arr[mid - 1]) {
                return mid-1;
            }

            // if elements at middle, start, end are equal then just skip the duplicates
            if (arr[mid] == arr[start] && arr[mid] == arr[end]) {
                // skip the duplicates
                // NOTE: what if these elements at start and end were the pivot??
                // check if start is pivot
                if (start < end && arr[start] > arr[start + 1]) {
                    return start;
                }
                start++;

                // check whether end is pivot
                if (end > start && arr[end] < arr[end - 1]) {
                    return end - 1;
                }
                end--;
            }
            // left side is sorted, so pivot should be in right
            else if(arr[start] < arr[mid] || (arr[start] == arr[mid] && arr[mid] > arr[end])) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
}




//4. Median of Two Sorted Arrays - https://leetcode.com/problems/median-of-two-sorted-arrays/description/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        // Ensure nums1 is the smaller array
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        
        int low = 0, high = n1;
        int left = (n1 + n2 + 1) / 2;
        int n = n1 + n2;
        
        while (low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;
            
            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];
            
            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1) return max(l1, l2);
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        
        return 0.0; // In case of unexpected failure
    }
};

//981. Time Based Key-Value Store - https://leetcode.com/problems/time-based-key-value-store/description/

class TimeMap {
public:
    map<string, vector<pair<int, string>>> m;  // Correct the data type of 'value' to string

    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value}); 
    }

    string get(string key, int timestamp) {
        if (m.find(key) == m.end())
            return "";

        int low = 0, high = m[key].size() - 1;
        int maxTimeStampIndex = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (m[key][mid].first <= timestamp) {
                maxTimeStampIndex = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (maxTimeStampIndex == -1)
            return "";

        return m[key][maxTimeStampIndex].second;
    }
};
