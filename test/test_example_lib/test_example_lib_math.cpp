#include "test_example_lib_math.h"
#include "example_lib/math.h"

#include <unity.h>

void test_example_lib_add()
{
  TEST_ASSERT_EQUAL(3, example_lib::add(1, 2));
}