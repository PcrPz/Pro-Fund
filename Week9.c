#include <stdio.h>
int w, h, l, sum = 0;
//ฟังกชันตัดส่วนที่เป็นเศษ
void remain(int x)
{
	if (x % 2 != 0)
		x = x - 1;
}
int main()
{
	printf("This program spilt bread\n");
	printf("Enter your size of bread :");
	scanf("%d %d %d", &w, &h, &l);

	while (w != 1 || h != 1 || l != 1)
	{
		//เปรียบเทียบขนาดอันใหญ่เพื่อตัดก่อน
		if (w >= h && w >= l)
		{
			remain(w);
			w = w / 2;
			sum++;
		}

		else if (h >= w && h >= l)
		{
			remain(h);
			h = h / 2;
			sum++;
		}

		else if (l >= w && l >= h)
		{
			remain(l);
			l = l / 2;
			sum++;
		}
	}
	printf("cut %d times.", sum);
}
