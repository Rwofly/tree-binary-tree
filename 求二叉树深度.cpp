#include<iostream>
using namespace std;
struct BiTree
{
	int data;
	BiTree *Lchild;
	BiTree *Rchild;
};
BiTree *creat_BiTree();//���������� 
int depth_BiTree(BiTree* pT);//���������� 
int main()
{
	BiTree* pT;
	pT=creat_BiTree();
	int depth=depth_BiTree(pT);
	cout<<"�ö��������Ϊ��"<<depth<<endl;
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
 int depth_BiTree(BiTree* pT)
 {
 	if(pT==NULL)
 	{
 		return 0;//����ǿ����������Ϊ�� 
	}
	int m=0,n=0;
	m=depth_BiTree(pT->Lchild);//������������ȼ�Ϊm
	n=depth_BiTree(pT->Rchild);//��������������ȼ�Ϊn
	if(m>n)//�����������Ϊm��n�ϴ��߼�һ 
	{
		return (m+1);
	 } else
	 {
	 	return (n+1);
	 }
 }
