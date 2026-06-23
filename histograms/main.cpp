#include <random>
#include <print>

int main() {
	std::random_device rd;
	std::philox4x64 rne(rd());
	std::normal_distribution<float> normal_0_1{0,1};

	std::vector<float> data;
	data.resize(256);
	for (float& x : data) {
		x = normal_0_1(rne);
		std::print("{:f} ", x);
	}
	std::println();

	std::println("data = {:f}", data[0]);
	return 0;
}
