/*
《剑指offer》面试题56(题目二)：数组中唯一只出现1次的数字（位运算）

在一个数组中除一个数字只出现一次之外，其他数字都出现了3次。请找出那个只出现一次的数字

解答
如果其余数字都出现2次，则使用异或很好解决，
但是这里是3次，所以无法使用异或；但是还是可以沿用位运算的思路，
如果一个数字出现3次，其二进制表示的每一位也出现3次，
把所有出现3次的数字的二进制表示的每一位都分别加起来，
每一位的和都能被3整除。我们把数组中所有数字的二进制表示的每一位都加起来。
如果某一位的和能被3整除，那么只出现一次的数字二进制中对应的那一位是0，否则是1
*/
#include <iostream>
#include <vector>

using namespace std;
/*
思路：
	将所有数异或，得到两个只出现一次的数的异或
	找到这个异或后的第一位为1的下标
	将所有的这个下标为1的数分成一组异或得到第一个数，不为1的数分成一组异或得到第二个数
*/
bool isBit(int num, int index)
{
	num = num >> index;
	return (num & 1);
}

void solution(vector<int> arr, int* num1, int* num2)
{
	int len = arr.size();
	int num1ORnum2 = 0;
	for (int i = 0; i < len; i++)
	{
		num1ORnum2 ^= arr[i];
	}
	int index = 0;
	while ((num1ORnum2 ^ 0 == 0) && index < 32)
	{
		num1ORnum2 = num1ORnum2 >> 1;
		index++;
	}

	for (int i = 0; i < len; i++)
	{
		if (isBit(arr[i], index))
		{
			*num1 ^= arr[i];
		}
		else
		{
			*num2 ^= arr[i];
		}
	}


}

int main()
{
	// test
	vector<int> test1 = {};
	vector<int> test2 = { 2, 2, 3, 3, 4, 6, 5, 5 };
	vector<int> test3 = { 1, 2, 3, 4 };
	vector<int> test4 = { 1, 2, 4 };
	vector<int> test5 = { 1, 2, 3, 4, 5, 6, 8, 9 };
	vector<int> test6 = {};
	int num1 = 0, num2 = 0;
	solution(test2, &num1, &num2);
	cout << num1 << "==>" << num2 << endl;
	//cout << solution(test2) << endl;
	// cout << solution(test3) << endl;
	// cout << solution(test4) << endl;
	// cout << solution(test5) << endl;
	return 0;
}