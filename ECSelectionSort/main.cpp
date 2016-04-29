#include <iostream>
using namespace std;


class SelectionSort{
public:
    
    void print(int *arr){
        for (int i = 0; i < 8; i++){
            cout << *(arr + i) << ", ";
        }
        cout << endl;
    }

    int indexOfSmallest(int arr[], int size, int index){
        if (index == size - 1)
                return index;
        int smallestInNext = indexOfSmallest(arr, size, index+1);
        if (arr[smallestInNext] < arr[index])
            return smallestInNext;
        else
            return index;
    }
    
    int* sort(int arr[], int size, int index){
        if (index == size - 1){
            return arr;
        }
        int small = indexOfSmallest(arr, size, index);
        int temp = arr[index];
        arr[index] = arr[small];
        arr[small] = temp;
        arr = sort(arr, size, index + 1);
        return arr;
    }
};

int main(){
    SelectionSort s = SelectionSort();
    int arr[] = { 5, 6, 8, 2, 4, 10, 35, 1 };
    int *intptr = arr;
    intptr = s.sort(arr, 8, 0);
    
    s.print(intptr);
    
    system("pause");
    return 0;
    
}

