/*
Leetcode81：旋转数组中查找数字II（二分查找 medium）
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:

输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
示例 2:

输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
进阶:

这是 旋转数组中查找数字 的延伸题目，本题中的 nums 可能包含重复元素
这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？
*/
#include <iostream>
#include <vector>

using namespace std;
// https://www.cnblogs.com/liujinhong/p/6490254.html

/*
	思路一：累加，控制溢出 时间复杂度：n
	思路二：异或          时间复杂度：n
	思路三：排序，二分查找 时间复杂度：nlog(n) + log(n)
*/
int solution(vector<int>& arr)
{
	
	int len = arr.size();
	int result = len;
	for (int i = 0; i < len; i++)
	{                       // 累加
		result ^= i;        // result += i;
		result ^= arr[i];   // result -= arr[i];
	}
	return result;
}

int main()
{
	// test
	vector<int> test1 = {};
	vector<int> test2 = { 0, 2, 3, 4, 5 };
	vector<int> test3 = { 1, 2, 3, 4 };
	vector<int> test4 = { 1, 2, 4 };
	vector<int> test5 = {0, 1, 2, 3, 4, 5, 6, 8, 9 };
	vector<int> test6 = {};

	//cout << solution(test1) << endl;
	cout << solution(test2) << endl;
	// cout << solution(test3) << endl;
	// cout << solution(test4) << endl;
	cout << solution(test5) << endl;
	return 0;
}