#include <bits/stdc++.h>

template <typename T>
void mergesort(std::vector<T> &arr, std::vector<T> &aux, int left, int right)
{
    if (left == right) return;
    int medium = (left + right) / 2;
    mergesort(arr, aux, left, medium);
    mergesort(arr, aux, medium + 1, right);
    int i = left, j = medium + 1, k = left;
    while (i <= medium && j <= right) {
        if (arr[i] > arr[j]) {
            aux[k++] = arr[j++];
        }
        else {
            aux[k++] = arr[i++];
        }
    }
    while (i <= medium) {
        aux[k++] = arr[i++];
    }
    for (i = left; i < k; ++i) {
        arr[i] = aux[i];
    }
}

int main()
{
    std::vector<int> v = {5, 2, 3, -1, 4};
    std::vector<int> aux (v.size());

    mergesort(v, aux, 0, v.size()-1);

    for (auto i : v) {
        std::cout << i << '\t';
    }
    std::cout << std::endl;

    return 0;
}
