#include<stdio.h>
#include<stdlib.h>

// The Iterative approach
int factNumber( unsigned int count )
{
	int fact = 1;
	for(int i = 1; i <= count; i++)
		fact *= i;
	return fact;
}

// Recursive approach
int factNumberRecursive( unsigned int count )
{
	// Base case, we always need a stopping condition
	// Here, we stop when the number 1 is reached.
	if( count  == 1 )
		return 1;

	// This our recursive steps.
	// We break the problem down by subtracting - 1
	// The problem is smaller in temrs of having 1 less number
	// to multiply by.
	return count * factNumberRecursive(count-1);
}

int main( int argc, char ** argv )
{
	int count = 0;

	printf("Please input a number > 0\n");
	scanf("%d",&count);
	while(count >= 0 )
	{
		// Start the recursive function call
		int result = factNumberRecursive( count );
		//int result = factNumber( count );
		printf("The sum is %d\n", result );
		
		printf("Please input a number > 0\n");
		scanf("%d",&count);
	}
}
