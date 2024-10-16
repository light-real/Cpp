#pragma once
#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <sys/syscall.h>
#include <mutex>
#include <unistd.h>
#include <thread>
#include <condition_variable>
#include <functional>
#include <future>
#include <atomic>

class ThreadPool
{
private:
    std::queue<std::function<void()>> taskqueue_; // 任务队列
    std::vector<std::thread> threads_;            // 线程池中的线程
    std::mutex mutex_;                            // 任务队列同步的互斥锁
    std::condition_variable condition_;           // 任务队列同步的条件变量
    std::atomic_bool stop_;                       // 在析构函数中 把stop_的值设置为true 全部的线程将退出
    const std::string threadtype_;                // 线程种类 "IO" "WORKS"
public:
    ThreadPool(size_t threadnum, const std::string &threadtype); // 在构造函数中将启动threadnum个线程
    void addtask(std::function<void()> task);                    // 把任务添加到队列中
    size_t size();                                               // 获取线程池的大小
    void stop();                                                 // 停止线程
    ~ThreadPool();                                               // 在析构函数中将停止线程
};