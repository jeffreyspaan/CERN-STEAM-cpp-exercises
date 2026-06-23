#include <random>
#include <print>
#include <algorithm>

int main() {
	std::random_device rd;
	std::philox4x64 rne(rd());
	std::normal_distribution<float> normal_0_1{0,1};

	std::vector<float> data;
	data.resize(256);
	for (float& x : data) {
		x = normal_0_1(rne);
	}

	int n_bins = 21;
	float start_cutoff = -3.0;
	float end_cutoff = 3.0;
	std::vector<int> histogram;
	histogram.resize(21);
	
	for (float& x : data) {
		y = std::max(x, start_cutoff);
		y = std::min(x, end_cutoff);
		y = ((y - start_cutoff) / (end_cutoff - start_cutoff)) * 21;
		
	}


//	std::println("data = {:f}", data[0]);
	return 0;
}
