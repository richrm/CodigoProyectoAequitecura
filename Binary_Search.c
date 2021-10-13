
#include<stdio.h>
int arr []= {2,3,4,10,20,30,40,50,70,100};
// A recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
int division (int dividendo, int divisor){
    int cont=0;
    dividendo= dividendo - divisor;
while (dividendo >= 0){
      cont++;
      dividendo = dividendo - divisor;
}
return cont;
}

int binarySearch(int *arr, int l, int r, int x)
{
   if (r >= l)
   {
        int mid =  r - l;
        mid = l + division(mid,2);
        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid;
  
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, r, x);
   }
  
   // We reach here when element is not present in array
   return -1;
}
  
int main(void)
{
   int n = 10;
   int x = 30;
   int result = binarySearch(arr, 0, n-1, x);
   printf("result %d", result);
   return 0;
}