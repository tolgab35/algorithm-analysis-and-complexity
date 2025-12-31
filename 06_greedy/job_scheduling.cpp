#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int time;
};

bool compare(Job a, Job b) {
    return a.time < b.time;
}

void greedyJobScheduling(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);

    int currentTime = 0;
    int totalCompletionTime = 0;

    cout << "Job sirasi: ";
    for (auto job : jobs) {
        currentTime += job.time;
        totalCompletionTime += currentTime;
        cout << "J" << job.id << " ";
    }

    cout << endl;
    cout << "Ortalama tamamlama suresi: "
         << (double)totalCompletionTime / jobs.size() << endl;
}
