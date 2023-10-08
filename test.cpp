#include <iostream>
#include <thread>

using namespace std;

int main() {
    char str1[] = "abc";
    char str2[] = "abc";
    const char str3[] = "abc";
    const char str4[] = "abc";
    char* str5 = "abc";
    char* str6 = "abc";
    const char* str7 = "abc";
    const char* str8 = "abc";
    cout << (str1 == str2) << endl;
    cout << (str3 == str4) << endl;
    cout << (str5 == str6) << endl;
    cout << (str7 == str8) << endl;
    cout << (int*)str1 << " " << (int*)str2 << " " << (int*)str3 << " " << (int*)str4 << endl;
    cout << (int*)str5 << " " << (int*)str6 << " " << (int*)str7 << " " << (int*)str8 << endl;

    unsigned int numThreads = std::thread::hardware_concurrency();

    if (numThreads == 0) {
        std::cout << "无法确定硬件线程数。" << std::endl;
    } else {
        std::cout << "可用的硬件线程数为: " << numThreads << std::endl;
    }

    return 0;
}