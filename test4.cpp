#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct MyComparator {
    bool operator()(int x, int y) const {
        return abs(x) < abs(y);
    }
};

int main() {
    vector<int> vec{-5,2,-3,3,-1,6,-2,7};
    MyComparator comp;
    sort(vec.begin(), vec.end(), comp);
    cout << vec[3] << " " << vec[4] << endl;
    auto range = equal_range(vec.begin(), vec.end(), 3, comp);

    cout << "start: " << distance(vec.begin(), range.first) << endl;
    cout << "end: " << distance(vec.begin(), range.second) << endl;

    vector<int> vec1{1,2,3,4,5};
    vector<int> vec2(9);
    copy_backward(vec1.begin(), vec1.end(), vec2.end());
    for (auto& x : vec2) {
        cout << x << " ";
    }
    cout << endl;
    cout << typeid(int).hash_code() << endl;
    cout << typeid(string).name() << endl;

    cout << "Price: " << put_money(10.50L) << endl;

    vector<int> vect{1, 3, 5, 7};
    if (all_of(vect.begin(), vect.end(), [](int i){ return (i%2); })) {
        cout << "vect all odd" << endl;
    }
    if (any_of(vect.begin(), vect.end(), [](int i){ return (i%2); })) {
        cout << "one of vect is odd" << endl;
    }
    if (none_of(vect.begin(), vect.end(), [](int i){ return (i%2) == 0;})) {
        cout << "none of vec is even" << endl;
    }
    for_each(vect.begin(), vect.end(), [](int i){ cout << i << endl; });
    if (find(vect.begin(), vect.end(), 1) != vect.end()) {
        cout << "find 1 in vect" << endl;
    }
    if (find_if(vect.begin(), vect.end(), [](int i){ return (i%2); }) != vect.end()) {
        cout << "find odd in vect" << endl;
    }
    vector<int>::iterator it = find_if_not(vect.begin(), vect.end(), [](int i){ return (i%2) == 0; });
    if (it != vect.end()) {
        cout << "find not even in vect" << endl;
    }
    int a1[] = {1,2,3,4,5};
    int a2[] = {1,2,3};
    if (find_end(begin(a1), end(a1), begin(a2), end(a2)) != end(a1)) {
        cout << "find a2 in a1" << endl;
    }
    int a3[] = {0,1,2};
    if (find_end(begin(a1), end(a1), begin(a3), end(a3), [](int i, int j) { return i == j + 1; }) != end(a1)) {
        cout << "find a3+1=a1" << endl;
    }

    char ch1[] = {'a','b','c'};
    char ch2[] = {'a','b'};
    char ch3[] = {'A','B'};
    char* it2;
    if ((it2 = find_first_of(begin(ch1), end(ch1), begin(ch2), end(ch2))) != end(ch1)) {
        cout << "find first: " << *it2 << endl;
    }

    int myints[] = {10,20,30,40,40,50,50,51};
    vector<int> myvec(myints, myints+8);
    if (adjacent_find(myvec.begin(), myvec.end()) != myvec.end()) {
        cout << "find adjacent in mycev" << endl;
    }
    if (adjacent_find(myvec.begin(), myvec.end(), [](int i, int j){ return i+1==j; }) != myvec.end()) {
        cout << "find adjacent in lambda" << endl;
    }
    cout << count(begin(myints), end(myints), 40) << endl;
    cout << count_if(myvec.begin(), myvec.end(), [](int i){ return i%2; }) << endl;

    vector<int> myvec2{10, 20, 30, 40};
    vector<int> myvec3{10, 20, 80, 320};
    pair<vector<int>::iterator, vector<int>::iterator> mypair;
    mypair = mismatch(myvec2.begin(), myvec2.end(), myvec3.begin());
    cout << *mypair.first << " " << *mypair.second << endl;
    ++mypair.first, ++mypair.second;
    mypair = mismatch(mypair.first, myvec2.end(), mypair.second, [](int i, int j) { return i==j; });
    cout << *mypair.first << " " << *mypair.second << endl;
    int myints1[] = {1,2,3};
    vector<int> myv1{1,2,4};
    if (equal(begin(myints1), end(myints1), myv1.begin())) {
        cout << "equal" << endl;
    } else {
        cout << "not equal" << endl;
    }
    

    return 0;
}