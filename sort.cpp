#include<iostream>
using namespace std;


void SelectionSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minInd = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[minInd])
                minInd = j;
        }

        swap(arr[i], arr[minInd]);
    }

    cout<<"\nThe sorted array using Selection sort: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void InsertionSort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int key = arr[i];
        while(j>=0 && key<arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }

    
    cout<<"\nThe sorted array using Insertion sort: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}


void BubbleSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool swapped = false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }

        }
        if(!swapped)
            break;
    }
    
    cout<<"\nThe sorted array using Bubble sort: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    

}


void Merge(int arr[], int low, int mid, int high)
{
    int temp[high-low+1];
    int left = low;
    int right = mid+1;
    int k=0;
    while(left<=mid && right<=high)
    {
        if(arr[left] <= arr[right])
        {
            temp[k] = arr[left];
            k++;
            left++; 
        }

        else
        {
            temp[k] = arr[right];
            k++;
            right++;
        }
    }

    while(left <= mid)
    {
        temp[k] = arr[left];
        left++;
        k++;
    }

    while(right <= high)
    {
        temp[k] = arr[right];
        right++;
        k++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i] = temp[i-low];
    }
}
void MergeSort(int arr[], int low, int high)
{
    if(low >= high)
        return;
    int mid = low + (high-low)/2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid+1, high);
    Merge(arr, low, mid, high);
}

int main()
{
    int n;
    cout<<"\nEnter the size of array:";
    cin>>n;
    int *arr = new int[n];

    int *SelectionArr = new int[n];
    int *InsertionArr  = new int[n];
    int *BubbleArr = new int[n];
    int *MergeArr = new int [n];
    cout<<"\nEnter the array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        SelectionArr[i] = arr[i];
        InsertionArr[i] = arr[i];
        BubbleArr[i] = arr[i];
        MergeArr[i] = arr[i];
    }

    SelectionSort(SelectionArr, n);
    
    InsertionSort(InsertionArr, n);

    BubbleSort(BubbleArr, n);
    int low = 0;
    int high = n-1;
    MergeSort(MergeArr, low, high);

    cout<<"\nThe sorted array using Merge sort: ";
    for(int i=0;i<n;i++)
    {
        cout<<MergeArr[i]<<" ";
    }

    delete[] arr;
    delete[] SelectionArr;
    delete[] InsertionArr;
    delete[] BubbleArr;
    delete[] MergeArr;
}