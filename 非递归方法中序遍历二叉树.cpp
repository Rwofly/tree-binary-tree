#include<iostream>//用栈实现二叉树的中序遍历 
using namespace std;
#define Max 100//用顺序栈实现 
struct BiTree//表示二叉树的结构体 
{
	int data;
	BiTree *Lchild;//左子树指针 
	BiTree *Rchild;//右子树指针
};
struct Stack//表示栈的结构体 
{
	BiTree *top;
	BiTree *base;
	int maxsize;//栈最大可用容量 
};
void init_stack(Stack *S);//初始化栈 
void push_stack(Stack *S,BiTree pT);//入栈 
BiTree *pop_stack(Stack *S);//出栈 
bool empty_stack(Stack *S);//判断栈是否为空 
bool full_stack(Stack *S);//判断栈是否为满
BiTree *creat_tree();//创建二叉树
void intravel(BiTree *pT);//递归方法中序遍历二叉树
void stack_tree(BiTree *pT);//顺序栈方法中序遍历二叉树
int main()
{
	BiTree *pT;
	pT=creat_tree();
	cout<<"递归方法中序遍历二叉树结果为：";
	intravel(pT);
	cout<<endl;
	cout<<"栈方法中序遍历二叉树结果为：";
	stack_tree(pT);
	cout<<endl; 
	return 0;
} 
void init_stack(Stack *S)
{
	S->base=new BiTree[Max];//创建一个BiTree类型的数组，数组元素为Max个 
	S->top=S->base;
	S->maxsize=Max;
	return;
}
void push_stack(Stack *S,BiTree pT)
{
	if(full_stack(S))
	{
		cout<<"栈已满"<<endl;
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
		cout<<"栈为空"<<endl;
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
	cout<<"输入该节点的值(输入-1表示建立空节点):";
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
	init_stack(&S);//初始化一个空栈S
	BiTree *p=pT;//指针p指向根节点
	BiTree *q=new BiTree;//申请一个节点空间q，用来存放栈顶弹出的元素
	while(p||!empty_stack(&S))//p非空，或者栈s非空时循环以下操作 
	{
		if(p)
		{
			push_stack(&S,*p);//根指针进栈 
			p=p->Lchild;//根指针进栈，遍历左子树 
		}else
		{
			q=pop_stack(&S);//退栈 
			cout<<q->data<<" ";//遍历根节点 
			p=q->Rchild;//遍历右子树 
		}
    }
    return;
}
/*void pop_stack(Stack *S,BiTree *pT)
{
	if(empty_stack(S))
	{
		cout<<"栈为空"<<endl;
		return;
	}
	pT=S->top;
	S->top--;
	return;
}
void stack_tree(BiTree *pT)
{
	Stack S;
	init_stack(&S);//初始化一个空栈S
	BiTree *p=pT;//指针p指向根节点v
	BiTree *q=new BiTree;//申请一个节点空间q，用来存放栈顶弹出的元素
	while(p||!empty_stack(&S))//p非空，或者栈s非空时循环以下操作 
	{
		if(p)
		{
			push_stack(&S,*p);//根指针进栈 
			p=p->Lchild;//根指针进栈，遍历左子树 
		}else
		{
			pop_stack(&S,q);//退栈 
			cout<<q->data<<" ";//遍历根节点 
			p=q->Rchild;//遍历右子树 
		}
    }
    return;
}
这种情况实现不了，pop_stack()函数有无返回值的问题。我也不清楚具体原因，希望有人可以解答*/