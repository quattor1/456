#include<iostream>
#include<string.h>
#define  UINT_iMAX 10000 
using namespace std;
 
typedef struct {
	char letter, *code;
	int weight;
	int parent, lchild, rchild;
}HTNode, *HuffmanTree;
 
int n;
char coding[100];
 
int Min(HuffmanTree &HT,int i)  
{  
    //在HT[1...i]中选择parent为0且权值最小的结点  
    //返回该结点的下标值  
    //此函数被Select函数调用  
    int j;  
    unsigned int k = UINT_iMAX;//假设各结点的权值不会超过UINT_MAX  
    int flag;  
    for(j = 0; j <= i; ++j)  
    {  
        if(HT[j].weight < k && HT[j].parent == 0)//用父结点是否为0来判断此结点是否已经被选过  
        {  
            k = HT[j].weight;  
            flag = j;  
        }  
    }  
    HT[flag].parent = 1;//作个标记，说明已经被选择了，因为在Select函数中要选择权值小的两个结点  
    return flag;  
}  
  
void Select(HuffmanTree &HT, int i, int &s1, int &s2)  
{  
    //在HT[1...i]中选择parent为0且权值最小的两个结点，其序号分别为s1,s2  
    //s1 <= s2  
    s1 = Min(HT,i);  
    s2 = Min(HT,i);  
}  
  
void CreateHuffmanTree(HuffmanTree &HT, char t[], int w[])
{
	//cout<<"nihao1"<<endl;
	int m;
	int i, s1, s2;
	if(n<=1)//如果只有一个就不用创建
	return ;
	m=2*n-1; //总共需要2n－1个节点
	HT=new HTNode[m+1];//开辟空间
	for(i=0; i<n; i++)
	{
		HT[i].code='\0';
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
		HT[i].letter=t[i];
		HT[i].weight=w[i]; 
	
	}
	for(i=n; i<=m; i++)
	{
		HT[i].code='\0';
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
		HT[i].letter=' ';
		HT[i].weight=0;
	}
	cout<<"++++++++++++++"<<endl;
	for(i=n; i<m; i++)
	{
	Select(HT, i-1,s1, s2);//在n个数中找出权值最小的两个
	
	HT[s1].parent=i;
	HT[s2].parent=i;//将他们两个的parent节点设置为i;
	
	HT[i].lchild=s1;
	HT[i].rchild=s2;//把这两个分别当作左右节点
	HT[i].weight=HT[s1].weight+HT[s2].weight;//他们两个的双亲为他们两个的和；
	
	}
}
void CreatHuffmanCode(HuffmanTree HT)
{
	int start, c, f;
	int i;
	char *cd=new char [n]; 
	
	cd[n-1]='\0';
	//for(i=0; i<2*n; i++)
//	cout<<HT[i].letter<<":"<<HT[i].lchild<<":"<<HT[i].rchild<<HT[i].weight<<endl;
	cout<<"字符编码为："<<endl;
	for(i=0; i<n; i++)
	{
	
	start=n-1;
	c=i;
	f=HT[i].parent;
	
		while(f!=0){
			--start;
			if(HT[f].lchild==c){
			
				cd[start]='0';
			}
			else{
			 
				cd[start]='1';
			}
			c=f;
			f=HT[f].parent;
		}
	
	HT[i].code=new char[n-start];
	strcpy(HT[i].code,&cd[start]);
	cout<<HT[i].letter<<":"<<HT[i].code<<endl;
	}
	
	delete cd;
	
}
int main()  
{  
    HuffmanTree HT;  
    //HuffmanCode HC;  
    char a[100], buff[1024];//a为存放字符 buff为输入的字符串 
    int b[100];//存放权值信息 
    int  i, j;
	int symbol=1, x, k; //译码时做判断用的变量  
    cout<<"请输入一段字符:";
    cin.getline(buff,1024);
    int len=strlen(buff);
 	for (i=0;i<len;i++)
 	{
 		//	cout<<n<<"________________"<<endl; 
		  for(j=0; j<n;  j++)
		  {
				   if (a[j]==buff[i])
				   {
				   	 	b[j]=b[j]+1;
				    	break;
				   }
		  }
		if (j>=n)
		{
			a[n]=buff[i];
			b[n]=1;
			n++;
		}
 	} 
	cout<<"字符和权值信息如下"<<endl;
	 for (i=0;i<n;i++)
	 {
	  cout<<"字符："<<a[i]<<"  权值："<<b[i]<<endl;
	 }
 
    CreateHuffmanTree(HT, a, b);
    CreatHuffmanCode(HT);
   return 0;
}
 
 
 	