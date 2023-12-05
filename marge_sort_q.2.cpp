#include <iostream>
#include<vector>
using namespace std;
void merge(vector<int>&v, int low, int mid, int high)
{
	int len1 = mid - low + 1;
	int len2 = high - mid;

	int* first = new int[len1];
	int* second = new int[len2];

	int k = low;
	for (int i = 0; i < len1; i++) {
		first[i] = v[k++];
	}

	k = mid + 1;
	for (int i = 0; i < len2; i++) {
		second[i] = v[k++];
	}
	int i = 0, j = 0;
	k = low;
	while (i < len1 && j < len2) {
		if (first[i] <= second[j]) {
			v[k++] = first[i++];
		}
		else {
			v[k++] = second[j++];
		}
	}
	while (i < len1) {
		v[k++] = first[i++];
	}
	while (j < len2) {
		v[k++] = second[j++];
	}
}
int countReversePairs(vector<int>&v, int low, int mid, int high)
{
	int cnt = 0;
	int j = mid + 1;
	for (int i = low; i <= mid; i++) {
		while (i <= high && v[i] > 2 * v[j]) {
			j++;
		}
		cnt += (j - (mid + 1));
	}

	return cnt;
}

int mergeSort(vector<int>&v, int low, int high)
{
	int cnt = 0;
	int mid = low + (high - low) / 2;
	if (low >= high) {
		return cnt;
	}

	cnt += mergeSort(v, low, mid);


	cnt += mergeSort(v, mid + 1, high);
	cnt += countReversePairs(v, low, mid, high);
	merge(v, low, mid, high);

	return cnt;
}
int main(){
	int arr[] = { 3, 2, 4, 5, 1, 20 };
	int n = sizeof(arr) / sizeof(arr[0]);
    vector<int>v(arr,arr+n);
	cout << "Reverse pairs are: "
		<< mergeSort(v, 0, n - 1) << endl;
	return 0;
}
