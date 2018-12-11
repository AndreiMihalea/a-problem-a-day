#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void scheduler(void (*f)(), int n)
{
	while (1) {
        (*f)();
        std::this_thread::sleep_for(std::chrono::milliseconds(n));
	}
}

void func()
{
	cout << "Hello" << endl;
}

int main()
{
	int n = 2000;
    std::thread th(scheduler, func, n);
    th.join();
}