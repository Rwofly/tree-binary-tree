#include<iostream>
using namespace std;
struct BiTree
{
	int data;
	BiTree *Lchild;
	BiTree *Rchild;
};
BiTree *creat_BiTree();//创建二叉树 
int Leaf_count(BiTree* pT);//求叶子节点的个数 
int main()
{
	BiTree* pT;
	pT=creat_BiTree();
	int count=Leaf_count(pT);
	cout<<"叶子节点数为："<<count<<endl; 
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
int Leaf_count(BiTree* pT)
{
	if(pT==NULL)
	{
		return 0;//树为空，叶子结点为0 
	}
	if(pT->Lchild==NULL&&pT->Rchild==NULL)
	{
		return 1;//如果左右指针都为NULL,表示为一个叶子节点 
	}else
	{
		return Leaf_count(pT->Lchild)+Leaf_count(pT->Rchild);//左子树的叶子节点加上右子树叶子节点 
	}
}
