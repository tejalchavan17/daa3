#include<stdio.h>
int max, min,i,n,m[100],pass=1;
void maxmin(int low, int high);
void main ()
{
	printf ("\nEnter the total number of numbers:\n");
	scanf ("%d",&n);
	printf ("Enter the numbers:\n");
	for (i=1;i<=n;i++)
		scanf ("%d",&m[i]);
	max=99999;
	min=99999;
	maxmin(1, n);
	printf("\n Final array\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",m[i]);
	}
	printf ("\nMinimum element in an array : %d\n", min);
	printf ("Maximum element in an array : %d\n", max);
}
void maxmin(int low, int high)
{
	int t,t1,t2,mid,maxt,mint;
	if(low==high)
	{
		max=min=m[low];
	}
	else
	{
		if(high-1==low)
		{
			if(m[low]<m[high])
			{
				max=m[high];
				min=m[low];
			}
			else
			{
				max=m[low];
				min=m[high];
			}
		}
		else
		{
			mid=(low+high)/2;
			maxmin(low, mid);
			printf("\n pass%d\n",pass);
			for(i=low;i<=mid;i++)
			{
				printf("%d\t",m[i]);
			}
			printf ("\nMinimum element in an array : %d", min);
			printf ("\nMaximum element in an array : %d", max);
			pass++; 
			maxt=max;
			mint=min;
			maxmin(mid+1, high);
			printf("\n pass%d\n",pass);
			for(i=mid+1;i<=high;i++)
			{
				printf("%d\t",m[i]);
			}
			printf ("\nMinimum element in an array : %d", min);
			printf ("\nMaximum element in an array : %d", max);
			pass++;
			if(max<maxt)
				max=maxt;
			if(min>mint)
				min=mint;
		}
	}
}


/*tejal@ubuntu:~/Desktop/daa$ gcc maxmin.c
tejal@ubuntu:~/Desktop/daa$ ./a.out

Enter the total number of numbers:
8
Enter the numbers:
9 7 6 8 4 5 2 3

 pass1
9	7	
Minimum element in an array : 7
Maximum element in an array : 9
 pass2
6	8	
Minimum element in an array : 6
Maximum element in an array : 8
 pass3
9	7	6	8	
Minimum element in an array : 6
Maximum element in an array : 9
 pass4
4	5	
Minimum element in an array : 4
Maximum element in an array : 5
 pass5
2	3	
Minimum element in an array : 2
Maximum element in an array : 3
 pass6
4	5	2	3	
Minimum element in an array : 2
Maximum element in an array : 5
 Final array
9	7	6	8	4	5	2	3	
Minimum element in an array : 2
Maximum element in an array : 9
tejal@ubuntu:~/Desktop/daa$ 
*/
