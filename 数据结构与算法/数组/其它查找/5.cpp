/*
《剑指offer》面试题56(题目一)：数组中只出现1次的2个数（位运算）

一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字

解答
可以先考虑如果只有1个数字出现1次，其余都2次，怎么找：

对所有数字异或，由于异或满足结合律交换律，结果就是所要查找的数字
对于存在2个出现1次的数字:

所有数字异或结果为这两个数字的异或值，如果能将数组分为2部分，每个数字属于其中一部分，则能求出这两个数字。可以找到这两个数字异或结果中第一个为1的位，根据该位将数组分成2个数组

*/
#include <iostream>
#include <vector>

using namespace std;
// https://www.cnblogs.com/liujinhong/p/6490254.html

/*
	思路二：异或          时间复杂度：n
	思路三：排序，二分查找 时间复杂度：nlog(n) + log(n)
*/
// 查找只出现一次的数字
int solution1(vector<int>& arr)
{
	int len = arr.size();
	int result = 0;
	for (int i = 0; i < len; i++)
	{
		result ^= arr[i];
	}
	return result;
}
int main()
{
	// test
	vector<int> test1 = { 1, 2, 3, 5, 5, 3, 1 };
	vector<int> test2 = { 0, 2, 3, 4, 5 };
	vector<int> test3 = { 1, 2, 3, 4 };
	vector<int> test4 = { 1, 2, 4 };
	vector<int> test5 = { 0, 1, 2, 3, 4, 5, 6, 8, 9 };
	vector<int> test6 = {};

	//cout << solution(test1) << endl;
	cout << solution1(test1) << endl;
	// cout << solution(test3) << endl;
	// cout << solution(test4) << endl;
	// cout << solution(test5) << endl;
	return 0;
}