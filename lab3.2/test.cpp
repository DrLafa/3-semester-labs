#include <gtest/gtest.h>
#include "vector.h"

using namespace oop3;

TEST(Vector_Constructor, Default_Constructor)
{
    Vector vector;
    ASSERT_NO_THROW(vector);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
