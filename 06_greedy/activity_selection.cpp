#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int id;
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare);

    cout << "Secilen aktiviteler: ";

    int prev = 0;
    cout << "a" << activities[prev].id << " ";

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= activities[prev].finish) {
            cout << "a" << activities[i].id << " ";
            prev = i;
        }
    }
    cout << endl;
}
