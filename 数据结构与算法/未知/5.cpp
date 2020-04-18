#include <iostream>
#include <vector>

using namespace std;
// https://www.cnblogs.com/jimmycheng/p/7519870.html
int solution(vector<int>& arr)
{
	int slow = arr[0], fast = arr[0];
	// 第一次相遇在M点
	do
	{
		slow = arr[slow];
		fast = arr[fast];
		fast = arr[fast];
	} while (slow != fast);
	// 第二次相遇在O点
	fast = arr[0];
	do
	{
		slow = arr[slow];
		fast = arr[fast];
	} while (slow != fast);
	return fast;
}
int main()
{
	// test
	vector<int> test1 = {1, 2, 5, 3, 4, 2, 2};
	vector<int> test2 = {1, 4, 2, 3, 4, 5 };
	vector<int> test3 = { 1, 2, 3, 4 };
	vector<int> test4 = { 1, 2, 4 };
	vector<int> test5 = { 1, 2, 3, 4, 5, 6, 8, 9 };
	vector<int> test6 = {};

	cout << solution(test1) << endl;
	cout << solution(test2) << endl;
	// cout << solution(test3) << endl;
	// cout << solution(test4) << endl;
	// cout << solution(test5) << endl;
	return 0;
}