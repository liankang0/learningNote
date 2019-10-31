/*
题目：剑指office 第11题
    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
    输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。
    例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，
    该数组的最小值为1。 NOTE：给出的所有元素都大于0，
    若数组大小为0，请返回0。

思路：二分查找变形，有序数组，将开头几个数字放到末尾，
     即旋转数组
     1.将left指向开头，right指向结尾,mid指向中间
     2.判断中间的数在左边的有序数组，还是在右边的有序数组中
     3.在左边有序数组中，将left指向mid，一步一步逼近，使left指向左边有序数组的最后一个元素
     4.在右边的有序数组中，将right指向mid，一步一步逼近，使right指向右边有序数组的最后一个元素
     5.返回right元素的值，即为最小值
*/
#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
    int minNumberInRotateArray(vector<int>& rotateArray)
    {
        int left = 0, right = rotateArray.size() - 1;
        int mid = (left + right) / 2;
        while(left < mid)
        {
            if(rotateArray[left] < rotateArray[mid])
            {
                 left = mid;
            }
            if(rotateArray[right] > rotateArray[mid])
            {
                right = mid;
            }
            mid = (left + right) / 2;
        }
        return rotateArray[right];
    }
};


int main()
{
    vector<int> arr = {3, 5, 6, 1, 2};
    solution val;
    cout << val.minNumberInRotateArray(arr) << endl;
}