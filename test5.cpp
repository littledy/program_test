#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

ostream& operator<<(ostream& os, vector<int> vec) {
    for (auto x : vec) {
        cout << x << " ";
    }
    cout << endl;
    return os;
}

int main() {
    int myints[] = {10, 20, 30, 30, 40, 30, 20, 10};
    vector<int> v(myints, myints+8);
    pair<vector<int>::iterator, vector<int>::iterator> bounds;

    sort(v.begin(), v.end());
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
    bounds = equal_range(v.begin(), v.end(), 20);
    cout << (bounds.first-v.begin()) << " " << (bounds.second-v.begin()) << endl;
    sort(v.begin(), v.end(), [](int i, int j){
        return i > j;
    });
    bounds = equal_range(v.begin(), v.end(), 20, [](int i, int j) {
        return i > j;
    });
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
    cout << (bounds.first-v.begin()) << " " << (bounds.second-v.begin()) << endl;

    int myintegers[] = {9, 7, 8, 6, 5, 1, 3, 4, 2};
    vector<int> vec(myintegers, myintegers+sizeof(myintegers)/sizeof(int));
    partial_sort(vec.begin(), vec.begin()+5, vec.end());
    cout << vec;

    typedef duration<int, ratio<60*60*24>> days_type;
    time_point<system_clock, days_type> today = time_point_cast<days_type>(system_clock::now());
    cout << today.time_since_epoch().count() << " days since epoch." << endl;

    return 0;
}