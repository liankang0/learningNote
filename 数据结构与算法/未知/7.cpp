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