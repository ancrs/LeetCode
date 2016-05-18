Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.


int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
         while( left <= right){
             int mid = (left + right)/2;
             if(nums[mid] == target) return mid;
             if(nums[left] < nums[mid]){
                 if(target <= nums[mid] && target >= nums[left])
                     right = mid - 1;
                 else left = mid + 1;
             } else if (nums[left] > nums[mid]){
                 if(target >= nums[left] || target <= nums[mid])
                     right = mid -1;
                 else left = mid + 1;
             }
             else left ++;
         }
         return -1;
}