#include<iostream>
using namespace std;
struct BiTree
{
	int data;
	BiTree *Lchild;
	BiTree *Rchild;
};
BiTree *creat_BiTree();//���������� 
int Leaf_count(BiTree* pT);//��Ҷ�ӽڵ�ĸ��� 
int main()
{
	BiTree* pT;
	pT=creat_BiTree();
	int count=Leaf_count(pT);
	cout<<"Ҷ�ӽڵ���Ϊ��"<<count<<endl; 
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
int Leaf_count(BiTree* pT)
{
	if(pT==NULL)
	{
		return 0;//��Ϊ�գ�Ҷ�ӽ��Ϊ0 
	}
	if(pT->Lchild==NULL&&pT->Rchild==NULL)
	{
		return 1;//�������ָ�붼ΪNULL,��ʾΪһ��Ҷ�ӽڵ� 
	}else
	{
		return Leaf_count(pT->Lchild)+Leaf_count(pT->Rchild);//��������Ҷ�ӽڵ����������Ҷ�ӽڵ� 
	}
}
