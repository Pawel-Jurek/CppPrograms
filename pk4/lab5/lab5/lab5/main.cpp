#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <numeric>

using std::cout;

void thread1()
{
	cout << "Thread 1\n";
}

int sum(int number1, int number2)
{
	return number1 + number2;
}

void thread2(int number1, int number2)
{
	cout << "Thread 2: "<< sum(number1, number2) <<"\n";
}

int getSum(const std::vector<int>& numbers)
{
	return std::accumulate(numbers.begin(), numbers.end(), 0);
}

double getAverage(const std::vector<int>& numbers)
{
	return getSum(numbers) / static_cast<double>(numbers.size());
}

int getMax(const std::vector<int>& numbers)
{
	if (!numbers.empty())
		return *std::max_element(numbers.begin(), numbers.end());
	return 0;
}

int main()
{
	//zadanie 1
	std::cout << "ZADANIE 1\n";
	std::thread t1(thread1);
	std::future<void>f2 = std::async(std::launch::async, thread2, 5, 10);
	t1.join();
	f2.wait();


	//zadanie 2
	std::cout << "----------------\n";
	std::cout << "ZADANIE 2\n";

	std::packaged_task<int(int, int)> task(sum);
	std::future<int> result = task.get_future();

	std::thread t2(std::move(task), 5, 10);
	t2.join();

	std::cout << "Result: " << result.get() << "\n";


	//zadanie 3
	std::vector<int> numbers {3, 5, 2, 1, 7, 19, 0, 1};

	std::promise<int> sumPromise;
	std::promise<double> averagePromise;
	std::promise<int> maxPromise;

	std::future<int> sumFuture = sumPromise.get_future();
	std::future<double> averageFuture = averagePromise.get_future();
	std::future<int> maxFuture = maxPromise.get_future();

	std::async(std::launch::async, [&numbers, &sumPromise]() {
		sumPromise.set_value(getSum(numbers));
		});

	std::async(std::launch::async, [&numbers, &averagePromise]() {
		averagePromise.set_value(getAverage(numbers));
		});

	std::async(std::launch::async, [&numbers, &maxPromise]() {
		maxPromise.set_value(getMax(numbers));
		});
	std::cout << "----------------\n";
	std::cout << "ZADANIE 3\n";
	std::cout << "Sum: " << sumFuture.get() << "\n";
	std::cout << "Average: " << averageFuture.get() << "\n";
	std::cout << "Max: " << maxFuture.get() << "\n";
}