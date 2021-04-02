#include <iostream>

void selection_sort(int arr[], int n);

void selection_sort(int arr[], int n)
{
	int i, j, min = 0;

	for(i = 0; i < n; i++)
	{
	    min = i;
	    for(j = i + 1; j < n; j++)
            {
		if(arr[j] < arr[min])
		    min = j;
            }

	    int temp = arr[min];
	    arr[min] = arr[i];
	    arr[i] = temp;
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

	selection_sort(arr, n);

	std::cout << "Sorted Array : ";
	display(arr, n);

	return 0;
}
