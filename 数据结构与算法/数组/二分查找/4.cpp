/*
题目:
        假设按照升序排序的数组在预先未知的某个点上进行了旋转。

        ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

        编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

        示例 1:

        输入: nums = [2,5,6,0,0,1,2], target = 0
        输出: true
        示例 2:

        输入: nums = [2,5,6,0,0,1,2], target = 3
        输出: false
        进阶:

        这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
        这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

思路:
        和上面两题比较像，唯一就是本题中，有重复的元素，怎么去掉重复的元素？
        1.当开头和结尾相同时，去掉开头和结尾重复的数字 12111
        2.在查找旋转点（边界）的时候，中间有重复的数字，怎么避免死循环。 344412  这个当left = nums[mid] 也要left右移到mid
        对时间复杂度的影响？
        1.极端情况下  1111131   时间复杂度为o(n)
        2.总体时间复杂度 o(n) = o(n) + o(log n)   去除重复元素 + 查找 
*/
class Solution
{
public:
    bool search(vector<int>& nums, int target) 
    {
        // 判断nums数组为空，为空则直接返回false
        if(0 == nums.size())
        {
            return false;
        }
        
        // 寻找两个有序数组的边界，结果left = mid 指向第一个有序数组的尾部
        // right 指向第二个有序数字组的开头
        int left = 0, right = nums.size() - 1;
        // 判断首尾数字相同，并且处理
        if(nums[left] == nums[right])
        { 
            while(left < right && nums[left] == nums[left + 1]) left++;
            while(left < right && nums[right] == nums[right - 1]) right--;
        }
        int mid = (left + right) / 2;
        while(mid > left)
        {
            
            
            if(nums[mid] >= nums[left])  // 等于号跳过数组中重复的元素，避免死循环
            {                            
                left = mid;              
            }
            if(nums[mid] <= nums[right])
            {
                right = mid;
            }
            mid = (left + right) / 2;
        }
        // 分块二分查找，找到返回true，否则返回false
        int arr1Head = 0, arr1Tail = left, arr2Head = right, arr2Tail = nums.size() - 1;
        if(target >= nums[arr1Head] && target <= nums[arr1Tail])
        {
            return binarySearchIsExist(nums, target, arr1Head, arr1Tail) ? true : false;
        }
        else if(target >= nums[arr2Head] && target <= nums[arr2Tail])
        {
            return binarySearchIsExist(nums, target, arr2Head, arr2Tail) ? true : false;
        }
        else
        {
            return false;
        }
    }
private:
    bool binarySearchIsExist(vector<int>& nums, int target, int arrHead, int arrTail)
    {
        int left = arrHead, right = arrTail;
        int mid;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(target == nums[mid])
            {
                return true;
            }
            else if(target > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};  