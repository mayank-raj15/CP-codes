#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int mid, int r)
{
	int l1 = mid - l + 1, l2 = r - mid;
	int left[l1], right[l2];
	for (int i = 0; i < l1; i++)
		left[i] = a[l + i];
	for (int i = 0; i < l2; i++)
		right[i] = a[mid + 1 + i];

	int i = 0, j = 0, k = l;
	while (i < l1 && j < l2)
	{
		if (left[i] < right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < l1)
	{
		a[k] = left[i];
		i++, k++;
	}

	while (j < l2)
	{
		a[k] = right[j];
		j++, k++;
	}

}

void mergeSort(int a[], int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		mergeSort(a, l, mid);
		mergeSort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << "Before Sort:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
	mergeSort(a, 0, n - 1);
	cout << "After Sort:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}