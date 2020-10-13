#include <gtest/gtest.h>

// Headers of objects that student should implement:
int max(int a, int b);
int legngyobb(int* tomb, int meret);
float atlag(int* jegyek, int meret);

// Tests:
TEST(maxTest, Simple) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_EQ(max(1, 2), 2);
    ASSERT_EQ(max(7, 2), 7);
    ASSERT_EQ(max(-7, -4), -4);
}

TEST(LegnagyobbTest, Simple) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    int tomb1[] = {3, 7, 2, 1, 0};
    ASSERT_EQ(legngyobb(tomb1, 5), 7);
    int tomb2[] = {8, 5, 3, 3, 7, 1, -5};
    ASSERT_EQ(legngyobb(tomb2, 7), 8);
    int tomb3[] = {-4, -2, -7, -3, -1};
    ASSERT_EQ(legngyobb(tomb3, 5), -1);
}

TEST(AtlagTest, Simple) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    int tomb1[] = {4, 4, 4, 2, 1};
    ASSERT_EQ(atlag(tomb1, 5), 3);
    int tomb2[] = {4, 2, 1, 1, 5, 1, 1};
    ASSERT_EQ((int)(atlag(tomb2, 7) * 100) / 100.0, 2.14);
    int tomb3[] = {1, 1, 1, 1, 1, 2};
    ASSERT_EQ((int)(atlag(tomb3, 6) * 100) / 100.0, 1.16);
}