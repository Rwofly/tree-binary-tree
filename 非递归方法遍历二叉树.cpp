#include<iostream>
using namespace std;
#define Max 100
struct BiTree
{
	int data;
	BiTree* Lchild;
	BiTree* Rchild;
};
BiTree *creatBiTree();//���ɶ�����
void pretravel(BiTree* pT);//�������
void intravel(BiTree* pT);//�������
void posttravel(BiTree* pT);//�������
int main()
{
	BiTree* pT=NULL;
	pT=creatBiTree();
	cout << "ǰ������Ľ��Ϊ��";
	pretravel(pT);
	cout << endl;
	cout << "��������Ľ��Ϊ��";
	intravel(pT);
	cout << endl;
	cout << "��������Ľ��Ϊ��";
	posttravel(pT);
	cout << endl;
	return 0;
}
BiTree *creatBiTree()
{
	BiTree* pT;
	int input;
	cout << "������ýڵ��ֵ(����-1��ʾ�����µĽڵ�)��";
	cin >> input;
	if (input == -1)
	{
		pT = NULL;
		return pT;
	}
	pT = new BiTree;
	pT->data = input;
	pT->Lchild=creatBiTree();
	pT->Rchild=creatBiTree();
	return pT;
}
void intravel(BiTree* pT)
{
	BiTree stack[Max];//����һ��BiTree���͵����飬����˳��ջʵ�֡�����ջ��ʵ��Ҫ�򵥣����������˷��ڴ棬������� ��
	BiTree node;//���ܵ���ջ��Ԫ��
	BiTree* p=pT;
	int n = 0;
	while (p || n > 0)
	{
		if (p)
		{
			n++;
			stack[n] = *p;//��ջ
			p = p->Lchild;//����������
		}
		else
		{
			node = stack[n];
			n--;//��ջ
			cout<<node.data<<" ";//���ʸ��ڵ�
			p = node.Rchild;//����������
		}
	}

}
void pretravel(BiTree* pT)
{
	BiTree stack[Max];
	BiTree node;
	BiTree* p=pT;
	int n = 0;
	while (p || n > 0)
	{
		if (p)
		{
			cout << p->data << " ";//���ʸ��ڵ�
			n++;
			stack[n] = *p;//��ջ
			p = p->Lchild;//������ڵ�
		}
		else
		{
			node = stack[n];
			n--;//��ջ
			p = node.Rchild;
		}
	}
	return;
}
void posttravel(BiTree* pT)//���������Ϊ�鷳������˼·��
{                         //�������˳��Ϊ��-��-�������԰Ѻ��򵱳ɸ�-��-������ڷ�ת����
	BiTree stack[Max];
	BiTree node;
	BiTree* p = pT;
	int n=0;
	int count = 0;
	int array[Max];//ʹ�����鱣�����ݣ�����������鷴ת
	n++;
	stack[n] = *p;//���ڵ���ջ
	while (n > 0)
	{
		node = stack[n];
		n--;//����
		array[count] = node.data;
		count++;//�����ݱ�����һ��������
		if (node.Lchild)
		{
			n++;
			stack[n] = *node.Lchild;//��ջ
		}
		if (node.Rchild)
		{
			n++;
			stack[n] = *node.Rchild;//��ջ
		}
	}
	for (int i = count - 1;i >= 0;i--)//���鷴ת
	{
		cout << array[i] << " ";
	}
	return;
}
