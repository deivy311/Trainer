#include <iostream>
#include <thread>
#include <cstring> // For strerror()

#ifdef _WIN32
    #include <windows.h>
#else
    #include <pthread.h>
#endif

void Process() {
    // std::cout << "Threadid:" << std::this_thread::get_id() << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << i << ' ';
    }
}

int main() {
    std::thread t1(Process);

    // Get and print the thread ID
    auto id = t1.get_id();
    std::cout << "t1.get_id(): " << std::hash<std::thread::id>{}(id) << std::endl;

    // Get and print the number of hardware cores
    int cores = std::thread::hardware_concurrency();
    std::cout << "Cores: " << cores << std::endl;

    // Platform-specific code to set the thread name
    #ifdef _WIN32
        HANDLE handle = t1.native_handle();
        HRESULT hr = SetThreadDescription(handle, L"MyThread");
        if (FAILED(hr)) {
            std::cerr << "Failed to set thread description" << std::endl;
        }
    #else
        pthread_t handle = t1.native_handle();
        int res = pthread_setname_np(handle, "MyThread");
        if (res != 0) {
            std::cerr << "Failed to set thread name: " << strerror(res) << std::endl;
        }
    #endif

    t1.join();
    return 0;
}
