/*
Leetcode41：缺失的第一个正数（交换 hard）

给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:

输入: [1,2,0]
输出: 3
示例 2:

输入: [3,4,-1,1]
输出: 2
示例 3:

输入: [7,8,9,11,12]
输出: 1
说明:

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
*/

//方法一：时间复杂度为O(n^2)，空间复杂度为O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int tmp;
        int i;
        for(i = 0; i < nums.size(); i++)
        {
            while(1 <= nums[i] && nums.size() >= nums[i] && nums[i] != nums[nums[i] - 1])
            {
                tmp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                //cout << tmp <<"--->"<< nums[i] << endl;
                nums[i] = tmp;
               
            }
        }

        for(i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i + 1)
                break;
        }
        return i + 1;
    }
};
//方法一：时间复杂度为O(n)，空间复杂度为O(1),
//方法是用hash思想，用数组本身下标当索引，数组值的正负当做value（在不使用额外内存情况下，实现一个hash）
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int tmp;
        int i;
        //有无1
        int contains = 0;
        for (int i = 0; i < nums.size(); i++)
        if (nums[i] == 1) {
            contains++;
            break;
        }

        if (contains == 0)
        return 1;

        if (nums.size() == 1)
            return 2;
        //排除干扰，不符合的都变成1
        for(i = 0; i < nums.size(); i++)
        {
            if(1 <= nums[i] && nums.size() >= nums[i]) continue;
            nums[i] = 1;
        }
        //将对应元素nums[i] 的 nums[nums[i] -1] 变为负数，重复元素执行一次
        for(i = 0; i < nums.size(); i++)
        {
            if(0 < nums[abs(nums[i]) - 1])
                nums[abs(nums[i]) - 1] *= -1;
        }

        for(i = 0; i < nums.size(); i++)
        {
            if(0 < nums[i])
                break;
        }
        return i + 1;
    }
};