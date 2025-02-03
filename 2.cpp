#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    char name;
    int weight;
    int value;
    double ratio; // Tỷ lệ giá trị/trọng lượng
};

bool compareItems(const Item &a, const Item &b)
{
    return a.ratio > b.ratio;
}

void fractionalKnapsack(int capacity, vector<Item> &items)
{
    // Tính tỷ lệ giá trị/trọng lượng cho từng mặt hàng
    for (Item &item : items)
    {
        item.ratio = static_cast<double>(item.value) / item.weight;
    }

    // Sắp xếp mặt hàng theo tỷ lệ giảm dần
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    cout << "Chon phan phoi cac mat hang nhu sau:" << endl;
    for (const Item &item : items)
    {
        if (currentWeight + item.weight <= capacity)
        {
            // Chọn toàn bộ mặt hàng
            cout << "Mat hang " << item.name << ": 100%" << endl;
            currentWeight += item.weight;
            totalValue += item.value;
        }
        else
        {
            // Chọn một phần của mặt hàng
            double fraction = static_cast<double>(capacity - currentWeight) / item.weight;
            cout << "Mat hang " << item.name << ": " << (fraction * 100) << "%" << endl;
            totalValue += fraction * item.value;
            break; // Túi đã đầy
        }
    }

    cout << "Tong gia tri trong tui: " << totalValue << endl;
}

int main()
{
    int capacity;
    cout << "Nhap dung tich tui: ";
    cin >> capacity;

    int numItems;
    cout << "Nhap so luong mat hang: ";
    cin >> numItems;

    vector<Item> items(numItems);
    for (int i = 0; i < numItems; ++i)
    {
        cout << "Nhap thong tin cho mat hang " << char('A' + i) << ":" << endl;
        items[i].name = char('A' + i);
        cout << " - Trong luong: ";
        cin >> items[i].weight;
        cout << " - Gia tri: ";
        cin >> items[i].value;
    }

    fractionalKnapsack(capacity, items);

    return 0;
}



