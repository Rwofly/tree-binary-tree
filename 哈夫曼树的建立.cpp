#include<iostream>
using namespace std;
struct HuffmanTree//��ʾ���������ڵ�Ľṹ��˫�ױ�ʾ�� 
{
	int weight;//�ڵ��Ȩֵ
	int parent;//�ڵ�˫���±� 
	int Lchild;//�ڵ������±� 
	int Rchild; //�ڵ��Һ����±� 
};
void creatHuffmanTree(HuffmanTree* Ht,int n);//������������ ,n��ʾҶ�ӽ���� 
void Select(HuffmanTree* Ht,int &s1,int &s2);
int main()
{
	HuffmanTree Ht;
	int n;
	cout<<"����Ҷ�ӽ��ĸ�����"; 
	cin>>n;
	creatHuffmanTree(&Ht,n);
	return 0;
}
void creatHuffmanTree(HuffmanTree* Ht,int n)
{
	if(n<=1)//Ҷ�ӽڵ���С�ڵ���1ʱ���� 
	{
		return;
	}
	int m=2*n-1;//n��Ҷ�ӽ��Ĺ�����������2n-1���ڵ�
	Ht=new HuffmanTree[m+1];//��һά�Ľṹ���鴢�������������Ϊ�򵥣���0�ŵ�Ԫδ�ã���Ҫ����m+1���ڴ浥Ԫ��Ht[m]��ʾ���ڵ�
	for(int i=1;i<m+1;i++)
	{
		Ht[i].parent=0;
		Ht[i].Lchild=0;
		Ht[i].Rchild=0;//��1--m�ŵ�˫�ס����ӡ��Һ����±궼��ʼ��Ϊ�� ������һ��ɭ�֣�ȫΪ���ڵ� 
	} 
	cout<<"���ǰ"<<n<<"����Ԫ��Ȩֵ��";
	for(int i=1;i<=n;i++)
	{
		cin>>Ht[i].weight;
	}
	//��ʼ��������������ʼ������������ 
	int s1,s2;
	for(int i=n+1;i<=m;i++)//ͨ��n-1��ѡ��ɾ�����ϲ��������������� 
	{
		Select(Ht,s1,s2);//ѡ������˫����Ϊ0������С�Ľڵ㣬������������Ht����ţ�s1��s2
		Ht[s1].parent=i;
		Ht[s2].parent=i;//�õ��½ڵ�i,��ɭ����ɾ��s1,s2,��s1��s2��˫������0��Ϊi,s1��s2����Ϊ���ڵ� 
		Ht[i].Lchild=s1;
		Ht[i].Rchild=s2;//s1,s2,�ֱ���Ϊi�����Һ���
		Ht[i].weight=Ht[s1].weight+Ht[s2].weight;//i��ȨֵΪ���Һ���֮�� 
	}
	cout<<"�������������ɹ���"<<endl;
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
	for(int i=1;i<=count-1;i++)//ѡ���������� 
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
	while(1)//ѡ�����ڵ���������Сֵ���±� 
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
