#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> result(vector<int> arr, int s)
	{
		vector<int> res;
		int len = arr.size();
		right = len - 1;
		while (left < right)
		{
			if (s > (arr[left] + arr[right]))
			{
				left++;
			}
			else if (s < (arr[left] + arr[right]))
			{
				right--;
			}
			else
			{
				res.push_back(arr[left]);
				res.push_back(arr[right]);
				break;
			}

		}
		return res;
	}
private:
	int left = 0;
	int right;
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
	
	//cout << solution(test1) << endl;
	cout << midNum.result(test5, 7)[0] << "  " << midNum.result(test5, 7)[1] << endl;
	// cout << solution(test3) << endl;
	// cout << solution(test4) << endl;
	// cout << solution(test5) << endl;
	return 0;
}