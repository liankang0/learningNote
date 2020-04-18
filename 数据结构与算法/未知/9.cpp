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
	{
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