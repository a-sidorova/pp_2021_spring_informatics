// Copyright 2021 Vagina Valeria
#include <gtest/gtest.h>
#include <vector>
#include "../../../modules/task_1/vagina_v_gauss_filter/gauss_filter.h"

TEST(Gauss_seq, Small_Image) {
    const int width = 10;
    const int height = 10;

    std::vector<Pixel> img = generateRandomImage(width, height);
    std::vector<Pixel> res = gaussFilter(img, width, height);

    ASSERT_NE(res, img);
}

TEST(Gauss_seq, Empty_Image) {
    const int width = 0;
    const int height = 0;

    std::vector<Pixel> img = generateRandomImage(width, height);

    ASSERT_EQ(img, gaussFilter(img, width, height));
}

TEST(Gauss_seq, Kernel_Size) {
    const int width = 2;
    const int height = 50;

    std::vector<Pixel> img = generateRandomImage(width, height);

    ASSERT_NE(img, gaussFilter(img, width, height));
}

TEST(Gauss_seq, Kernel_Size_1) {
    const int width = 50;
    const int height = 2;

    std::vector<Pixel> img = generateRandomImage(width, height);

    ASSERT_NE(img, gaussFilter(img, width, height));
}

TEST(Gauss_seq, Incorrect_Image_Height) {
    const int width = 10;
    const int height = 10;

    std::vector<Pixel> img = generateRandomImage(width, height);

    ASSERT_ANY_THROW(gaussFilter(img, width, height - 1));
}

TEST(Gauss_seq, Incorrect_Image_Width) {
    const int width = 10;
    const int height = 10;

    std::vector<Pixel> img = generateRandomImage(width, height);

    ASSERT_ANY_THROW(gaussFilter(img, width + 1, height));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
