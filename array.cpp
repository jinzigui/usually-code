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

	//这个不可思议
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
	std::cout<<p1<<p2<<std::endl;//指向的地址没有发生改变。可是为什么值变了呢？？因为赋值吗？？


	//数组和指针的关系
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


	//指针可以代替数组
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

	//动态数组的创建和使用
	std::cout<<std::endl;
	int total;
	std::cout<<"input total number perple"<<std::endl;
	std::cin>>total;
	//关键在这一步，创建动态数组
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

	//使用的动态内存必须要使用delete删除回收内存
	delete [] p5;

	//创建动态二位数组的方法和创建一维的有些不同
	//有些问题，二位数组创建补成功，在c++中二维数组不这样创建，直接用vector就好了
	/*int k,l;
	std::cout<<"intput k and l :  ";
	std::cin>>k>>l;
	int **p6=new int* [k];   //一维
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