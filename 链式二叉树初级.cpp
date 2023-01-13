#include<iostream>
using namespace std;
struct BTNode
{
	char data;//数据域 
	struct BTNode *pLchild;//左子树指针 
	struct BTNode *pRchild;//右子树指针 
};
BTNode *CreateBTree();//创建链式二叉树 ,简单粗暴式 
void PreTraverseBTree(BTNode* pT);//先序遍历 
void InTraverseBTree(BTNode* pT);//中序遍历
void PostTraverseBTree(BTNode* pT);//后序遍历 
int main()
{
	BTNode *pT=CreateBTree();
	cout<<"先序遍历的结果为：";
	PreTraverseBTree(pT);
	cout<<endl;
	cout<<"中序遍历的结果为：";
	InTraverseBTree(pT);
	cout<<endl;
	cout<<"后序遍历的结果为：";
	PostTraverseBTree(pT);
	return 0;
}
BTNode *CreateBTree()//简单粗暴 
{
	BTNode *pA=new BTNode;
	BTNode *pB=new BTNode;
	BTNode *pC=new BTNode;
	BTNode *pD=new BTNode;
	BTNode *pE=new BTNode;
	pA->data='A';
	pB->data='B';
	pC->data='C';
	pD->data='D';
	pE->data='E';
	pA->pLchild=pB;
	pA->pRchild=pC;
	pB->pLchild=pB->pRchild=NULL;
	pC->pLchild=pD;
	pC->pRchild=NULL;
	pD->pLchild=NULL;
	pD->pRchild=pE;
	pE->pLchild=pE->pRchild=NULL;
	return pA; 
}
void PreTraverseBTree(BTNode* pT)
{
	//先访问根节点，再先序访问左子树，再先序访问右子树
	if(pT!=NULL)
	{
	   cout<<pT->data<<" ";
	   PreTraverseBTree(pT->pLchild);
	   PreTraverseBTree(pT->pRchild);
    }
	return; 
}
void InTraverseBTree(BTNode* pT)
{
	//先访问左子树，再访问根节点，再序访问右子树
	if(pT!=NULL)
	{
	   PreTraverseBTree(pT->pLchild);
	   cout<<pT->data<<" ";
	   PreTraverseBTree(pT->pRchild);
    }
	return; 
}
void PostTraverseBTree(BTNode* pT)
{
	//先访问左子树，再访问右子树，最后访问根节点 
	if(pT!=NULL)
	{
	   PreTraverseBTree(pT->pLchild);
	   PreTraverseBTree(pT->pRchild);
	   cout<<pT->data<<" ";
    }
	return; 
}
/*
示例中的二叉树 
                     根节点A 
				 B            C
				           D
				               E
*/ 
