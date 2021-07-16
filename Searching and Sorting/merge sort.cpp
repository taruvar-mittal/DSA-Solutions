class Solution
{
public:
    void merge(int arr[], int l, int m, int r)
    {
        int x = m - l + 1;
        int n = r - m;

        int *leftarr = new int[x];
        int *rightarr = new int[n];

        for (int i = 0; i < x; i++)
        {
            leftarr[i] = arr[l + i];
        }
        for (int i = 0; i < n; i++)
        {
            rightarr[i] = arr[m + 1 + i];
        }

        int i = 0, j = 0, k = l;

        while (i < x && j < n)
        {
            if (leftarr[i] < rightarr[j])
            {
                arr[k++] = leftarr[i++];
            }
            else
            {
                arr[k++] = rightarr[j++];
            }
        }

        while (i < x)
            arr[k++] = leftarr[i++];
        while (j < n)
            arr[k++] = rightarr[j++];
    }

public:
    void mergeSort(int arr[], int l, int r)
    {
        if (l < r)
        {
            int mid = l + (r - l) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }
};