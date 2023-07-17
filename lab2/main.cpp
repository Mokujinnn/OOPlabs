#include <iostream>

int **createArray2d(int n)
{
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }

    return arr;
}

void deleteArray2d(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

void printArray2d(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void deleteArray(int *arr)
{
    delete [] arr;
}

int *createArrayA(int **arr, int n)
{
    int *d = new int[n * n];
    int count = 0;

    for (int k = 0; k < n * n - 1; k++)
    {
        int i, j;
        if(k < n)
        {
            i = 0;
            j = n - k - 1;
        }
        else
        {
            i = k - n + 1;
            j = 0;
        }

        while(i >= 0 && i < n && j >= 0 && j < n)
        {
            d[count] = arr[i][j];

            i++;
            j++;
            count++;
        }
    }

    return d;
}

int *createArrayB(int **arr, int n)
{
    int *d = new int[n * n];
    int count = 0;

    for (int k = 0; k < n * n - 1; k++)
    {
        int i, j;
        if(k < n)
        {
            i = 0;
            j = k;
        }
        else
        {
            i = k - n + 1;
            j = n - 1;
        }

        while(i >= 0 && i < n && j >= 0 && j < n)
        {
            d[count] = arr[i][j];

            i++;
            j--;
            count++;
        }
    }

    return d;
}

int* createArrayC(int **arr, int n)
{
    int *d = new int[n*n];
    int k = 0;
    int shift;
    int i;
    int j;
    if (n % 2 == 0)
    {
        shift = n/2 - 1;
        i = n/2;
        j = n/2;
    }
    else
    {
        shift = n/2;
        i = n/2;
        j = n/2;
    }

    while (k < n * n)
    {
        d[k] = arr[i][j];
        if (i == n - shift - 1 && j > shift)
            j--;
        else if (j == shift && i > shift)
            i--;
        else if (i == shift && j < n - shift - 1)
            j++;
        else
            i++;

        if ((i == shift + 1) && (j == shift) && (shift != 0))
        {
            shift--;
        }

        k++;
    }

    return d;
}

int* createArrayD(int **arr, int n)
{
    int *d = new int[n*n];
    int shift = 0;
    
    int k = 0;
    int i = 0;
    int j = 0;

    while (k < n * n)
    {
        d[k] = arr[i][j];
        if (i == shift && j < n - shift - 1)
            j++;
        else if (j == n - shift - 1 && i < n - shift - 1)
            i++;
        else if (i == n - shift - 1 && j > shift)
            j--;
        else
            i--;

        if ((i == shift + 1) && (j == shift) && (shift != n - shift - 1))
        {
            shift++;
        }

        k++;
    }

    return d;
}

int main()
{
    int n = 5;
    int **arr = createArray2d(n);
    printArray2d(arr, n);

    std::cout << '\n';
    int *d = createArrayD(arr, n);
    printArray(d, n*n);

    deleteArray2d(arr, n);
    return 0;
}