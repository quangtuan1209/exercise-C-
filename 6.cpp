#include<iostream>

using namespace std;

const int maxN = 8; // Kích thước bàn cờ
int countSolutions = 0; // Biến để lưu tổng số cách xếp
int queensToPlace; // Số hậu cần đặt

// Kiểm tra xem có thể đặt hậu vào ô (row, col) hay không
bool canPlace(int board[maxN][maxN], int row, int col) {
    // Kiểm tra cùng cột
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Kiểm tra đường chéo trái trên
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Kiểm tra đường chéo phải trên
    for (int i = row, j = col; i >= 0 && j < maxN; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

// In ra vị trí của quân hậu
void printQueenPosition(int row, int col) {
    cout << "Q" << row + 1 << " (" << row << ", " << col << ") ";
}

// Xây dựng chương trình đặt hậu bằng phương pháp quay lui
void solveNQueens(int board[maxN][maxN], int row, int queensPlaced) {
    if (queensPlaced == queensToPlace) {
        // Nếu đã đặt được số lượng hậu yêu cầu, in ra vị trí của từng quân hậu
        for (int i = 0; i < maxN; i++) {
            for (int j = 0; j < maxN; j++) {
                if (board[i][j] == 1) {
                    printQueenPosition(i, j);
                }
            }
        }
        cout << endl;
        countSolutions++;
        return;
    }

    for (int col = 0; col < maxN; col++) {
        if (canPlace(board, row, col)) {
            // Đặt hậu vào ô (row, col) nếu có thể
            board[row][col] = 1;

            // Tiếp tục đặt hậu cho hàng tiếp theo
            solveNQueens(board, row + 1, queensPlaced + 1);

            // Quay lui nếu không tìm được cách đặt hậu
            board[row][col] = 0;
        }
    }
}

int main() {
    int board[maxN][maxN] = {0}; // Khởi tạo bàn cờ

    cout << "Nhap so luong hau can dat (tu 1 den " << maxN << "): ";
    cin >> queensToPlace;

    if (queensToPlace < 1 || queensToPlace > maxN) {
        cout << "So luong hau khong hop le." << endl;
        return 1;
    }

    cout << "Cac vi tri cua cac hau la: " << endl;
    solveNQueens(board, 0, 0);

    cout << "Tong so cach xep " << queensToPlace << " hau tren ban co " << maxN << "x" << maxN << " la: ";
    cout << countSolutions << endl;

    return 0;
}
