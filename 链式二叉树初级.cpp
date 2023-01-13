#include<iostream>
using namespace std;
struct BTNode
{
	char data;//������ 
	struct BTNode *pLchild;//������ָ�� 
	struct BTNode *pRchild;//������ָ�� 
};
BTNode *CreateBTree();//������ʽ������ ,�򵥴ֱ�ʽ 
void PreTraverseBTree(BTNode* pT);//������� 
void InTraverseBTree(BTNode* pT);//�������
void PostTraverseBTree(BTNode* pT);//������� 
int main()
{
	BTNode *pT=CreateBTree();
	cout<<"��������Ľ��Ϊ��";
	PreTraverseBTree(pT);
	cout<<endl;
	cout<<"��������Ľ��Ϊ��";
	InTraverseBTree(pT);
	cout<<endl;
	cout<<"��������Ľ��Ϊ��";
	PostTraverseBTree(pT);
	return 0;
}
BTNode *CreateBTree()//�򵥴ֱ� 
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
	//�ȷ��ʸ��ڵ㣬��������������������������������
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
	//�ȷ������������ٷ��ʸ��ڵ㣬�������������
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
	//�ȷ������������ٷ����������������ʸ��ڵ� 
	if(pT!=NULL)
	{
	   PreTraverseBTree(pT->pLchild);
	   PreTraverseBTree(pT->pRchild);
	   cout<<pT->data<<" ";
    }
	return; 
}
/*
ʾ���еĶ����� 
                     ���ڵ�A 
				 B            C
				           D
				               E
*/ 
