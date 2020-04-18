#include <iostream>
#include <vector>

using namespace std;

double solution(vector<int> arrA, vector<int> arrB)
{
	int m = arrA.size();
	int n = arrB.size();
	if (m > n)
	{ // to ensure m<=n
		vector<int> temp = arrA;
		arrA = arrB;
		arrB = temp;
		int tmp = m;
		m = n;
		n = tmp;
	}
	int leftA = 0, rightA = m, i;
	int  j;
	while (leftA <= rightA)
	{
		i = (leftA + rightA) / 2;
		j = (n + m + 1) / 2 - i;
		if (i < m && arrB[j - 1] > arrA[i])
		{
			rightA = i - 1;
		}
		else if (i > 0 && arrA[i - 1] > arrB[j])
		{
			leftA = i + 1;
		}
		else
		{
			int max;

			if (0 == i)
			{
				max = arrB[j - 1];
			}
			else if (0 == j)
			{
				max = arrA[i - 1];
			}
			else
			{
				max = arrA[i - 1] > arrB[j - 1] ? arrA[i - 1] : arrB[j - 1];
			}
			
			if ((m + n) % 2 == 1)
			{
				return max;
			}

			int min;
			if (i == m)
			{
				min = arrB[j];
			}
			else if (j == n)
			{
				min = arrA[i];
			}
			else
			{
				min = arrA[i] < arrB[j] ? arrA[i] : arrB[j];
			}	
			return (max + min) / 2.0;
		}
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
	vector<int> test6 = {};

	cout << solution(test1, test2) << endl;
	cout << solution(test2, test3) << endl;
	// cout << solution(test3) << endl;
	// cout << solution(test4) << endl;
	// cout << solution(test5) << endl;
	return 0;
}