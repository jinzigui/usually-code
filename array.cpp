#include<iostream>
int main()
{
	int a[4][4];
	int index1,index2;
	for (index1=0;index1<4;index1++)
	{
		for(index2=0;index2<4;index2++)
		{
			a[index1][index2]=index2;
		}
	}
	for (index1=0;index1<4;index1++)
	{
		for(index2=0;index2<4;index2++)
		{
			std::cout<<a[index1][index2]<<"  ";
		}
	}
	int *p1,*p2,num=8;
	p1=&num;
	p2=p1;
	std::cout<<*p1<<*p2<<num<<std::endl;

	//�������˼��
	p1=new int;
	*p1=48;
	p2=p1;
	std::cout<<*p1<<*p2<<std::endl;
	*p2 =58;
	std::cout<<*p1<<*p2<<std::endl;
	

	p1=new int;
	p2=new int;
	*p1=89;
	*p2=90;
	std::cout<<*p1<<*p2<<std::endl;
	*p1=*p2;
	std::cout<<*p1<<*p2<<std::endl;
	std::cout<<p1<<p2<<std::endl;//ָ��ĵ�ַû�з����ı䡣����Ϊʲôֵ�����أ�����Ϊ��ֵ�𣿣�


	//�����ָ��Ĺ�ϵ
	int *p3;
	int number[10];
	int i;
	for( i=0;i<10;i++)
	{
		number[i]=i;
	}
	p3=number;
	for(i=0;i<10;i++)
	{
		std::cout<<p3[i]<<" ";
	}
	std::cout<<*(p3+5)<<" ";


	//ָ����Դ�������
	int *p4;
	p4=new int;
	for(i=0;i<10;i++)
	{
		*(p4+i)=i;
	}
	for(i=0;i<10;i++)
	{
		std::cout<<*(p4+i)<<" ";
	}
	//delete p4;

	//��̬����Ĵ�����ʹ��
	std::cout<<std::endl;
	int total;
	std::cout<<"input total number perple"<<std::endl;
	std::cin>>total;
	//�ؼ�����һ����������̬����
	int *p5;
	p5= new int [total];

	std::cout<<"input the perple id"<<std::endl;
	for(int j=0;j<total;j++)
	{
		std::cin>>*(p5+j);
	}
	for(int j=0;j<total;j++)
	{
		std::cout<<*(p5+j);
	}

	//ʹ�õĶ�̬�ڴ����Ҫʹ��deleteɾ�������ڴ�
	delete [] p5;

	//������̬��λ����ķ����ʹ���һά����Щ��ͬ
	//��Щ���⣬��λ���鴴�����ɹ�����c++�ж�ά���鲻����������ֱ����vector�ͺ���
	/*int k,l;
	std::cout<<"intput k and l :  ";
	std::cin>>k>>l;
	int **p6=new int* [k];   //һά
	int h, m;
	for(h=0;h<k;k++)
	{
		p6[h]=new int[l];
	}
	std::cout<<k<<"*"<<l<<std::endl;
	for(int t=0;t<h;t++)
	{
		for(int g=0;g<l;g++)
		{
			std::cin>>p6[t][g];
		}
	}
	for(int t=0;t<h;t++)
	{
		for(int g=0;g<l;g++)
		{
			std::cout<<p6[t][g];
		}
	}

	std::cout<<std::endl;
	for(int n=0;n<k;n++)
	{
		delete p6[n];
	}
	delete [] p6;*/
}