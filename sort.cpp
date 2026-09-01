#include<iostream>
using namespace std;


void SelectionSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int minInd = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minInd])
                minInd = j;
        }

        swap(arr[i], arr[minInd]);
    }

    cout << "\nThe sorted array using Selection sort: ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}


void InsertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = arr[i];

        while(j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    cout << "\nThe sorted array using Insertion sort: ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}


void BubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }

    cout << "\nThe sorted array using Bubble sort: ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}


void Merge(int arr[], int low, int mid, int high)
{
    int temp[high - low + 1];

    int left = low;
    int right = mid + 1;
    int k = 0;

    while(left <= mid && right <= high)
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

    for(int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}


void MergeSort(int arr[], int low, int high)
{
    if(low >= high)
        return;

    int mid = low + (high - low) / 2;

    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);

    Merge(arr, low, mid, high);
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[low];

    int i = low;
    int j = high;

    while(i < j)
    {
        while(arr[i] <= pivot && i <= high - 1)
            i++;

        while(arr[j] > pivot && j >= low + 1)
            j--;

        if(i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);

    return j;
}


void QuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int Pindex = partition(arr, low, high);

        QuickSort(arr, low, Pindex - 1);
        QuickSort(arr, Pindex + 1, high);
    }
}


int main()
{
    int n;

    cout << "\nEnter the size of array: ";
    cin >> n;

    int *arr = new int[n];
    int *SelectionArr = new int[n];
    int *InsertionArr = new int[n];
    int *BubbleArr = new int[n];
    int *MergeArr = new int[n];
    int *QuickArr = new int[n];

    cout << "\nEnter the array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];

        SelectionArr[i] = arr[i];
        InsertionArr[i] = arr[i];
        BubbleArr[i] = arr[i];
        MergeArr[i] = arr[i];
        QuickArr[i] = arr[i];
    }

    int low = 0;
    int high = n - 1;

    QuickSort(QuickArr, low, high);

    cout << "\nThe sorted array using Quick sort: ";

    for(int i = 0; i < n; i++)
    {
        cout << QuickArr[i] << " ";
    }

    delete[] arr;
    delete[] SelectionArr;
    delete[] InsertionArr;
    delete[] BubbleArr;
    delete[] MergeArr;
    delete[] QuickArr;

    return 0;
}