#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High);
//void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int ZeroElem(int** a, const int rowCount, const int colCount, int k);
void NomRowMaxSer(int** a, const int rowCount, const int colCount,int nomr);

int main()
{
    srand((unsigned)time(NULL));

    int Low = -17;
    int High = 15;

    int rowCount, colCount;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    //Input(a, rowCount, colCount);

    Print(a, rowCount, colCount);
   
    cout << "number of rows with zeros = " << ZeroElem(a, rowCount, colCount, 0) << endl;


    NomRowMaxSer(a, rowCount, colCount,0);
   



    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

//void Input(int** a, const int rowCount, const int colCount)
//{
//    for (int i = 0; i < rowCount; i++)
//    {
//        for (int j = 0; j < colCount; j++)
//        {
//            cout << "a[" << i << "][" << j << "] = ";
//            cin >> a[i][j];
//        }
//        cout << endl;
//    }
//}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int ZeroElem(int** a, const int rowCount, const int colCount, int k)
{
    
    for (int i = 0; i < rowCount; i++)
    {
        bool t = false;


        for (int j = 0; j < colCount; j++)
        {
            if (a[i][j] == 0)
                t = true;
        }
        if (t)
            k++;
    }
    return k;
}

void NomRowMaxSer(int** a, const int rowCount, const int colCount, int nomr)
{
    int maxk = 0;
    int sumel = 0;

    for (int i = 0; i < rowCount; i++)
    {
        
        for (int j = 0; j < colCount; j++)
        {
            
            for (int k = 0; k < colCount; k++)
            {
                if (a[i][j] == a[i][k])
                    sumel++;
            }

            if (sumel > maxk)
            {
                maxk = sumel;
                nomr = i;
            }

            sumel = 0;
             
        }
     
    }

    cout << "row namber with max series = " << nomr;
    
}