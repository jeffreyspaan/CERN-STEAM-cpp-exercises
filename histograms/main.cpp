#include <random>
#include <print>
#include <algorithm>
#include <cassert>
#include <numeric>

int main(int argc, char *argv[]) {
	std::random_device rd;
	std::philox4x64 rne(rd());
	std::normal_distribution<float> normal_0_1{0,1};

	size_t number_of_numbers = 256;
	if (argc == 2) {
		number_of_numbers = std::stoi(argv[1], &number_of_numbers);
	}

	std::vector<float> data(number_of_numbers);

	for (float& x : data) {
		x = normal_0_1(rne);
	}

	int n_bins = 21;
	float start_cutoff = *std::min_element(data.begin(), data.end());
	float end_cutoff = *std::max_element(data.begin(), data.end());
	std::vector<int> histogram(n_bins, 0);

	for (float& x : data) {
		float y = std::max(x, start_cutoff);
		y = std::min(y, end_cutoff);
		int bin_i = std::floor(((y - start_cutoff) / (end_cutoff - start_cutoff)) * (n_bins - 1));
		assert(bin_i < n_bins);
		++histogram[bin_i];
		//std::println("{:.2f} {:d} {:d}", x, bin_i, histogram[bin_i]);
	}

	int max_bin = *std::max_element(histogram.begin(), histogram.end());

	for (int &bin : histogram) {
		int num_chars = std::round(((double) bin / max_bin) * 80);
		for (int i=0; i<num_chars; i++) {
			std::print("#");
		}
		std::println(" {:.1f}%", ((double) bin / number_of_numbers) * 100);
	}

//	std::println("data = {:f}", data[0]);
	return 0;
}
