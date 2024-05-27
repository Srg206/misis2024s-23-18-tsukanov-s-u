#include <queuelst/queuelst.hpp>
#include <queuearr/queuearr.hpp>
#include <chrono>
#include <vector>
#include <string>

template<typename T>
std::string Time_to_add_one_el(const T& queue) {
	auto begin = std::chrono::high_resolution_clock::now();
	a.Push(c);
	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		


}



int main() {
	QueueLst a;
	QueueArr b;
	Complex c(3.88, 7.99);

	auto begin = std::chrono::high_resolution_clock::now();
	a.Push(c);
	auto end = std::chrono::high_resolution_clock::now();
	auto time_lst = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	begin = std::chrono::high_resolution_clock::now();
	b.Push(c);
	end = std::chrono::high_resolution_clock::now();
	auto time_arr = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	std::cout << "time to push 1 element for lst - " << time_lst.count() << " ns\n";
	std::cout << "time to push 1 element for arr - " << time_arr.count() << " ns\n";

	std::vector<Complex> test_data(100);
	for (int i = 0; i < 100; i++) {
		srand(time(0));
		test_data[i] = Complex(rand(), rand());
	}

	begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100; i++) {
		a.Push(test_data[i]);
	}
	end = std::chrono::high_resolution_clock::now();
	time_lst = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100; i++) {
		b.Push(test_data[i]);
	}
	end = std::chrono::high_resolution_clock::now();
	time_arr = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);


	std::cout << "\ntime to push 100 element for lst - " << time_lst.count() << " ns\n";
	std::cout << "time to push 100 element for arr - " << time_arr.count() << " ns\n";


	return 0;
}
