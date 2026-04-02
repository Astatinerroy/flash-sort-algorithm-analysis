#include <iostream>
#include <vector>
using namespace std;

void flashSort(vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    if (n == 0) return;

    int m = 0.45 * n;
    vector<int> L(m, 0);

    int minVal = arr[0], maxVal = arr[0];
    int maxIndex = 0;

    // Find min and max
    for (int i = 1; i < n; i++) {
        comparisons++;
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
    }

    if (minVal == maxVal) return;

    // Classification
    for (int i = 0; i < n; i++) {
        int k = (m - 1) * (arr[i] - minVal) / (maxVal - minVal);
        L[k]++;
    }

    // Prefix sum
    for (int i = 1; i < m; i++) {
        L[i] += L[i - 1];
    }

    // Swap max element to first position
    swap(arr[maxIndex], arr[0]);
    swaps++;

    // Permutation
    int move = 0, j = 0, k = m - 1;

    while (move < n - 1) {
        while (j >= L[k]) {
            j++;
            k = (m - 1) * (arr[j] - minVal) / (maxVal - minVal);
            comparisons++;
        }

        int flash = arr[j];

        while (j != L[k]) {
            k = (m - 1) * (flash - minVal) / (maxVal - minVal);
            int temp = arr[L[k] - 1];
            arr[L[k] - 1] = flash;
            flash = temp;
            L[k]--;
            swaps++;
            move++;
        }
    }

    // Final Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    int comparisons = 0, swaps = 0;

    flashSort(arr, comparisons, swaps);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;

    return 0;
}
