#include <iostream>
#include <vector>
#include <map>

using namespace std;

void greedyJobScheduling(vector<struct Job>&);
void activitySelection(vector<struct Activity>&);
void huffmanCoding(map<char,int>&);

int main() {

    vector<Job> jobs = {
        {1,15}, {2,8}, {3,3}, {4,10}
    };
    greedyJobScheduling(jobs);
    cout << "------------------\n";

    vector<Activity> activities = {
        {1,1,4}, {2,3,5}, {3,0,6}, {4,5,7},
        {5,3,8}, {6,5,9}, {7,6,10}, {8,8,11},
        {9,8,12}, {10,2,13}, {11,12,14}
    };
    activitySelection(activities);
    cout << "------------------\n";

    map<char,int> freq = {
        {'a',5}, {'b',9}, {'c',12}, {'d',13}, {'e',16}, {'f',45}
    };
    huffmanCoding(freq);

    return 0;
}
