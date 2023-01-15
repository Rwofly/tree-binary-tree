#include<iostream>//��ջʵ�ֶ�������������� 
using namespace std;
#define Max 100//��˳��ջʵ�� 
struct BiTree//��ʾ�������Ľṹ�� 
{
	int data;
	BiTree *Lchild;//������ָ�� 
	BiTree *Rchild;//������ָ��
};
struct Stack//��ʾջ�Ľṹ�� 
{
	BiTree *top;
	BiTree *base;
	int maxsize;//ջ���������� 
};
void init_stack(Stack *S);//��ʼ��ջ 
void push_stack(Stack *S,BiTree pT);//��ջ 
BiTree *pop_stack(Stack *S);//��ջ 
bool empty_stack(Stack *S);//�ж�ջ�Ƿ�Ϊ�� 
bool full_stack(Stack *S);//�ж�ջ�Ƿ�Ϊ��
BiTree *creat_tree();//����������
void intravel(BiTree *pT);//�ݹ鷽���������������
void stack_tree(BiTree *pT);//˳��ջ�����������������
int main()
{
	BiTree *pT;
	pT=creat_tree();
	cout<<"�ݹ鷽������������������Ϊ��";
	intravel(pT);
	cout<<endl;
	cout<<"ջ��������������������Ϊ��";
	stack_tree(pT);
	cout<<endl; 
	return 0;
} 
void init_stack(Stack *S)
{
	S->base=new BiTree[Max];//����һ��BiTree���͵����飬����Ԫ��ΪMax�� 
	S->top=S->base;
	S->maxsize=Max;
	return;
}
void push_stack(Stack *S,BiTree pT)
{
	if(full_stack(S))
	{
		cout<<"ջ����"<<endl;
		return;
	}
	S->top++;
	*S->top=pT;
	return;
}
BiTree *pop_stack(Stack *S)
{
	BiTree *pT=NULL;
	if(empty_stack(S))
	{
		cout<<"ջΪ��"<<endl;
		return pT;
	}
	pT=S->top;
	S->top--;
	return pT;
}
bool empty_stack(Stack *S)
{
	if(S->base==S->top)
	{
		return true;
	}
	return false;
}
bool full_stack(Stack *S)
{
	if(S->top-S->base==S->maxsize)
	{
		return true;
	}
	return false;
}
BiTree *creat_tree()
{
	int input;
	BiTree *pT;
	cout<<"����ýڵ��ֵ(����-1��ʾ�����սڵ�):";
	cin>>input;
	if(input==-1)
	{
		pT=NULL;
		return pT;
	}
	pT=new BiTree;
	pT->data=input;
	pT->Lchild=creat_tree();
	pT->Rchild=creat_tree();
	return pT;
}
void intravel(BiTree *pT)
{
	if(pT!=NULL)
	{
		intravel(pT->Lchild);
		cout<<pT->data<<" ";
		intravel(pT->Rchild);
	}
	return;
}
void stack_tree(BiTree *pT)
{
	Stack S;
	init_stack(&S);//��ʼ��һ����ջS
	BiTree *p=pT;//ָ��pָ����ڵ�
	BiTree *q=new BiTree;//����һ���ڵ�ռ�q���������ջ��������Ԫ��
	while(p||!empty_stack(&S))//p�ǿգ�����ջs�ǿ�ʱѭ�����²��� 
	{
		if(p)
		{
			push_stack(&S,*p);//��ָ���ջ 
			p=p->Lchild;//��ָ���ջ������������ 
		}else
		{
			q=pop_stack(&S);//��ջ 
			cout<<q->data<<" ";//�������ڵ� 
			p=q->Rchild;//���������� 
		}
    }
    return;
}
/*void pop_stack(Stack *S,BiTree *pT)
{
	if(empty_stack(S))
	{
		cout<<"ջΪ��"<<endl;
		return;
	}
	pT=S->top;
	S->top--;
	return;
}
void stack_tree(BiTree *pT)
{
	Stack S;
	init_stack(&S);//��ʼ��һ����ջS
	BiTree *p=pT;//ָ��pָ����ڵ�v
	BiTree *q=new BiTree;//����һ���ڵ�ռ�q���������ջ��������Ԫ��
	while(p||!empty_stack(&S))//p�ǿգ�����ջs�ǿ�ʱѭ�����²��� 
	{
		if(p)
		{
			push_stack(&S,*p);//��ָ���ջ 
			p=p->Lchild;//��ָ���ջ������������ 
		}else
		{
			pop_stack(&S,q);//��ջ 
			cout<<q->data<<" ";//�������ڵ� 
			p=q->Rchild;//���������� 
		}
    }
    return;
}
�������ʵ�ֲ��ˣ�pop_stack()�������޷���ֵ�����⡣��Ҳ���������ԭ��ϣ�����˿��Խ��*/