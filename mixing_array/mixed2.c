#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef int bool;

#define ARRAY_SIZE 997
#define true 1
#define false 0
int mixedArray[ARRAY_SIZE];


int mixed_function(int key)
{
    double help = key % 10;
    return ( ( key % 1000 ) +  pow(2, help) + 1  % 997 );
}

int second_mixed_function(int key)
{
	return ((3 * key) % 19 +1);
}

void init_array(void)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
            mixedArray[i] = 0;
}
 
bool insert_element(int key)
{
    int calculatedIndex = mixed_function(key);
    if (mixedArray[calculatedIndex] == key)
	    return false;
    if ( mixedArray[calculatedIndex] > 0 )
    {
            calculatedIndex++;
            while ( mixedArray[calculatedIndex] > 0 || calculatedIndex < ARRAY_SIZE )
                calculatedIndex++;
    }
    else
    {
		mixedArray[calculatedIndex] = key;
    		return true;		
    }  
}
 
bool second_insert_element(int key)
{
    int calculatedIndex = second_mixed_function(key);
    if (mixedArray[calculatedIndex] == key)
	    return false;
    if ( mixedArray[calculatedIndex] > 0 )
    {
            calculatedIndex++;
            while ( mixedArray[calculatedIndex] > 0 || calculatedIndex < ARRAY_SIZE )
                calculatedIndex++;
    }
    else
    {
		bool testVar = insert_element(key);
    		return testVar;		
    }  
}

void insert_many_element(int numberElements)
{
    bool checkVar = false;
    int i = 0;
    while ( i < numberElements )
    {
        int numForInsert = 20000 + rand() % 40000;
        checkVar = insert_element(numForInsert);
	if (checkVar == true)
		i++;
    }
}

void second_insert_many(int numberElements )
{
    bool checkVar = false;
    int i = 0;
    while ( i < numberElements )
    {
        int numForInsert = 20000 + rand() % 40000;
        checkVar = second_insert_element(numForInsert);
	if (checkVar == true)
		i++;
    }
}

void remove_element(int key)
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
 
void second_remove_element(int key)
{
    if (!mixedArray)
    {
        printf("Array is empty !!! \n");
        return;
    }
        int calculatedIndex = second_mixed_function(key);
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

void found_element(int key)
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

void second_found_element(int key)
{
    if (!mixedArray)
    {
        printf("Array is empty !!! \n");
        return;
    }
        int calculatedIndex = second_mixed_function(key);
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
void print_in_range(int startPoint, int endPoint)
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
    init_array();
    remove_element(k1);
    insert_element(k1);
    print_in_range(0, 100);
    insert_many_element(x);
    insert_element(k2);
    insert_element(k3);
    insert_element(k4);
    print_in_range(0, 100);
    print_in_range(500, 600);
    remove_element(k3);
    remove_element(k4);
    print_in_range(0, 100);
    print_in_range(500, 600);
    print_in_range(0, 100);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;    
    printf("Time spent: %lf \n",time_spent);

    printf("Mieszanie podwojne \n");
    begin = clock();
    init_array();
    second_remove_element(k1);
    second_insert_element(k1);
    print_in_range(0, 100);
    second_insert_many(x);
    print_in_range(0, 100);
    second_insert_element(k2);
    second_insert_element(k3);
    second_insert_element(k4);
    print_in_range(0, 100);
    print_in_range(500, 600);
    second_remove_element(k3);
    second_remove_element(k4);
    print_in_range(0, 100);
    print_in_range(500, 600);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Time spent: %lf \n",time_spent);

    fclose(fp); 
    return 0;
}
