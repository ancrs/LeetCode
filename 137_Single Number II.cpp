Given an array of integers, every element appears three times except for one. Find that single one.



int singleNumber(int* nums, int numsSize) {
    int bitnum[32]={0};
        int res=0;
        for(int i=0; i<32; i++){
            for(int j=0; j<numsSize; j++){
                bitnum[i]+=(nums[j]>>i)&1;
            }
            res|=(bitnum[i]%3)<<i;
        }
        return res;
}