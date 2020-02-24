#include <gmock/gmock.h>

#include <foo.hpp>

using namespace ::testing;

TEST(Foo, NameOfFirstPassingTest){
  ASSERT_TRUE(true);
}

TEST(Foo, NameOfFirstFailingTest){
  ASSERT_TRUE(false);
}
