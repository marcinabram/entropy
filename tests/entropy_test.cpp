#include <gtest/gtest.h>
#include <math.h>
#include "../src/entropy.h"

TEST(bools_to_int, full_tab) {
  bool tab[] = {0, 0, 0, 1, 0, 1};
  EXPECT_EQ(bools_to_int(tab, 0, 6), 5);
}

TEST(bools_to_int, tab_end1) {
  bool tab[] = {0, 0, 0, 1, 0, 1};
  EXPECT_EQ(bools_to_int(tab, 3, 6), 5);
}

TEST(bools_to_int, tab_end2) {
  bool tab[] = {0, 0, 0, 1, 0, 1};
  EXPECT_EQ(bools_to_int(tab, 4, 6), 1);
}

TEST(bools_to_int, tab_beginning1) {
  bool tab[] = {0, 0, 0, 1, 0, 1};
  EXPECT_EQ(bools_to_int(tab, 0, 2), 0);
}

TEST(bools_to_int, tab_beginning2) {
  bool tab[] = {0, 0, 0, 1, 0, 1};
  EXPECT_EQ(bools_to_int(tab, 4, 6), 1);
}

TEST(bools_to_int, tab_middle) {
  bool tab[] = {0, 0, 0, 1, 0, 1};
  EXPECT_EQ(bools_to_int(tab, 2, 5), 2);
}

TEST(entropy, zero) {
  bool tab[] = {0, 1, 0, 1, 0, 1};
  EXPECT_EQ(entropy(tab, 6, 2), 0);
}

TEST(entropy, one) {
  bool tab[] = {0, 0, 0, 1, 1, 0, 1, 1};
  EXPECT_EQ(entropy(tab, 8, 2), 1);
}

TEST(entropy, mixed1) {
  bool tab[] = {0, 0, 0, 1, 1};
  float expected = -(3*log(3./5.) + 2*log(2./5.))/(5*log(2));
  EXPECT_EQ(entropy(tab, 5, 1), expected);
}



int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
