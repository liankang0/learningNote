#include <iostream>
#include <vector>

using namespace std;

int soulution(vector<int> arr)
{
	// 处理arr为空
	if (0 == arr.size())
	{
		return -1;
	}
	// 处理arr开头和结尾是缺少的数字
	int len = arr.size();
	if (1 < arr[0])
		return 1;
	if (len + 1 > arr[len - 1])
		return len + 1;
	int mid, left = 0, right = len - 1;
	// 处理中间是缺少的数据
	while (left + 1 < right)
	{
		mid = (left + right) / 2;
		if (mid + 1 == arr[mid])
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	return arr[left] + 1;
}

int main()
{
	// test
	vector<int> test1 = {};
	vector<int> test2 = { 2, 3, 4, 5 };
	vector<int> test3 = { 1, 2, 3, 4 };
	vector<int> test4 = { 1, 2, 4 };
	vector<int> test5 = {1, 2, 3, 4, 5, 6, 8, 9};
	vector<int> test6 = {};

	cout << soulution(test1) << endl;
	cout << soulution(test2) << endl;
	cout << soulution(test3) << endl;
	cout << soulution(test4) << endl;
	cout << soulution(test5) << endl;
}