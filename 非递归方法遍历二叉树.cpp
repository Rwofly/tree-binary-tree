#include<iostream>
using namespace std;
#define Max 100
struct BiTree
{
	int data;
	BiTree* Lchild;
	BiTree* Rchild;
};
BiTree *creatBiTree();//生成二叉树
void pretravel(BiTree* pT);//先序遍历
void intravel(BiTree* pT);//中序遍历
void posttravel(BiTree* pT);//后序遍历
int main()
{
	BiTree* pT=NULL;
	pT=creatBiTree();
	cout << "前序遍历的结果为：";
	pretravel(pT);
	cout << endl;
	cout << "中序遍历的结果为：";
	intravel(pT);
	cout << endl;
	cout << "后序遍历的结果为：";
	posttravel(pT);
	cout << endl;
	return 0;
}
BiTree *creatBiTree()
{
	BiTree* pT;
	int input;
	cout << "请输入该节点的值(输入-1表示建立新的节点)：";
	cin >> input;
	if (input == -1)
	{
		pT = NULL;
		return pT;
	}
	pT = new BiTree;
	pT->data = input;
	pT->Lchild=creatBiTree();
	pT->Rchild=creatBiTree();
	return pT;
}
void intravel(BiTree* pT)
{
	BiTree stack[Max];//分配一个BiTree类型的数组，当做顺序栈实现。比链栈的实现要简单，但是容易浪费内存，不够灵活 。
	BiTree node;//接受弹出栈的元素
	BiTree* p=pT;
	int n = 0;
	while (p || n > 0)
	{
		if (p)
		{
			n++;
			stack[n] = *p;//入栈
			p = p->Lchild;//遍历左子树
		}
		else
		{
			node = stack[n];
			n--;//出栈
			cout<<node.data<<" ";//访问根节点
			p = node.Rchild;//遍历右子树
		}
	}

}
void pretravel(BiTree* pT)
{
	BiTree stack[Max];
	BiTree node;
	BiTree* p=pT;
	int n = 0;
	while (p || n > 0)
	{
		if (p)
		{
			cout << p->data << " ";//访问根节点
			n++;
			stack[n] = *p;//入栈
			p = p->Lchild;//遍历左节点
		}
		else
		{
			node = stack[n];
			n--;//出栈
			p = node.Rchild;
		}
	}
	return;
}
void posttravel(BiTree* pT)//后序遍历较为麻烦，具体思路：
{                         //后序遍历顺序为左-右-根。可以把后序当成根-右-左，最后在反转即可
	BiTree stack[Max];
	BiTree node;
	BiTree* p = pT;
	int n=0;
	int count = 0;
	int array[Max];//使用数组保存数据，方便最后数组反转
	n++;
	stack[n] = *p;//根节点入栈
	while (n > 0)
	{
		node = stack[n];
		n--;//弹出
		array[count] = node.data;
		count++;//将数据保存在一个数组中
		if (node.Lchild)
		{
			n++;
			stack[n] = *node.Lchild;//入栈
		}
		if (node.Rchild)
		{
			n++;
			stack[n] = *node.Rchild;//入栈
		}
	}
	for (int i = count - 1;i >= 0;i--)//数组反转
	{
		cout << array[i] << " ";
	}
	return;
}
