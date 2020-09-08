#include<stdio.h>
#define MAX 50
int arr[MAX], even[MAX], odd[MAX];
int evenf(int x, int a)
{
	if (a % 2 == 0)
		even[x] = a;

	return even[x];
}//Function of putting even numbers in even number array
void insertion_s(int *x, int n)
{
	int tmp, p, q;
	for (p = 1; p < n; p++)
	{
		tmp = x[p];
		q = p - 1;
		while (tmp < x[q] && q >= 0)
		{
			x[q + 1] = x[q];
			q--;
		}
		x[q + 1] = tmp;
	}
}
int main(void)
{
	int num, i, j, k = 0, temp = 0, min = 0;
	printf("How many numbers? : ");
	scanf("%d", &num);
	printf("\nEnter numbers : \n");
	for (i = 0; i < num; i++)
	{
		printf("[%d] : ", i + 1);
		scanf("%d", &arr[i]);
	}printf("\n");

	printf("Original array is : \n");
	for (i = 0; i < num; i++)
		printf("%5d", arr[i]);
	printf("\n");

	for (i = 0; i < num; i++)
	{
		if (arr[i] % 2 == 0)
		{
			k++;
		}
	}
	for (i = 0; i < num; i++)//Sorting numbers by even and odd
	{
		evenf(i, arr[min + i]);
		while (arr[min + i] % 2 != 0)
		{
			odd[min] = arr[min + i];
			min++;
			evenf(i, arr[min + i]);
		}
	}
	insertion_s(even, k);
	insertion_s(odd, num - k);
	/*Final sorting*/
	int a = 0, b = 0, c = 0;
	while ((a < num-k) && (b<k))
	{
		if (odd[a] < even[b])
		{
			arr[c] = odd[a];
			a++;
			c++;
		}
		else
		{
			arr[c] = even[b];
			b++;
			c++;
		}
	}
	while (a < num-k)
	{
		arr[c] = odd[a];
		a++;
		c++;
	}
	while (b<k)
	{
		arr[c] = even[b];
		b++;
		c++;
	}
	printf("Sorted array is : \n");
	for (i = 0; i < num; i++)
		printf("%5d", arr[i]);
	printf("\n");
}