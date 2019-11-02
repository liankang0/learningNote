/*
题目：leetcode 33题
        假设按照升序排序的数组在预先未知的某个点上进行了旋转。

        ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

        搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

        你可以假设数组中不存在重复的元素。

        你的算法时间复杂度必须是 O(log n) 级别。

        示例 1:

        输入: nums = [4,5,6,7,0,1,2], target = 0
        输出: 4
        示例 2:

        输入: nums = [4,5,6,7,0,1,2], target = 3
        输出: -1
思路：二分查找算法复杂度 o(log n)
        思路同上面第二题
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0, right = nums.size() - 1;
        int mid = (left + right) / 2;
        while(mid > left)
        {
            if(nums[left] < nums[mid])
            {
                left = mid;
            }
            if(nums[right] > nums[mid])
            {
                right = mid;
            }
            mid = (left + right) /2;
        }
        int pos1 = 0, pos2 = left, pos3 = right, pos4 = nums.size() - 1;
        if(target >= nums[pos1] && target <= nums[pos2])
        {
            return binarySearch(nums, target, pos1, pos2);
        }
        else if(target >= nums[pos3] && target <= nums[pos4])
        {
            return binarySearch(nums,target, pos3, pos4);
        }
        else
        {
            return -1;
        }
    }
};

int binarySearch(vector<int> & nums, int target, int left, int right)
{
    int mid;
    while(left <= right)
    {
        if(target == nums[mid])
        {
            return mid;
        }
        else if(target < nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}