#include <gtest/gtest.h>
#include "catenary.h"

using namespace Lab2Catenary;

TEST(Catenary_Constructor, Default_Constructor)
{
    Catenary catenary;
    ASSERT_NO_THROW(catenary);
    ASSERT_EQ(0, catenary.get_center());
    ASSERT_EQ(1, catenary.get_tension());
}

TEST(Catenary_Constructor, Initial_Constructor)
{
    ASSERT_NO_THROW(Catenary catenary_1(2, 4));

    ASSERT_DEATH(Catenary catenary_2(1,-1), "a > 0");
    ASSERT_DEATH(Catenary catenary_2(-7,-9), "a > 0");
}

TEST(Catenary_Methods, Setters) {
    Catenary catenary;
    ASSERT_NO_THROW(catenary.set_center(8));
    ASSERT_NO_THROW(catenary.set_center(-8));

    ASSERT_NO_THROW(catenary.set_tension(4));
    ASSERT_DEATH(catenary.set_tension(-8), "a > 0");
}

TEST(Catenary_Methods, Getters) {
    Catenary catenary_1(1, 1);
    ASSERT_EQ(1, catenary_1.get_center());
    ASSERT_EQ(1, catenary_1.get_tension());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
