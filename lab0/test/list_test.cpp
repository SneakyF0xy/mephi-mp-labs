#include "../src/list.h"

#include <gtest/gtest.h>

TEST(ListSequenceTest, BasicScenario) {
  ListSequence<int> seq;

  EXPECT_EQ(seq.GetLength(), 0);

  seq.Append(23);

  EXPECT_EQ(seq.GetLength(), 1);

  EXPECT_EQ(seq.GetFirst(), 23);

  EXPECT_EQ(seq.GetLast(), 23);

  EXPECT_EQ(seq.Get(0), 23);
  EXPECT_THROW(seq.Get(-1), std::runtime_error);
  EXPECT_THROW(seq.Get(1), std::runtime_error);

  seq.Append(43);

  EXPECT_EQ(seq.GetLength(), 2);

  EXPECT_EQ(seq.GetFirst(), 23);

  EXPECT_EQ(seq.GetLast(), 43);

  EXPECT_EQ(seq.Get(0), 23);
  EXPECT_EQ(seq.Get(1), 43);
  EXPECT_THROW(seq.Get(-1), std::runtime_error);
  EXPECT_THROW(seq.Get(2), std::runtime_error);

  seq.Prepend(53);
  // 53 23 43

  EXPECT_EQ(seq.GetLength(), 3);

  EXPECT_EQ(seq.GetFirst(), 53);

  EXPECT_EQ(seq.GetLast(), 43);

  EXPECT_EQ(seq.Get(0), 53);
  EXPECT_EQ(seq.Get(1), 23);
  EXPECT_EQ(seq.Get(2), 43);
  EXPECT_THROW(seq.Get(-1), std::runtime_error);
  EXPECT_THROW(seq.Get(3), std::runtime_error);

  auto sub = seq.GetSubsequence(1, 1);

  EXPECT_EQ(sub.GetLength(), 1);

  EXPECT_EQ(sub.GetFirst(), 23);
  EXPECT_EQ(sub.GetLast(), 23);
}
