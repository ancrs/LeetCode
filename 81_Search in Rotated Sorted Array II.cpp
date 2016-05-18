Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.


bool search(int* nums, int numsSize, int target) {
    int begin = 0;
		int end = numsSize-1;
		while(begin < end)
		{
			int mid = (begin+end)/2;
			if(nums[mid] == target)return true;
			else if(nums[begin] == nums[mid])
			{
				for(int i = begin; i< mid; i++)
					if(nums[i]==target)return true;
				begin = mid+1;
			}
			else if(nums[begin] < nums[mid])//begin-mid increase
			{
				if(nums[begin] <= target && target < nums[mid])
					end = mid-1;
				else
					begin = mid+1;
			}
			else//mid-end increase
			{
				if(nums[mid] < target && target <= nums[end])
					begin = mid+1;
				else
					end = mid-1;
			}
		}
		if(begin==end && nums[begin]==target)
			return true;
		else
			return false;
}