#include<iostream>
using namespace std;
#define Max 100
struct BiTree
{
	int data;
	BiTree* Lchild;
	BiTree* Rchild;
};
struct Queue//ѭ�����б�ʾ 
{
	BiTree *p;
	int top;
	int bottom;
};
void init_queue(Queue* Q);//��ʼ������
void input_queue(Queue* Q,BiTree *pT);//���
void output_queue(Queue* Q,BiTree &T);//����
BiTree *creat_BiTree();//���������� 
bool full_queue(Queue* Q);//�ж϶����Ƿ�Ϊ�� 
bool empty_queue(Queue* Q);//�ж϶����Ƿ�Ϊ�� 
void travel_BiTree(BiTree* pT);//��α��������� 
int main()
{
	BiTree *pT;
	pT=creat_BiTree();
	cout<<"��α������������Ϊ��";
	travel_BiTree(pT);
	return 0;
}
BiTree *creat_BiTree()
{
	BiTree* pT;
	int input;
	cout<<"������ڵ��ֵ(����-1��ʾ�����սڵ�)��";
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
		cout<<"����Ϊ����"<<endl;
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
		cout<<"����Ϊ�գ�";
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
	/*����˼·��
	ʹ��һ�����У��������ڵ����
	���в���ʱ����ѭ�����Ӷ������г�һ���ڵ�*p,��������
	  ���������ӽڵ㣬�����ӽڵ���ӣ�
	  �������Һ��ӽڵ㣬���Һ��ӽڵ���ӡ�*/
	  Queue Q;
	  init_queue(&Q);//����һ������
	  input_queue(&Q,pT);//���ڵ����
	  BiTree T;//��ų���Ԫ��
	  while(!empty_queue(&Q))//���в��ս���ѭ�� 
	  {
	  	output_queue(&Q,T);
	  	cout<<T.data<<" ";
		if(T.Lchild)//���ӽڵ���� 
		{
			input_queue(&Q,T.Lchild);
		}
		if(T.Rchild)//�Һ��ӽڵ���� 
		{
			input_queue(&Q,T.Rchild);
		} 
	  } 
}


