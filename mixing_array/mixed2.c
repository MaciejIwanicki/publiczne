#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define ARRAY_SIZE 997

int mixed_function(int key)
{
    double help = key % 10;
    return ( ( key % 1000 ) +  pow(2, help) + 1  % 997 );
}

int second_mixed_function(int key)
{
	return ((3 * key) % 19 +1);
}

void init_array(int* mixedArray)
{
//	memset(mixedArray, 0, ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++)
            mixedArray[i] = 0;
}
 
void insert_element(int* mixedArray, int key)
{
    int calculatedIndex = mixed_function(key);
    if ( mixedArray[calculatedIndex] > 0 )
    {
            calculatedIndex++;
            while ( mixedArray[calculatedIndex] > 0 || calculatedIndex < ARRAY_SIZE )
                calculatedIndex++;
    }
    else
		mixedArray[calculatedIndex] = key;
       
}
 
void insert_many_element(int* mixedArray, int numberElements)
{
    for (int i = 0; i < numberElements; i++)
    {
        int numForInsert = 20000 + rand() % 40000;
        insert_element(mixedArray, numForInsert);
    }
}
 
void remove_element(int* mixedArray, int key)
{
    if (!mixedArray)
    {
        printf("Array is empty !!! \n");
        return;
    }
        int calculatedIndex = mixed_function(key);
    while (mixedArray[calculatedIndex] != key)
    {
        calculatedIndex++;
        if (calculatedIndex > ARRAY_SIZE)
        {
            printf("In array given number was not found \n");
                return;
        }
    }
        mixedArray[calculatedIndex] = -1;
}
 
void found_element(int* mixedArray, int key)
{
    if (!mixedArray)
    {
        printf("Array is empty !!! \n");
        return;
    }
        int calculatedIndex = mixed_function(key);
    while (mixedArray[calculatedIndex] != key)
    {
        calculatedIndex++;
        if (calculatedIndex > ARRAY_SIZE)
        {
            printf("In array given number was not found \n");
                return;
        }
    }
        printf("I found %d in Array ! ! ! \n",key);
}
 
void print_in_range(int const * mixedArray, int startPoint, int endPoint)
{
    if (!mixedArray)
    {
        printf("Array is empty !!! \n");
        return;
    }
    printf("------------------>Start print in range<------------------\n");
        for (int i = startPoint; i <= endPoint; i++)
    {
            printf("%d \n",mixedArray[i]);
    }
    printf("------------------>Stop print in range<------------------\n");
} 
 
int main(int argc, char* argv[])
{
    int x,k1,k2,k3,k4;
     
        FILE* fp = fopen("inlab06.txt", "r");
    if (fp == NULL)
        {
        printf("I couldn't  open given file \n");
        return -1;
    }
    fscanf (fp, "%d %d %d %d %d", &x, &k1, &k2, &k3, &k4);
    clock_t begin, end;
    double time_spent;
    begin = clock();
    int mixedArray[ARRAY_SIZE];
    init_array(mixedArray);
    //memset(mixedArray, 0, ARRAY_SIZE);
    remove_element(mixedArray, k1);
    insert_element(mixedArray, k1);
    print_in_range(mixedArray, 0, 100);
    insert_many_element(mixedArray, x);
    insert_element(mixedArray, k2);
    insert_element(mixedArray, k3);
    insert_element(mixedArray, k4);
    print_in_range(mixedArray, 0, 100);
    print_in_range(mixedArray, 500, 600);
    remove_element(mixedArray, k3);
    remove_element(mixedArray, k4);
    print_in_range(mixedArray, 0, 100);
    print_in_range(mixedArray, 500, 600);
    print_in_range(mixedArray, 0, 100);
    end = clock();
 
    //time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //    printf("Time spent: %lf \n",time_spent);
    fclose(fp); 
    return 0;
}
