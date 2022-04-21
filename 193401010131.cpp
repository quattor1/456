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
    //��HT[1...i]��ѡ��parentΪ0��Ȩֵ��С�Ľ��  
    //���ظý����±�ֵ  
    //�˺�����Select��������  
    int j;  
    unsigned int k = UINT_iMAX;//���������Ȩֵ���ᳬ��UINT_MAX  
    int flag;  
    for(j = 0; j <= i; ++j)  
    {  
        if(HT[j].weight < k && HT[j].parent == 0)//�ø�����Ƿ�Ϊ0���жϴ˽���Ƿ��Ѿ���ѡ��  
        {  
            k = HT[j].weight;  
            flag = j;  
        }  
    }  
    HT[flag].parent = 1;//������ǣ�˵���Ѿ���ѡ���ˣ���Ϊ��Select������Ҫѡ��ȨֵС���������  
    return flag;  
}  
  
void Select(HuffmanTree &HT, int i, int &s1, int &s2)  
{  
    //��HT[1...i]��ѡ��parentΪ0��Ȩֵ��С��������㣬����ŷֱ�Ϊs1,s2  
    //s1 <= s2  
    s1 = Min(HT,i);  
    s2 = Min(HT,i);  
}  
  
void CreateHuffmanTree(HuffmanTree &HT, char t[], int w[])
{
	//cout<<"nihao1"<<endl;
	int m;
	int i, s1, s2;
	if(n<=1)//���ֻ��һ���Ͳ��ô���
	return ;
	m=2*n-1; //�ܹ���Ҫ2n��1���ڵ�
	HT=new HTNode[m+1];//���ٿռ�
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
	Select(HT, i-1,s1, s2);//��n�������ҳ�Ȩֵ��С������
	
	HT[s1].parent=i;
	HT[s2].parent=i;//������������parent�ڵ�����Ϊi;
	
	HT[i].lchild=s1;
	HT[i].rchild=s2;//���������ֱ������ҽڵ�
	HT[i].weight=HT[s1].weight+HT[s2].weight;//����������˫��Ϊ���������ĺͣ�
	
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
	cout<<"�ַ�����Ϊ��"<<endl;
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
    char a[100], buff[1024];//aΪ����ַ� buffΪ������ַ��� 
    int b[100];//���Ȩֵ��Ϣ 
    int  i, j;
	int symbol=1, x, k; //����ʱ���ж��õı���  
    cout<<"������һ���ַ�:";
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
	cout<<"�ַ���Ȩֵ��Ϣ����"<<endl;
	 for (i=0;i<n;i++)
	 {
	  cout<<"�ַ���"<<a[i]<<"  Ȩֵ��"<<b[i]<<endl;
	 }
 
    CreateHuffmanTree(HT, a, b);
    CreatHuffmanCode(HT);
   return 0;
}
 
 
 	