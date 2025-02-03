#include <iostream>
#include <climits> // Để dùng INT_MIN
using namespace std;

// Hàm tìm dãy con liên tiếp có tổng lớn nhất (sử dụng chia để trị)
int maxSubArraySum(int arr[], int low, int high) {
    // Trường hợp cơ bản: chỉ có một phần tử
    if (low == high)
        return arr[low];

    // Tìm chỉ số giữa
    int mid = (low + high) / 2;

    // Tìm dãy con liên tiếp có tổng lớn nhất trong phần đầu tiên (từ low đến mid)
    int leftMax = INT_MIN, sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftMax)
            leftMax = sum;
    }

    // Tìm dãy con liên tiếp có tổng lớn nhất trong phần thứ hai (từ mid+1 đến high)
    int rightMax = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightMax)
            rightMax = sum;
    }

    // Tổng của dãy con cắt qua giữa
    int crossMax = leftMax + rightMax;

    // Trả về giá trị lớn nhất trong ba trường hợp
    return max(crossMax, max(maxSubArraySum(arr, low, mid), maxSubArraySum(arr, mid + 1, high)));
}

int main() {
    // Mảng đầu vào
    int arr[] = {6,-2,-3,1,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Gọi hàm tìm tổng lớn nhất của dãy con liên tiếp
    int maxSum = maxSubArraySum(arr, 0, n - 1);

    // In kết quả
    cout << "Tong lon nhat cua day con lien tiep: " << maxSum << endl;
    return 0;
}
