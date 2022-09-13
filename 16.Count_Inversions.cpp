//Using Enhaced Merge Sort

//two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

#include<iostream>
using namespace std;

int countAndMerge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1], right[n2];

    for(int i = 0; i < n1; i++)
    {
       left[i] = arr[low + i];
    }

    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;
    int res = 0;
    while(i < n1 && j < n2)
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = right[j];
            k++;
            j++;
            res = res + (n1-i);
        }
    }

    while(i < n1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }

    while(j < n2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }

    return res;     
}

int countInv(int arr[], int low, int high)
{
    int res = 0;
    if(high > low)
    {
        int mid = low + (high-low)/2;
        res += countInv(arr, low, mid);
        res += countInv(arr, mid+1, high);
        res += countAndMerge(arr, low, mid, high);
    }


    return res;
}

int main()
{
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr)/sizeof(int);

    int ans = countInv(arr, 0, n-1);

    cout << "Number of inversions are : " << ans;

    return 0;
}
