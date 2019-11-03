/*
题目：
    剑指offer35题第一小题
        查找一个数target在一个有序数组nums中出现的次数

思路： 
        二分查找找这个target，没找到返回0，找到times + 1,再找相邻相同的数出现的次数
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
            return 0;
        }

        int mid, left = 0, right = nums.size() - 1;
        int index = -1, times = 0;
        while(left <= right) // 一定不能忘记等于，这个不能等于，当在最左边或者最右边的一个是target，就查不到
        {
            mid = (left + right) / 2;
            if(target == nums[mid])
            {
                index = mid;
                times++;        // 出现一次
                break;
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
        // 如果出现过，判断左右相邻相同元素的个数
        if(-1 != index)
        {
            int tmp = index;
            while(tmp > 0 && nums[tmp] == nums[tmp - 1]) 
            {
                times++;
                tmp--;
            }
            tmp = index;
            while(tmp < nums.size() - 1 && nums[tmp] == nums[tmp + 1])
            {
                times++;
                tmp++;
            }
        }
        return times;
    }
};


int main()
{
    Solution sol;
    vector<int> nums = {5, 5, 5, 5};
    // vector<int> nums = {1, 2, 3, 4, 5, 6, 6, 6, 7, 8};
    int target = 5;
    int sult = sol.timesInArr(nums, target);
    cout << sult << endl;
    return 0;
}