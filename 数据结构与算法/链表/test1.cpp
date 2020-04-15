#include "linkList.h"
#define LENGTH 5

int main()
{
    int i;
    ListDataType e, data[LENGTH] = {1, 2, 3, 4, 5};
    LinkList L;

	//显示测试值
	printf("---【有头结点的单链表】---\n");
	printf("待测试元素为：\n");
	for (i = 0; i < LENGTH; i++) printf("%d\t", data[i]);
	printf("\n");

	//创建链表L
	printf("创建链表L\n");
	if (ERROR == createList(L, data, LENGTH))
	{
		printf("创建链表L失败\n");
		return -1;
	}
	printf("成功创建包含1个头结点、%d个元素的链表L\n元素值存储在data数组中\n", LENGTH);

	//遍历单链表
	printf("此时链表中元素为：\n");
	travelList(L);

	//从链表头节点出链表到e
	printf("\n出链表到e\n");
	deList(L, e);
	printf("出链表的元素为：%d\n", e);
	printf("此时链表中元素为：\n");

	//遍历单链表    
	travelList(L);

	//e从链表末尾入链表
	printf("\ne入链表\n");
	enList(L, e);
	printf("入链表的元素为：%d\n", e);
	printf("此时链表中元素为：\n");

	//遍历单链表
	travelList(L);
	printf("\n");

	getchar();
    return 0;
}