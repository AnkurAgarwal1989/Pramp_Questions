#include <algorithm>
#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Image {
	int W;
	int H;
	vector<T> data;

	Image(int w, int h) : W(w), H(h) {
		data.resize(W*H);
	};
};

template <typename T>
void printImage(Image<T>& img) {
	int j = 0;
	std::for_each(img.data.cbegin(), img.data.cend(), [=, &j](const auto& v) {
		std::cout << static_cast<int>(v) << " ";
		++j;
		if (j % img.W == 0) {
			std::cout << std::endl;
		}
	});
	std::cout << std::endl;
}

template <typename T>
void fillImage(Image<T>& img, T val) {
	std::for_each(img.data.begin(), img.data.end(), [=](auto& v) {v = val; });
}


void integralImage(Image<uint8_t>& img, Image<float>& out) {
	fillImage<float>(out, 0);

	for (int i = 1; i < out.H; ++i) {
		for (int j = 1; j < out.W; ++j) {
			out.data[i*out.W + j] = out.data[(i - 1)*out.W + j] + out.data[i*out.W + (j - 1)]
				- out.data[(i - 1)*out.W + (j - 1)] + img.data[(i - 1)*img.W + j - 1];
		}
	}
}

void boxFilter(Image<uint8_t>& img, Image<float>& intImg, Image<float>& out, uint8_t k) {
	for (int i = k; i < intImg.H; ++i) {
		for (int j = k; j < intImg.W; ++j) {
			out.data[(i - k)*out.W + (j - k)] = intImg.data[(i)*intImg.W + (j)] - intImg.data[(i - k)*intImg.W + (j)]
				- intImg.data[(i)*intImg.W + (j - k)] + intImg.data[(i - k)*intImg.W + (j - k)];
			out.data[(i - k)*out.W + (j - k)] /= static_cast<float>(k * k);
		}
	}
}

int main() {
	int H = 10;
	int W = 10;
	int k = 3;
	Image<uint8_t> img{ W, H };
	Image<float> intImg{ W + 1, H + 1 };
	Image<float> filtImg{ W - (k+1)/2, H - (k+1)/2 };
	cout << img.data.size() << endl;
	assert(img.data.size() == img.H * img.W);
	fillImage<uint8_t>(img, 1);
	printImage<uint8_t>(img);
	integralImage(img, intImg);
	printImage<float>(intImg);
	boxFilter(img, intImg, filtImg, k);
	printImage<float>(filtImg);
	cin.get();
	return 1;
}

