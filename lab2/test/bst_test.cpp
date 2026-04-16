#include "../src/util/bst/bst.h"
#include "../src/models/student.h"
#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

using std::runtime_error;

TEST(BSTTest, BasicOperations) {
    BST<std::string, Student> bst;
    
    EXPECT_TRUE(bst.GetIsEmpty());
    EXPECT_EQ(bst.GetCount(), 0);
    EXPECT_EQ(bst.GetLength(), 0);
    
    Student s1{"Doe", "John", 1001};
    Student s2{"Smith", "Alice", 1002};
    Student s3{"Johnson", "Bob", 1003};
    
    bst.Insert("Doe", s1);
    bst.Insert("Smith", s2);
    bst.Insert("Johnson", s3);
    
    EXPECT_FALSE(bst.GetIsEmpty());
    EXPECT_EQ(bst.GetCount(), 3);
    EXPECT_EQ(bst.GetLength(), 3);
    
    EXPECT_TRUE(bst.ContainsKey("Doe"));
    EXPECT_TRUE(bst.ContainsKey("Smith"));
    EXPECT_TRUE(bst.ContainsKey("Johnson"));
    EXPECT_FALSE(bst.ContainsKey("Brown"));
    
    EXPECT_EQ(bst.At("Doe").group_number, 1001);
    EXPECT_EQ(bst.At("Smith").group_number, 1002);
    EXPECT_EQ(bst.At("Johnson").group_number, 1003);
    
    EXPECT_THROW(bst.At("Brown"), runtime_error);
}

TEST(BSTTest, SortedSequenceInterface) {
    BST<int, Student> bst;
    
    Student s1{"A", "First", 10};
    Student s2{"B", "Second", 20};
    Student s3{"C", "Third", 30};
    Student s4{"D", "Fourth", 40};
    
    bst.Insert(10, s1);
    bst.Insert(30, s3);
    bst.Insert(20, s2);
    bst.Insert(40, s4);
    
    EXPECT_EQ(bst.GetLength(), 4);
    EXPECT_FALSE(bst.GetIsEmpty());
    
    EXPECT_EQ(bst.Get(0).group_number, 10);
    EXPECT_EQ(bst.Get(1).group_number, 20);
    EXPECT_EQ(bst.Get(2).group_number, 30);
    EXPECT_EQ(bst.Get(3).group_number, 40);
    
    EXPECT_EQ(bst.GetFirst().group_number, 10);
    EXPECT_EQ(bst.GetLast().group_number, 40);
    
    EXPECT_EQ(bst.IndexOf(s1), 0);
    EXPECT_EQ(bst.IndexOf(s2), 1);
    EXPECT_EQ(bst.IndexOf(s3), 2);
    EXPECT_EQ(bst.IndexOf(s4), 3);
    
    EXPECT_EQ(bst.IndexOf(Student{"X", "Y", 999}), -1);
    
    EXPECT_THROW(bst.Get(-1), std::out_of_range);
    EXPECT_THROW(bst.Get(4), std::out_of_range);
}

TEST(BSTTest, DictionaryInterface) {
    BST<std::string, Student> bst;
    
    Student s1{"Doe", "John", 1001};
    Student s2{"Smith", "Alice", 1002};
    
    bst.Insert("Doe", s1);
    bst.Insert("Smith", s2);
    
    EXPECT_EQ(bst.GetCount(), 2);
    EXPECT_EQ(bst.GetCapacity(), -1);
    
    EXPECT_TRUE(bst.ContainsKey("Doe"));
    EXPECT_TRUE(bst.ContainsKey("Smith"));
    EXPECT_FALSE(bst.ContainsKey("Brown"));
    
    EXPECT_EQ(bst.At("Doe").group_number, 1001);
    EXPECT_EQ(bst.At("Smith").group_number, 1002);
}

TEST(BSTTest, AddValue) {
    BST<int, Student> bst;
    
    Student s1{"A", "First", 10};
    Student s2{"B", "Second", 20};
    
    bst.Add(s1);
    bst.Add(s2);
    
    EXPECT_EQ(bst.GetLength(), 2);
    EXPECT_TRUE(bst.ContainsKey(10));
    EXPECT_TRUE(bst.ContainsKey(20));
}

TEST(BSTTest, Remove) {
    BST<int, Student> bst;
    
    Student s1{"A", "First", 10};
    Student s2{"B", "Second", 20};
    Student s3{"C", "Third", 30};
    Student s4{"D", "Fourth", 40};
    
    bst.Insert(10, s1);
    bst.Insert(20, s2);
    bst.Insert(30, s3);
    bst.Insert(40, s4);
    
    bst.Remove(40);
    EXPECT_EQ(bst.GetLength(), 3);
    EXPECT_FALSE(bst.ContainsKey(40));
    EXPECT_THROW(bst.At(40), runtime_error);
    
    bst.Remove(30);
    EXPECT_EQ(bst.GetLength(), 2);
    EXPECT_FALSE(bst.ContainsKey(30));
    EXPECT_THROW(bst.At(30), runtime_error);
    
    bst.Remove(20);
    EXPECT_EQ(bst.GetLength(), 1);
    EXPECT_FALSE(bst.ContainsKey(20));
    EXPECT_THROW(bst.At(20), runtime_error);
    
    bst.Remove(10);
    EXPECT_TRUE(bst.GetIsEmpty());
    EXPECT_EQ(bst.GetLength(), 0);
}

TEST(BSTTest, EdgeCases) {
    BST<int, Student> bst;
    
    EXPECT_TRUE(bst.GetIsEmpty());
    EXPECT_EQ(bst.GetLength(), 0);
    
    EXPECT_THROW(bst.GetFirst(), runtime_error);
    EXPECT_THROW(bst.GetLast(), runtime_error);
    EXPECT_THROW(bst.Get(0), std::out_of_range);
    bst.Remove(1);
    
    Student s1{"A", "First", 10};
    Student s1_duplicate{"A", "First Duplicate", 15};
    
    bst.Insert(10, s1);
    bst.Insert(10, s1_duplicate);
    
    EXPECT_EQ(bst.GetLength(), 1);
    EXPECT_EQ(bst.At(10).group_number, 15);
    
    EXPECT_EQ(bst.GetFirst().group_number, 15);
    EXPECT_EQ(bst.GetLast().group_number, 15);
}

TEST(BSTTest, LargeTree) {
    BST<int, Student> bst;
    
    for (int i = 1; i <= 100; i++) {
        Student s{"Name " + std::to_string(i), "First " + std::to_string(i), i * 10};
        bst.Insert(i, s);
    }
    
    EXPECT_EQ(bst.GetLength(), 100);
    EXPECT_FALSE(bst.GetIsEmpty());
    
    EXPECT_EQ(bst.Get(0).group_number, 10);
    EXPECT_EQ(bst.Get(50).group_number, 510);
    EXPECT_EQ(bst.Get(99).group_number, 1000);
    
    EXPECT_EQ(bst.IndexOf(Student{"Name 5", "First 5", 50}), 4);
    EXPECT_EQ(bst.IndexOf(Student{"Name 42", "First 42", 420}), 41);
    
    bst.Remove(1);
    bst.Remove(50);
    bst.Remove(100);
    
    EXPECT_EQ(bst.GetLength(), 97);
    
    EXPECT_FALSE(bst.ContainsKey(1));
    EXPECT_FALSE(bst.ContainsKey(50));
    EXPECT_FALSE(bst.ContainsKey(100));
    EXPECT_TRUE(bst.ContainsKey(2));
    EXPECT_TRUE(bst.ContainsKey(49));
    EXPECT_TRUE(bst.ContainsKey(99));
}