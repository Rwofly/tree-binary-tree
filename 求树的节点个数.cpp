#include<iostream>
using namespace std;
struct BiTree
{
	int data;
	BiTree *Lchild;
	BiTree *Rchild;
};
BiTree *creat_BiTree();//���������� 
int Node_count(BiTree* pT);//��������ڵ���� 
int main()
{
	BiTree* pT;
	pT=creat_BiTree();
	int count=Node_count(pT);
	cout<<"���Ľڵ����Ϊ��"<<count<<endl; 
	return 0;
}
BiTree *creat_BiTree()
{
	BiTree* pT;
	int input;
	cout<<"����ڵ��ֵ(����-1��ʾ�����սڵ�):";
	cin>>input;
	if(input==-1)
	{
		pT=NULL;
		return pT;
	}
	pT=new BiTree;
	pT->data=input;
	pT->Lchild=creat_BiTree();
	pT->Rchild=creat_BiTree();
	return pT;
}
int Node_count(BiTree* pT)
{
	if(pT==NULL)
	{
		return 0;//���ڵ�Ϊ�գ��ڵ����Ϊ�� 
	}
	return Node_count(pT->Lchild)+Node_count(pT->Rchild)+1;//�ڵ��ܸ���Ϊ�����������������������ټ�1�����ڵ㣩 
}
