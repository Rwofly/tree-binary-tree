#include<iostream>
using namespace std;
struct BiTree
{
	int data;
	BiTree *Lchild;
	BiTree *Rchild;
};
BiTree *creat_BiTree();//创建二叉树 
int Node_count(BiTree* pT);//求二叉树节点个数 
int main()
{
	BiTree* pT;
	pT=creat_BiTree();
	int count=Node_count(pT);
	cout<<"树的节点个数为："<<count<<endl; 
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
int Node_count(BiTree* pT)
{
	if(pT==NULL)
	{
		return 0;//根节点为空，节点个数为零 
	}
	return Node_count(pT->Lchild)+Node_count(pT->Rchild)+1;//节点总个数为左子树个数加右子树个数再加1（根节点） 
}
