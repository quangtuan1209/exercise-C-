#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Nhập số nguyên n (n < 100): ";
    cin >> n;

    // Khởi tạo bảng dp để lưu trữ số cách phân tích số i
    vector<int> dp(n + 1, 0);
    dp[0] = 1;  // Có một cách phân tích số 0

    // Duyệt từ 1 đến n và tính số cách phân tích từng số
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[j] += dp[j - i];
        }
    }

    // Kết quả là dp[n]
    cout << "Số cách phân tích số " << n << " thành tổng các số nguyên dương là: " << dp[n] << endl;

    return 0;
}
