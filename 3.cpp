#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Activity
{
    int id;
    int start;
    int finish;
};

bool compare(Activity a, Activity b)
{
    return (a.finish < b.finish);
}

void scheduleActivities(vector<Activity> &activities)
{
    sort(activities.begin(), activities.end(), compare);

    cout << "Thu tu hoat dong: ";
    cout << activities[0].id << " ";

    int lastFinishTime = activities[0].finish;

    for (int i = 1; i < activities.size(); i++)
    {
        if (activities[i].start >= lastFinishTime)
        {
            cout << activities[i].id << " ";
            lastFinishTime = activities[i].finish;
        }
    }
    cout << endl;
}

int main()
{
    // Input the number of activities
    int numActivities;
    cout << "Nhap so luong hoat dong: ";
    cin >> numActivities;

    vector<Activity> activities;
    cout << "Nhap thoi diem bat dau va ket thuc cho tung hoat dong:" << endl;
    for (int i = 0; i < numActivities; i++)
    {
        int start, finish;
        cout << "Hoat dong " << i + 1 << ": ";
        cin >> start >> finish;
        activities.push_back({i + 1, start, finish});
    }

    scheduleActivities(activities);

    return 0;
}

// Enter the number of activities: 9
// Enter the start and finish times for each activity:
// Activity 1: 1 3
// Activity 2: 3 4
// Activity 3: 4 6
// Activity 4: 2 8
// Activity 5: 6 10
// Activity 6: 4 13
// Activity 7: 10 14
// Activity 8: 12 15
// Activity 9: 11 16

// Enter the number of activities: 6
// Enter the start and finish times for each activity:
// Activity 1: 1 4
// Activity 2: 3 5
// Activity 3: 0 6
// Activity 4: 5 7
// Activity 5: 8 9
// Activity 6: 5 9

// Enter the number of activities: 5
// Enter the start and finish times for each activity:
// Activity 1: 1 2
// Activity 2: 2 3
// Activity 3: 3 4
// Activity 4: 4 5
// Activity 5: 5 6
