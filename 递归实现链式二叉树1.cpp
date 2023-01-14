#include<iostream>
using namespace std;
struct BiTree
{
	int data;
	BiTree* Lchild;
	BiTree* Rchild;
};
BiTree *creatBiTree();//递归法创建二叉树，先序创建
void pretravel(BiTree* pT);//先序遍历二叉树
void intravel(BiTree* pT);//中序遍历二叉树
void posttravel(BiTree* pT);//后序遍历二叉树 
int main()
{
	BiTree* pT;
	pT=creatBiTree();
	cout << "先序遍历的结果是：";
	pretravel(pT);
	cout << endl;
	cout << "中序遍历的结果是：";
	intravel(pT);
	cout << endl;
	cout << "后序遍历的结果是：";
	posttravel(pT);
	return 0;
}
BiTree *creatBiTree()//先序遍历，使用递归方法 
{
	BiTree* pT;
	int input;
	cout << "输入该节点的值(输入-1表示建立空节点):";
	cin >> input;
	if (input == -1)
	{
		pT = NULL;
		return pT;
	}
	pT = new BiTree;//创建新节点 
	pT->data = input;
	pT->Lchild=creatBiTree();//左子树的递归 
	pT->Rchild=creatBiTree();//右子树的递归
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