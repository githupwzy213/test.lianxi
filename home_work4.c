#include<stdio.h>
//���Ͼ������⣺��һ�����־��󣬾����ÿһ�д������ǵ����ģ�������ϵ����ǵ����ģ�
//��д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��ʱ�临�Ӷ�С��O��n)
//1,2,3 1,2,3
//4,5,6 2,3,4
//7,8,9 3,4,5
int FindNum1(int arr[3][3],int num,int row,int col)
{
	//���Ͻ�Ԫ���±�
	int x = 0;
	int y = col - 1;
	while (x<row&&col>=0)//�������б������������
	{
		if (num < arr[x][y])//���Ͻ�Ԫ���±���0��col-1
			col--;
		else if (num > arr[x][y])
			row++;
		else
			return 1;//���Ҫ��ӡ������ò�Ҫ�ں�������printf����
		//return x,y;����д��Ҳ�Ǵ���ģ����ص��Ƕ��ű���ʽ��ֵ��y��ֵ
	}
	return 0;
}
int FindNum2(int arr[3][3], int num,int *px,int *py)
{
	//���Ͻ�Ԫ���±�
	int x = 0;
	int y = *py - 1;
	while (x < *px && y >= 0)//�������б������������
	{
		if (num < arr[x][y])//���Ͻ�Ԫ���±���0��col-1
			y--;
		else if (num > arr[x][y])
			x++;
		else
		{
			*py = y;
			*px = x;
			return 1;//���Ҫ��ӡ������ò�Ҫ�ں�������printf����
		}
		//return x,y;����д��Ҳ�Ǵ���ģ����ص��Ƕ��ű���ʽ��ֵ��y��ֵ
	}
	return 0;
}
int main()
{
	//����Ҫ���Ӷ�С��O(n)���Բ��ܱ������飨���ϣ����¶����������жϣ��������²����ԣ�
	//���Ͻ�Ԫ����һ�������һ������С��
	//�����Ͻ�Ԫ��<k����ȥ��һ��Ԫ��
	//�����Ͻ�Ԫ��>k����ȥһ��
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int num = 7;
	//int ret = FindNum1(arr,num,3,3);
	//�÷����Ͳ�������Ԫ���±�
	int x = 3;
	int y = 3;
	int ret = FindNum2(arr, num, &x,&y);//Ҫ����ַ����ֱ�Ӵ�x,y(�βθı䲻Ӱ��ʵ�Σ�
	if (ret == 1)
		printf("�ҵ��ˣ��±��ǣ�%d,%d\n",x,y);
	else
		printf("Ԫ�ز�����\n");
	return 0;
}