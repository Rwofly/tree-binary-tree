#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#define Maxsize 100
struct Tree
{
	char tree[Maxsize];
	int count;//表示二叉树最后一个节点的位置 
};
void init_tree(Tree *&T);//初始化二叉树
void input_tree(Tree *& T);//给二叉树写入值
void find_son(Tree* T);//求子节点
void find_father(Tree* T);//求父节点 
bool if_empty(Tree* T);//判断二叉树是否为空 
void travel_tree(Tree* T);//输出二叉树 
void destory_tree(Tree*& T);//销毁二叉树 
int main()
{
	Tree* T;
	init_tree(T);
	input_tree(T);
	printf("层次遍历树为：\n");
	travel_tree(T);
	find_son(T);
	printf("\n\n");
	find_father(T);
	destory_tree(T);
	return 0;
}
void init_tree(Tree*& T)
{
	T = (Tree*)malloc(sizeof(Tree));
	T->tree[Maxsize] = { '#' };
	T->count = 0;
	return;
}
void input_tree(Tree*& T)
{
	char ch;
	printf("请输入节点的值（#表示空节点、*表示结束输入）：");
	while ((ch = getchar()) != '*')//以*号结束
	{
		T->count++;//从下标为1处开始储存 
		T->tree[T->count] = ch;
	}
	return;
}
bool if_empty(Tree* T)
{
	if (T->tree[1] == '#')//T->tree[1]只能存储根节点的值 
	{
		return true;
	}
	return false;
}
void find_son(Tree* T)
{
	printf("查找子结点\n");
	int n;
	printf("请输入所操作的节点编号：");
	scanf("%d", &n);
	if (if_empty(T))
	{
		printf("此树为空！\n");
		return;
	}
	if (n > T->count)
	{
		printf("输入值过大！\n");
		return;
	}
	if (T->tree[n] == '#')
	{
		printf("此节点为空节点！\n");
		return;
	}
	if (T->tree[2 * n] == '#' && T->tree[2 * n + 1] == '#')
	{
		printf("%c节点的左右孩子为空！\n", T->tree[n]);
	}
	else if (T->tree[2 * n] == '#' && T->tree[2 * n + 1] != '#')
	{
		printf("%c节点的左孩子为空,右孩子为%c\n", T->tree[n], T->tree[2 * n + 1]);
	}
	else if (T->tree[2 * n] != '#' && T->tree[2 * n + 1] == '#')
	{
		printf("%c节点的左孩子为%c,右孩子为空\n", T->tree[n], T->tree[2 * n]);
	}
	else
	{
		printf("%c节点的左孩子为%c,右孩子为%c\n", T->tree[n], T->tree[2 * n], T->tree[2 * n + 1]);
	}
	return;
}
void find_father(Tree* T)
{
	printf("查找父节点\n");
	int n;
	if (if_empty(T))
	{
		printf("此树为空！\n");
		return;
	}
	printf("请输入操作的节点编号：");
	scanf("%d", &n);
	if (n == 1)
	{
		printf("此节点为根节点无父节点！\n");
	}
	if (n > T->count)
	{
		printf("输入值过大！\n");
		return;
	}
	if (T->tree[n] == '#')
	{
		printf("此节点为空节点！\n");
		return;
	}
	else
	{
		printf("%c的父节点为%c\n", T->tree[n], T->tree[n / 2]);
	}
	return;
}
void travel_tree(Tree* T)
{
	if (if_empty(T))
	{
		printf("此树为空！\n");
		return;
	}
	for (int i = 1;i <= T->count;i++)
	{
		printf("%c ", T->tree[i]);
	}
	printf("\n");
	return;
}
void destory_tree(Tree*& T)
{
	free(T);
	return;
}
