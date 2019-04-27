#include <iostream>
#include "LIST.H"

void swap(int &a, int &b){
int h = b;
b = a;
a = h;
}

void PreparePartition(int a[], int f, int l, int &p){
//pivot-element
int pivot = a[f];
p = f-1;
for(int i = f; i <= l; i++){
    if(a[i] <= pivot)
    {
        p++;
        swap(a[i], a[p]);
    }
}

//Pivot to the right place
swap(a[f], a[p]);
}

void QuickSort(int a[], int f, int l){
int part;

if(f<l){
    PreparePartition(a, f, l, part);
    QuickSort(a, f, part-1);
    QuickSort(a, part+1, l);
    }
}

int main(){

    int nmbrs[] = {4, 8, 6, 2, 10, 1 };
    QuickSort(nmbrs, 0, 5);
    for(int i = 0; i < 6; i++){
        printf("%d ", nmbrs[i]);
    }
    printf("\n");
    liste z(10);
    liste y(4, &z);
    liste x(3, &y);
    x.printValue();

return 0;
}
