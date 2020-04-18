/*
《剑指offer》面试题41：数据流的中位数（堆）

如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
priority_queue 头文件 queue
		容器的参数  T, 容器<T>, less<T> or greater<T>
		pop() push() top()

		中位数主要分成两个相等数量的队列，单数取中间，双数取中间两个的和除2
*/

class Solution
{
private:
	int count = 0;
	priority_queue<int, vector<int>, less<int>> small;
	priority_queue<int, vector<int>, greater<int>> big;
public:
	void insert(int num)
	{   // 这里不停地将大根堆的最大值放到小根堆，小根堆的最小值放到大根堆，最终形成大根堆的最大值，小于小根堆的最小值
		if (0 == count % 2)
		{
			big.push(num);
			int temp = big.top();
			big.pop();
			small.push(temp);
		}
		else
		{
			small.push(num);
			int temp = small.top();
			small.pop();
			big.push(temp);
		}
		count++;

	}

	void readStream(vector<int> arr)
	{
		int len = arr.size();
		for (int i = 0; i < len; i++)
		{
			insert(arr[i]);
		}
	}

	int getMidNum()
	{
		if (0 == count % 2)
		{
			return (big.top() + small.top()) / 2;
		}
		else
		{
			return small.top();
		}

	}
};

int main()
{
	// test
	vector<int> test1 = { 1, 2, 3, 5, 5, 3, 1 };
	vector<int> test2 = { 0, 2, 3, 4, 5 };
	vector<int> test3 = { 1, 2, 3, 4 };
	vector<int> test4 = { 1, 2, 4 };
	vector<int> test5 = { 0, 1, 2, 3, 4, 5, 6, 8, 9 };
	vector<int> test6 = {};
	Solution midNum;
	midNum.readStream(test5);
	//cout << solution(test1) << endl;
	cout << midNum.getMidNum() << endl;
	// cout << solution(test3) << endl;
	// cout << solution(test4) << endl;
	// cout << solution(test5) << endl;
	return 0;
}