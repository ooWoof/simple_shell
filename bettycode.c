#include <stdio.h>

/**
 * main - Entry point
 * a programme that computes the average marks of a student
 * Create an array that stores the marks of 5 subjects
 * Compute the total marks by adding all the marks
 * Divide the total marks by the total number of subjects
 * Print the average marks
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	int sum = 0;
	int marks[5];

	for (i = 0; i < 5; i++)
	{
	printf("Enter marks ", i + 1);
	scanf("%d", &marks[i]);
	sum += marks[i];
	}
	printf("Sum is %d\n", sum);
	printf("Average marks is %d\n", sum / 5);

	return (0);
}
