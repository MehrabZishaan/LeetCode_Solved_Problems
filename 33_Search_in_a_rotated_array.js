// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let left = 0; right = nums.length-1;
    result = -1;

    while(left <= right){
        mid = Math.floor((left+right)/2);
        if(nums[mid] == target){
            result = mid;
        }
       
        if(nums[mid] >= nums[left]){
            if(target >= nums[left] && target <= nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid+1;
            }
        }
        else{
            if(target >= nums[mid] && target <= nums[right]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
    }
    return result;
}; 