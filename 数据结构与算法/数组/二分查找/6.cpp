/*
题目：
        剑指offer53第二小题 0~n中缺失的数字
        一个长度为n的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0 ~ n之内。
        在范围0~n内的n个数字有且只有一个数字不在该数组中，请找出。

思路： 
        方法一：异或，将0到n先异或，然后遍历数组异或，结果就是这个数
                这个方法用在一个数组每个数都出现两次，只有一个数出现一次情况
        正解： 二分查找：判断 mid == nums[mid] ？ left = mid + 1 : right = mid - 1;
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int timesInArr(vector<int>& nums, int target)
    {
        // 处理nums为空
        if(0 == nums.size())
        {
            return -1;
        }

        int mid, left = 0, right = nums.size() - 1;
        while(left + 1 < right) // 一定不能忘记等于，这个不能等于，当在最左边或者最右边的一个是target，就查不到
        {
            mid = (left + right) / 2;
            if(mid - 1 == nums[mid])
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
       return right;
    }
};


int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 4};
    // vector<int> nums = {1, 2, 3, 4, 5, 6, 6, 6, 7, 8};  //未测试。。。。。。。。。。。。。。。。。。。。。。。。。
    int target = 5;
    int sult = sol.timesInArr(nums, target);
    cout << sult << endl;
    return 0;
}