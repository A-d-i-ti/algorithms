#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int start, end, weight;
};

// Compare jobs by end time
bool compare(Job a, Job b) {
    return a.end < b.end;
}

// Binary search to find the latest job that doesn't conflict
int latestNonConflict(vector<Job>& jobs, int i) {
    int low = 0, high = i - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (jobs[mid].end <= jobs[i].start) {
            if (jobs[mid + 1].end <= jobs[i].start)
                low = mid + 1;
            else
                return mid;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Main function to find the maximum weight of non-overlapping jobs
int weightedIntervalScheduling(vector<Job>& jobs) {
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), compare);

    vector<int> dp(n);
    dp[0] = jobs[0].weight;

    for (int i = 1; i < n; i++) {
        int incl = jobs[i].weight;
        int l = latestNonConflict(jobs, i);
        if (l != -1)
            incl += dp[l];

        dp[i] = max(incl, dp[i - 1]);
    }

    return dp[n - 1];
}

int main() {
    vector<Job> jobs = {
        {1, 3, 5},
        {2, 5, 6},
        {4, 6, 5},
        {6, 7, 4},
        {5, 8, 11},
        {7, 9, 2}
    };

    int maxWeight = weightedIntervalScheduling(jobs);
    cout << "Maximum weight of non-overlapping intervals: " << maxWeight << endl;

    return 0;
}
