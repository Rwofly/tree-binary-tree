#include<iostream>
using namespace std;
struct BiTree
{
	int data;
	BiTree *Lchild;
	BiTree *Rchild;
};
BiTree *creat_BiTree();//创建 二叉树 
BiTree *copy_BiTree(BiTree* pT);//复制二叉树
void pretravel(BiTree* pT);//先序遍历二叉树 
int main()
{
	BiTree *pT,*NewpT;
	pT=creat_BiTree();
	cout<<"原二叉树的值为：";
	pretravel(pT);
	cout<<endl;
NewpT=copy_BiTree(pT);
	cout<<"复制的二叉树的值为：";
	pretravel(NewpT);
	return 0;
}
BiTree *creat_BiTree()
{
	BiTree* pT;
	int input;
	cout<<"输入节点的值(输入-1表示建立空节点):";
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
	if(pT==NULL)// 如果树为空，递归结束
	{
		NewpT=NULL;
		return NewpT;
	}
	NewpT=new BiTree;//否则，申请新的节点空间，复制根节点 
	NewpT->data=pT->data;
	NewpT->Lchild=(pT->Lchild);//递归复制左子树 
	NewpT->Rchild=(pT->Rchild);//递归复制右子树 
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

