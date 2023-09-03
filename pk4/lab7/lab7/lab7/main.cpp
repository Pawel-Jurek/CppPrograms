#include <barrier>
#include <iostream>
#include <sstream>
#include <thread>
#include <semaphore>
#include <chrono>

void info(std::barrier<>& limit, int j) {
    std::stringstream thread_stream;

    thread_stream << "Thread number: " << j << " created\n";
    std::cout << thread_stream.str();
    thread_stream.str("");

    limit.arrive_and_wait();

    thread_stream << "Thread number: " << j << " has just finished work\n";
    std::cout << thread_stream.str();
}


void print_char(std::binary_semaphore& sem1, std::binary_semaphore& sem2, char letter) {
    while (true) {
        sem1.acquire();
        std::cout << letter << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        sem2.release();
    }
}

void print_A(std::counting_semaphore<3>& sem1, std::counting_semaphore<3>& sem2, std::counting_semaphore<3>& sem3, char letter) {
    while (true) {
        sem1.acquire();
        sem1.acquire();
        std::cout << letter << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        sem2.release();
    }
}
void print_E(std::counting_semaphore<3>& sem1, std::counting_semaphore<3>& sem2, std::counting_semaphore<3>& sem3, char letter) {
    while (true) {
        sem2.acquire();
        std::cout << letter << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        sem3.release();
        sem3.release();
    }
}
void print_I(std::counting_semaphore<3>& sem1, std::counting_semaphore<3>& sem2, std::counting_semaphore<3>& sem3, char letter) {
    while (true) {
        sem3.acquire();
        std::cout << letter << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        sem1.release();
    }
}


void print_c(std::counting_semaphore<3>& sem_a, std::counting_semaphore<3>& sem_b, std::counting_semaphore<3>& sem_c) {
    while (true) {
        sem_c.acquire();
        std::cout << 'C' << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        sem_a.release();
        sem_b.release();
    }
}

void print_b(std::counting_semaphore<3>& sem_a, std::counting_semaphore<3>& sem_b, std::counting_semaphore<3>& sem_c) {
    while (true) {
        sem_b.acquire();
        sem_b.acquire();
        std::cout << 'B' << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        sem_c.release();
        sem_a.release();
    }
}

void print_a(std::counting_semaphore<3>& sem_a, std::counting_semaphore<3>& sem_b, std::counting_semaphore<3>& sem_c) {
    while (true) {
        sem_a.acquire();
        sem_a.acquire();
        sem_a.acquire();
        std::cout << 'A' << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        sem_c.release();
    }
}

void zad1()
{
    const int amount_of_Threads = 5;
    std::barrier limit(amount_of_Threads);
    std::thread threads1[5];

    for (int i = 0; i < amount_of_Threads; i++) {
        threads1[i] = std::thread(info, std::ref(limit), i);
    }

    for (auto& thread : threads1) {
        thread.join();
    }
}

void zad2()
{
    std::binary_semaphore sem_z{ 1 };
    std::binary_semaphore sem_a{ 0 };
    std::binary_semaphore sem_d{ 0 };
    std::binary_semaphore sem_2{ 0 };
    std::thread threads2[4];

    threads2[0] = std::thread(print_char, std::ref(sem_z), std::ref(sem_a), 'z');
    threads2[1] = std::thread(print_char, std::ref(sem_a), std::ref(sem_d), 'a');
    threads2[2] = std::thread(print_char, std::ref(sem_d), std::ref(sem_2), 'd');
    threads2[3] = std::thread(print_char, std::ref(sem_2), std::ref(sem_z), '2');

    for (auto& thread : threads2) {
        thread.join();
    }
}

void zad3()
{
    std::counting_semaphore<3> sem_A{ 2 };
    std::counting_semaphore<3> sem_E{ 0 };
    std::counting_semaphore<3> sem_I{ 0 };

    std::thread threads3[3];

    threads3[0] = std::thread(print_A, std::ref(sem_A), std::ref(sem_E), std::ref(sem_I), 'A');
    threads3[1] = std::thread(print_E, std::ref(sem_A), std::ref(sem_E), std::ref(sem_I), 'E');
    threads3[2] = std::thread(print_I, std::ref(sem_A), std::ref(sem_E), std::ref(sem_I), 'I');

    for (auto& thread : threads3) {
        thread.join();
    }
}

void zad4()
{
    std::counting_semaphore<3> sem_c{ 1 };
    std::counting_semaphore<3> sem_b{ 0 };
    std::counting_semaphore<3> sem_a{ 2 };

    std::thread threads4[3];
    threads4[0] = std::thread(print_a, std::ref(sem_a), std::ref(sem_b), std::ref(sem_c));
    threads4[1] = std::thread(print_b, std::ref(sem_a), std::ref(sem_b), std::ref(sem_c));
    threads4[2] = std::thread(print_c, std::ref(sem_a), std::ref(sem_b), std::ref(sem_c));

    for (auto& thread : threads4) {
        thread.join();
    }
}

int main() {
    zad1();
    //zad2();
    //zad3();
    //zad4();

    return 0;
}