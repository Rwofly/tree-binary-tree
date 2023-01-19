#include<iostream>
using namespace std;
struct HuffmanTree//表示哈夫曼树节点的结构，双亲表示法 
{
	int weight;//节点的权值
	int parent;//节点双亲下标 
	int Lchild;//节点左孩子下标 
	int Rchild; //节点右孩子下标 
};
void creatHuffmanTree(HuffmanTree* Ht,int n);//创建哈夫曼树 ,n表示叶子结点数 
void Select(HuffmanTree* Ht,int &s1,int &s2);
int main()
{
	HuffmanTree Ht;
	int n;
	cout<<"输入叶子结点的个数："; 
	cin>>n;
	creatHuffmanTree(&Ht,n);
	return 0;
}
void creatHuffmanTree(HuffmanTree* Ht,int n)
{
	if(n<=1)//叶子节点数小于等于1时返回 
	{
		return;
	}
	int m=2*n-1;//n个叶子结点的哈夫曼树上有2n-1个节点
	Ht=new HuffmanTree[m+1];//用一维的结构数组储存哈夫曼树（较为简单），0号单元未用，需要分配m+1个内存单元，Ht[m]表示根节点
	for(int i=1;i<m+1;i++)
	{
		Ht[i].parent=0;
		Ht[i].Lchild=0;
		Ht[i].Rchild=0;//将1--m号的双亲、左孩子、右孩子下标都初始化为零 。构造一个森林，全为根节点 
	} 
	cout<<"输出前"<<n<<"个单元的权值：";
	for(int i=1;i<=n;i++)
	{
		cin>>Ht[i].weight;
	}
	//初始化工作结束，开始创建哈夫曼树 
	int s1,s2;
	for(int i=n+1;i<=m;i++)//通过n-1次选择、删除、合并来创建哈夫曼树 
	{
		Select(Ht,s1,s2);//选出两个双亲域为0并且最小的节点，并返回他们在Ht中序号，s1和s2
		Ht[s1].parent=i;
		Ht[s2].parent=i;//得到新节点i,从森林中删除s1,s2,将s1、s2的双亲域由0改为i,s1、s2不在为根节点 
		Ht[i].Lchild=s1;
		Ht[i].Rchild=s2;//s1,s2,分别作为i的左右孩子
		Ht[i].weight=Ht[s1].weight+Ht[s2].weight;//i的权值为左右孩子之和 
	}
	cout<<"哈夫曼树创建成功！"<<endl;
	return;
}
void Select(HuffmanTree* Ht,int &s1,int &s2)
{
	HuffmanTree* HT=Ht;
	int count=1;
	while(Ht[count].weight)
	{
		count++;
	}
	HuffmanTree temp;
	for(int i=1;i<=count-1;i++)//选择排序法排序 
	{
		for(int j=i+1;j<=count;j++)
		{
			if(HT[i].weight>HT[j].weight)
			{
				temp=HT[i];
				HT[i]=HT[j];
				HT[j]=temp;
			}
		}
	}
	int k=1;
	while(1)//选出根节点中两个最小值的下标 
	{
		if(HT[k].parent==0)
		{
			s1=k;
			k++;
			break;
		}
		k++;
	}
	while(1)
	{
		if(HT[k].parent==0)
		{
			s2=k;
			k++;
			break;
		}
		k++;
	}
	return;
}
