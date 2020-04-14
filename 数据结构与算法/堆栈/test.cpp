#include "sqStack.h"
//测试代码
int main()
{
    SqStack S;

    int size = 5;
    int increment = 5;
    int i = 5;
    //初始化测试
    ElemType e, eArray[5] = { 1, 2, 3, 4, 5 };

	//显示测试值
	printf("---【顺序栈】---\n");
	printf("栈S的size为：%d\n栈S的increment为：%d\n", size, increment);
	printf("待测试元素为：\n");
	for (i = 0; i < 5; i++) {
		printf("%d\t", eArray[i]);
	}
	printf("\n");

	//初始化顺序栈
	if (!initStack(S, size, increment)) {
		printf("初始化顺序栈失败\n");
		exit(0);
	}
	printf("已初始化顺序栈\n");


    //入栈
    for (i = 0; i < S.size; i++) {
		if (!pushStack(S, eArray[i])) {
			printf("%d入栈失败\n", eArray[i]);
			exit(0);
		}
	}
	printf("已入栈\n");

    //栈S元素出栈
	printf("栈S元素出栈为：\n");
	for (i = 0, e = 0; i < S.size; i++) {
		popStack(S, e);
        printf("%d\t", e);
	}
	printf("\n");
    return 0;
}