#include<iostream>
using namespace std;
struct BiTree
{
	int data;
	BiTree* Lchild;
	BiTree* Rchild;
};
BiTree *creatBiTree();//�ݹ鷨���������������򴴽�
void pretravel(BiTree* pT);//�������������
void intravel(BiTree* pT);//�������������
void posttravel(BiTree* pT);//������������� 
int main()
{
	BiTree* pT;
	pT=creatBiTree();
	cout << "��������Ľ���ǣ�";
	pretravel(pT);
	cout << endl;
	cout << "��������Ľ���ǣ�";
	intravel(pT);
	cout << endl;
	cout << "��������Ľ���ǣ�";
	posttravel(pT);
	return 0;
}
BiTree *creatBiTree()//���������ʹ�õݹ鷽�� 
{
	BiTree* pT;
	int input;
	cout << "����ýڵ��ֵ(����-1��ʾ�����սڵ�):";
	cin >> input;
	if (input == -1)
	{
		pT = NULL;
		return pT;
	}
	pT = new BiTree;//�����½ڵ� 
	pT->data = input;
	pT->Lchild=creatBiTree();//�������ĵݹ� 
	pT->Rchild=creatBiTree();//�������ĵݹ�
	return pT;
}
void pretravel(BiTree* pT)
{
	if (pT != NULL)
	{
		cout <<pT->data << " ";
		pretravel(pT->Lchild);
		pretravel(pT->Rchild);
	}
	return;
}
void intravel(BiTree* pT)
{
	if (pT != NULL)
	{
		intravel(pT->Lchild);
		cout << pT->data << " ";
		intravel(pT->Rchild);
	}
	return;
}
void posttravel(BiTree* pT)
{
	if (pT != NULL)
	{
		posttravel(pT->Lchild);
		posttravel(pT->Rchild);
		cout << pT->data << " ";
	}
	return;
}