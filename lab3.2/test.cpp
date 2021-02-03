#include <gtest/gtest.h>
#include "vector.h"

using namespace oop3;

TEST(VectorConstructor, DefaultConstructor)
{
    Vector * vector = new Vector();
    ASSERT_NO_THROW(vector);
    ASSERT_THROW(vector->getNorm(), std::length_error);
}

TEST(Vector_Methods, Getters) {
    Vector * vector = new Vector(1337);
    ASSERT_EQ(1337, vector->getNorm());
}

TEST(Vector_Methods, OverloadAdd){
  double arr[3] = {1.0, 2.0, 3.0};
  Vector * vector1 = new Vector(3, arr);

  *vector1 += 10;

  ASSERT_EQ(10, vector1->getNorm());
}

TEST(Vector_Methods, OverloadSum){
  double arr[3] = {1.0, 2.0, 3.0};
  Vector * vector1 = new Vector(3, arr);
  Vector * vector2 = new Vector(3, arr);

  double arr2[2] = {1.0, 2.0};

  Vector * vector3 = new Vector(2, arr2);

  ASSERT_THROW(*vector2 + *vector3, std::length_error);
  ASSERT_NO_THROW(*vector1+*vector2);
}

TEST(Vector_Methods, OverloadSub){
  double arr[3] = {1.0, 2.0, 3.0};
  Vector * vector1 = new Vector(3, arr);
  Vector * vector2 = new Vector(3, arr);

  double arr2[2] = {1.0, 2.0};

  Vector * vector3 = new Vector(2, arr2);

  ASSERT_THROW(*vector2 - *vector3, std::length_error);
  ASSERT_NO_THROW(*vector1 - *vector2);
}

TEST(Vector_Methods, OverloadMultiply){
  double arr[3] = {1.0, 2.0, 3.0};
  Vector * vector1 = new Vector(3, arr);
  Vector * vector2 = new Vector(3, arr);

  double arr2[2] = {1.0, 2.0};

  Vector * vector3 = new Vector(2, arr2);

  ASSERT_THROW(*vector2 * *vector3, std::length_error);
  ASSERT_NO_THROW(*vector1 * *vector2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
