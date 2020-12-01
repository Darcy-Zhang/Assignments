#include <stdio.h>

int main(void)
{
	unsigned int i, x, y;
	unsigned int m, n;	
	unsigned char a[10];
	unsigned char temp;
	unsigned int GB[38] = {'��','��','��','��','��','��','��','��','��',
	'ԥ','��','��','��','��','��','��','��','��','��','��',
	'³','��','��','��','��','��','��','��','��','��','��',
	'��','ѧ','��','��','��','ʹ','��'};
	unsigned int UTF[38] = {0xE79A96, 0xE4BAAC, 0xE997BD, 0xE79498, 0xE7B2A4,
	0xE6A182, 0xE8B4B5, 0xE790BC, 0xE58680, 0xE8B1AB, 0xE9BB91,
	0xE98482, 0xE6B998, 0xE59089, 0xE88B8F, 0xE8B5A3, 0xE8BEBD,
	0xE89299, 0xE5AE81, 0xE99D92, 0xE9B281, 0xE6998B, 0xE99995,
	0xE6B2AA, 0xE5B79D, 0xE6B4A5, 0xE8978F, 0xE696B0, 0xE4BA91,
	0xE6B599, 0xE6B89D, 0xE68C82, 0xE5ADA6, 0xE8ADA6, 0xE6B8AF,
	0xE6BEB3, 0xE4BDBF, 0xE9A286};
	
	printf("Please enter the license plate number and press Enter to end: ");
		
	for (; (temp = getchar()) != '\n';)//ѭ����ȡ��Ļ�ϵ��ַ����ûس�ֹͣ 
	{
		if (temp != ' ')//���Կո� 
		{
			a[i] = temp;//���ַ��ŵ������� 
			i++;
		}
	}
	
	for (x = 0; x < i; x++)
	{
		if (a[x] < 128)//ͨ���ж��ַ������Ƿ�С��128���ж����ĺ�ASCII�� 
		{
			if (97 <= a[x] && a[x] <= 122)//˳��д�ģ�Ŀ��������Сд��ĸ�Ͱ���ת��Ϊ��д 
			{
				a[x] = a[x] - 32;
			}
			
			printf("%c", a[x]);//��ӡ���� 
		}
		else
		{
			m = (int)a[x];//�ѱ���ת��Ϊ���ν������㣬��Ϊ��֮ǰֱ������������ˣ����Զ����˸�ֵ��һ�� 
			n = (int)a[x+1];
			
			for (y = 0; y < 38; y++)
			{
				if (((m * 256) + n) == GB[y])//��������ַ��ı�����������еĺ��ֱ��루�Ƚ���������Ϊ����ռ�����ֽڣ� 
				{
					printf(" %x ", UTF[y]);//��ӡ��Ӧ���ַ� 
					y = y + 38;//����ѭ������ʵ��ûʲô���� 
				}
			}
			
			x++;//��Ϊһ�����ֵ��������ַ������Ծ�һ���������� 
		}
	}
			
	return 0;
}
