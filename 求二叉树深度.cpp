#include<iostream>
using namespace std;
struct BiTree
{
	int data;
	BiTree *Lchild;
	BiTree *Rchild;
};
BiTree *creat_BiTree();//创建二叉树 
int depth_BiTree(BiTree* pT);//求二叉树深度 
int main()
{
	BiTree* pT;
	pT=creat_BiTree();
	int depth=depth_BiTree(pT);
	cout<<"该二叉树深度为："<<depth<<endl;
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
 int depth_BiTree(BiTree* pT)
 {
 	if(pT==NULL)
 	{
 		return 0;//如果是空树，则深度为零 
	}
	int m=0,n=0;
	m=depth_BiTree(pT->Lchild);//计算左子树深度记为m
	n=depth_BiTree(pT->Rchild);//计算右子树的深度记为n
	if(m>n)//二叉树的深度为m与n较大者加一 
	{
		return (m+1);
	 } else
	 {
	 	return (n+1);
	 }
 }
