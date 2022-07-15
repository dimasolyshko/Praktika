#include <iostream>
#include <cmath>
    using namespace std;
    void Create_Bulean_Of_A(int*, int);
    void Create_Bit_Mask(int*, int*, int*, int, int);
    void Show_Bit_Arr(int*, int);
    void Union(int*, int*, int*,int);
    void Intersection(int*, int*, int*, int);
    void Difference(int*, int*, int*, int);
    void Symmetrical_Difference(int*, int*, int*, int);
    void Addition(int*, int*, int*, int);
    void task(int*, int*, int*, int*, int);
    int main() {
        setlocale(LC_ALL, "ru");
        int A[6] = { 1,2,3,4,5,6 };
        Create_Bulean_Of_A(A, 6);
        int B[4] = { 5,6,7,8 };
        int C[5] = { 2,3,5,7,8};
        int U[11] = { 1,2,3,4,5,6,7,8,9,10,11 };
        int bit_A[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
        int bit_B[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
        int bit_C[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
        int bit_AC[] = { 0,0,0,0,0,0,0,0,0,0,0 };
        Create_Bit_Mask(U, A, bit_A, 11, 6);
        Create_Bit_Mask(U, B, bit_B, 11, 4);
        Create_Bit_Mask(U, C, bit_C, 11, 5);

        Show_Bit_Arr(bit_A, 11);
        Show_Bit_Arr(bit_B, 11);

        Union(bit_A, bit_B, U, 11);

        Intersection(bit_A, bit_B, U, 11);

        Difference(bit_A, bit_B, U, 11);

        Symmetrical_Difference(bit_A, bit_B, U, 11);

        Addition(bit_A, bit_B, U, 11);

        task(bit_A, bit_B, bit_C, U, 11);

        return 0;
    }
    void Create_Bulean_Of_A(int* A, int size)
    {
        for (int i = 0; i < pow(2, size); i++) {
            cout << "{ ";
            for (int j = 0; j < size; j++) {
                if (i & (1 << j))
                {
                    cout << A[j] << " ";
                }
            }
            cout << "}" << endl;
        }
        cout << endl << "Number of buleans: " << pow(2, size) << endl;
    }
    void Create_Bit_Mask(int* U, int* Arr, int* Bit_Arr, int sizeU, int size)
    {
        for (int i = 0; i < sizeU; i++) {
            for (int l = 0; l < size; l++) {
                if (U[i] == Arr[l]) {
                    Bit_Arr[i] = 1;
                }
            }
        }
    }
    void Show_Bit_Arr(int *Bit_Arr,int size)
    {
        for (int i = 0; i < size; i++) {
            cout << Bit_Arr[i] << "\t";
        }
        cout << endl;
    }
    void Union(int* bit_A, int* bit_B,int* U,int size)
    {
        cout << "объединение: \n";
        for (int i = 0; i < size; i++) {    
            if (bit_A[i] || bit_B[i]) {
                cout << U[i] << "\t";
            }
        }
        cout << endl;
    }
    void Intersection(int* bit_A, int* bit_B, int* U, int size)
    {
        cout << "пересечение: \n";
        for (int i = 0; i < size; i++) { 
            if (bit_A[i] && bit_B[i]) {
                cout << U[i] << "\t";
            }
        }
        cout << endl;
    }
    void Difference(int* bit_A, int* bit_B, int* U, int size)
    {
        cout << "разность: \n";
        for (int i = 0; i < size; i++) {          
            if (bit_A[i] && !bit_B[i]) {
                cout << U[i] << "\t";
            }
        }
        cout << endl;
    }
    void Symmetrical_Difference(int* bit_A, int* bit_B, int* U, int size)
    {
        cout << "Симметрическая разность: \n";
        for (int i = 0; i < 11; i++) {         
            if (bit_A[i] ^ bit_B[i]) {
                cout << U[i] << "\t";
            }
        }
        cout << endl;
    }
    void Addition(int* bit_A, int* bit_B, int* U, int size)
    {
        cout << "Дополнение: \n";
        for (int i = 0; i < 11; i++) {          
            if (!bit_A[i] && !bit_B[i]) {
                cout << U[i] << "\t";
            }
        }
        cout << endl;
    }
    void task(int* bit_A, int* bit_B, int* bit_C, int* U, int size)
    {
        cout << "Вычислить выражение (A/B)ПC: " << endl;
        int bit_AB[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
        for (int i = 0; i < 11; i++) {
            if (bit_A[i] && !bit_B[i]) {
                bit_AB[i] = 1;
            }
        }
        for (int i = 0; i < 11; i++) {
            if (bit_C[i] && bit_AB[i]) {
                cout << U[i] << "\t";
            }
        }
        cout << endl;
    }



