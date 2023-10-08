#include <iostream>
#include <future>
#include <chrono>
#include <string>
#include <string.h>

using namespace std;

int main() {
    future<int> fut = async(launch::async, []() {
        return 42;
    });
    auto start = chrono::high_resolution_clock::now();

    shared_future<int> sharedFuture1 = fut.share();
    shared_future<int> sharedFuture2 = sharedFuture1;

    thread t1([&sharedFuture1]() {
        int result = sharedFuture1.get();
        cout << "t1: " << this_thread::get_id() << ": " << result << endl;
    });
    thread t2([&sharedFuture2]() {
        int result = sharedFuture2.get();
        cout << "t2: " << this_thread::get_id() << ": " << result << endl;
    });
    t1.join();
    t2.join();
    this_thread::sleep_for(chrono::seconds(2));
    auto end = chrono::high_resolution_clock::now();
    cout << (chrono::duration<double, ratio<1,1000>>(end-start)).count() << endl;
}