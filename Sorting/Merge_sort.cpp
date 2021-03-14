#include <iostream>

void merge_sort(int arr[], int l, int r);
void merge(int arr[], int l, int mid, int r);

void merge_sort(int arr[], int l, int r)
{
	int mid = 0;
	if(l < r)
	{
	    mid = (l + r)/2;
	    merge_sort(arr, l, mid);
	    merge_sort(arr, mid+1, r);
	    merge(arr, l, mid, r);
	}
}

void merge(int arr[], int l, int mid, int r)
{
	int n1 = mid - l + 1;
	int n2 = r - mid;

	int L[n1], R[n2];

	for(int i = 0; i < n1; i++)
	    L[i] = arr[l + i];

	for(int j = 0; j < n2; j++)
	    R[j] = arr[mid + 1 + j];

	int i = 0, j = 0;

	int k = l;

	while(i < n1 && j < n2)
	{
	    if(L[i] <= R[j])
	    {
	        arr[k] = L[i];
		i++;
	    }
	    else
	    {
	        arr[k] = R[j];
		j++;
	    }
	    k++;
	}

	while(i < n1)
	{
	    arr[k] = L[i];
	    i++;
	    k++;
	}

	while(j < n2)
	{
	    arr[k] = R[j];
	    j++;
	    k++;
	}
}

void display(int arr[], int n)
{
	
	for(int i = 0; i < n; i++)
	    std::cout << arr[i] << "  ";
	std::cout << "\n";

}

int main()
{
	int arr[50];
	int n;

	std::cout << "Enter no. of elements in Array : ";
	std::cin >> n ;
	std::cout << "\nEnter elements in Array." << std::endl;
	for(int i = 0; i < n; i++)
	    std::cin >> arr[i];

	display(arr, n);

	merge_sort(arr, 0, n-1);

	std::cout << "Sorted Array : ";
	display(arr, n);

	return 0;
}
