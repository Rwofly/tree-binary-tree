#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#define Maxsize 100
struct Tree
{
	char tree[Maxsize];
	int count;//��ʾ���������һ���ڵ��λ�� 
};
void init_tree(Tree *&T);//��ʼ��������
void input_tree(Tree *& T);//��������д��ֵ
void find_son(Tree* T);//���ӽڵ�
void find_father(Tree* T);//�󸸽ڵ� 
bool if_empty(Tree* T);//�ж϶������Ƿ�Ϊ�� 
void travel_tree(Tree* T);//��������� 
void destory_tree(Tree*& T);//���ٶ����� 
int main()
{
	Tree* T;
	init_tree(T);
	input_tree(T);
	printf("��α�����Ϊ��\n");
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
	printf("������ڵ��ֵ��#��ʾ�սڵ㡢*��ʾ�������룩��");
	while ((ch = getchar()) != '*')//��*�Ž���
	{
		T->count++;//���±�Ϊ1����ʼ���� 
		T->tree[T->count] = ch;
	}
	return;
}
bool if_empty(Tree* T)
{
	if (T->tree[1] == '#')//T->tree[1]ֻ�ܴ洢���ڵ��ֵ 
	{
		return true;
	}
	return false;
}
void find_son(Tree* T)
{
	printf("�����ӽ��\n");
	int n;
	printf("�������������Ľڵ��ţ�");
	scanf("%d", &n);
	if (if_empty(T))
	{
		printf("����Ϊ�գ�\n");
		return;
	}
	if (n > T->count)
	{
		printf("����ֵ����\n");
		return;
	}
	if (T->tree[n] == '#')
	{
		printf("�˽ڵ�Ϊ�սڵ㣡\n");
		return;
	}
	if (T->tree[2 * n] == '#' && T->tree[2 * n + 1] == '#')
	{
		printf("%c�ڵ�����Һ���Ϊ�գ�\n", T->tree[n]);
	}
	else if (T->tree[2 * n] == '#' && T->tree[2 * n + 1] != '#')
	{
		printf("%c�ڵ������Ϊ��,�Һ���Ϊ%c\n", T->tree[n], T->tree[2 * n + 1]);
	}
	else if (T->tree[2 * n] != '#' && T->tree[2 * n + 1] == '#')
	{
		printf("%c�ڵ������Ϊ%c,�Һ���Ϊ��\n", T->tree[n], T->tree[2 * n]);
	}
	else
	{
		printf("%c�ڵ������Ϊ%c,�Һ���Ϊ%c\n", T->tree[n], T->tree[2 * n], T->tree[2 * n + 1]);
	}
	return;
}
void find_father(Tree* T)
{
	printf("���Ҹ��ڵ�\n");
	int n;
	if (if_empty(T))
	{
		printf("����Ϊ�գ�\n");
		return;
	}
	printf("����������Ľڵ��ţ�");
	scanf("%d", &n);
	if (n == 1)
	{
		printf("�˽ڵ�Ϊ���ڵ��޸��ڵ㣡\n");
	}
	if (n > T->count)
	{
		printf("����ֵ����\n");
		return;
	}
	if (T->tree[n] == '#')
	{
		printf("�˽ڵ�Ϊ�սڵ㣡\n");
		return;
	}
	else
	{
		printf("%c�ĸ��ڵ�Ϊ%c\n", T->tree[n], T->tree[n / 2]);
	}
	return;
}
void travel_tree(Tree* T)
{
	if (if_empty(T))
	{
		printf("����Ϊ�գ�\n");
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
