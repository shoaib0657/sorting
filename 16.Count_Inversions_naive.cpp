#include<iostream>
using namespace std;

int countInversions(int arr[], int n)
{

    int count = 0;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
            }
            
        }
    }

    return count;
}

int main() {

    int arr[] = {2, 4, 1, 3, 5};
    int count = countInversions(arr, 5);

    cout << "Count of inversions are = " << count << endl;

    return 0;
}