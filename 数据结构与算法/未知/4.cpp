#include <iostream>
#include <vector>

using namespace std;

// O(n)时间复杂度
// O(1)空间复杂度

int solution(vector<int>& arr)
{
	int len = arr.size();
	if (0 == len)
		return 1;

	int i = 0;
	while (i < len ) 
	{
		if (arr[i] - 1 < len && arr[i] > 0)// 要求i和 arr[i] - 1 都< len
		{
			int tmp = arr[arr[i] - 1];
			arr[arr[i] - 1] = arr[i];
			arr[i] = tmp;
			
		}
		i++;
	}
	for (i = 0; i < len; i++)
	{
		if (arr[i] != i + 1)
			return i + 1;
	}
}



int main()
{
	// test
	vector<int> test1 = {};
	vector<int> test2 = { 2, 3, 4, 5 };
	vector<int> test3 = { 1, 2, 3, 4 };
	vector<int> test4 = { 1, 2, 4 };
	vector<int> test5 = { 1, 2, 3, 4, 5, 6, 8, 9 };
	vector<int> test6 = {3, 8, 1, 9, 5, 2};

	cout << solution(test1) << endl;
	cout << solution(test6) << endl;
	// cout << solution(test3) << endl;
	// cout << solution(test4) << endl;
	// cout << solution(test5) << endl;
	return 0;
}