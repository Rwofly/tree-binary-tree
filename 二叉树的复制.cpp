#include<iostream>
using namespace std;
struct BiTree
{
	int data;
	BiTree *Lchild;
	BiTree *Rchild;
};
BiTree *creat_BiTree();//���� ������ 
BiTree *copy_BiTree(BiTree* pT);//���ƶ�����
void pretravel(BiTree* pT);//������������� 
int main()
{
	BiTree *pT,*NewpT;
	pT=creat_BiTree();
	cout<<"ԭ��������ֵΪ��";
	pretravel(pT);
	cout<<endl;
NewpT=copy_BiTree(pT);
	cout<<"���ƵĶ�������ֵΪ��";
	pretravel(NewpT);
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
BiTree *copy_BiTree(BiTree* pT)
{ 
    BiTree* NewpT;
	if(pT==NULL)// �����Ϊ�գ��ݹ����
	{
		NewpT=NULL;
		return NewpT;
	}
	NewpT=new BiTree;//���������µĽڵ�ռ䣬���Ƹ��ڵ� 
	NewpT->data=pT->data;
	NewpT->Lchild=(pT->Lchild);//�ݹ鸴�������� 
	NewpT->Rchild=(pT->Rchild);//�ݹ鸴�������� 
	return NewpT;
}
void pretravel(BiTree* pT)
{
	if(pT)
	{
		cout<<pT->data<<" ";
		pretravel(pT->Lchild);
		pretravel(pT->Rchild);
	}
	return; 
}

