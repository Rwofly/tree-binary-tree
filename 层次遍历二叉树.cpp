#include<iostream>
using namespace std;
#define Max 100
struct BiTree
{
	int data;
	BiTree* Lchild;
	BiTree* Rchild;
};
struct Queue//循环队列表示 
{
	BiTree *p;
	int top;
	int bottom;
};
void init_queue(Queue* Q);//初始化队列
void input_queue(Queue* Q,BiTree *pT);//入队
void output_queue(Queue* Q,BiTree &T);//出队
BiTree *creat_BiTree();//创建二叉树 
bool full_queue(Queue* Q);//判断队列是否为满 
bool empty_queue(Queue* Q);//判断队列是否为空 
void travel_BiTree(BiTree* pT);//层次遍历二叉树 
int main()
{
	BiTree *pT;
	pT=creat_BiTree();
	cout<<"层次遍历二叉树结果为：";
	travel_BiTree(pT);
	return 0;
}
BiTree *creat_BiTree()
{
	BiTree* pT;
	int input;
	cout<<"请输入节点的值(输入-1表示建立空节点)：";
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
void init_queue(Queue* Q)
{
	Q->p=new BiTree[Max];
	Q->bottom=0;
	Q->top=0;
	return;
}
void input_queue(Queue* Q,BiTree *p)
{
	if(full_queue(Q))
	{
		cout<<"队列为满！"<<endl;
		return;
	}
	Q->p[Q->top]=*p;
	Q->top=(Q->top+1)%Max;
	return;
}
void output_queue(Queue* Q,BiTree &T)
{
	if(empty_queue(Q))
	{
		cout<<"队列为空！";
		return;
	}
	T=Q->p[Q->bottom];
	Q->bottom=(Q->bottom+1)%Max;
	return;
}
bool empty_queue(Queue* Q)
{
	if(Q->bottom==Q->top)
	{
		return true;
	}
	return false;
}
bool full_queue(Queue* Q)
{
	if((Q->top+1)%Max==Q->bottom)
	{
		return true;
	}
	return false;
}
void travel_BiTree(BiTree* pT)
{
	/*具体思路：
	使用一个队列，并将根节点进队
	队列不空时进行循环，从队列中列出一个节点*p,访问它：
	  若它有左孩子节点，将左孩子节点进队；
	  若它有右孩子节点，将右孩子节点进队。*/
	  Queue Q;
	  init_queue(&Q);//申请一个队列
	  input_queue(&Q,pT);//根节点入队
	  BiTree T;//存放出队元素
	  while(!empty_queue(&Q))//队列不空进行循环 
	  {
	  	output_queue(&Q,T);
	  	cout<<T.data<<" ";
		if(T.Lchild)//左孩子节点入队 
		{
			input_queue(&Q,T.Lchild);
		}
		if(T.Rchild)//右孩子节点入队 
		{
			input_queue(&Q,T.Rchild);
		} 
	  } 
}


