#include <gtest/gtest.h>
#include <chrono>
#include <iostream>
#include "../src/sort/quick.h"
#include "../src/sort/merge.h"
#include "../src/random_sequence.h"

using std::cout;
using std::endl;

double MeasureMs(std::function<void()> f) {
    auto start = std::chrono::high_resolution_clock::now();
    f();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
}

TEST(SortComparison, Array) {
    RandomSequenceGenerator gen;
    auto seq = gen.generateArray(10000);
    auto copy1 = gen.generateArray(0);
    auto copy2 = gen.generateArray(0);

    for (int i = 0; i < seq.GetLength(); ++i) {
        copy1.Append(seq.Get(i));
        copy2.Append(seq.Get(i));
    }

    double quick = MeasureMs([&] { QuickSorter<int>().Sort(&copy1); });
    double merge = MeasureMs([&] { MergeSorter<int>().Sort(&copy2); });
    cout << "Array QuickSort: " << quick << endl;
    cout << "Array MergeSort: " << merge << endl;

    EXPECT_LT(quick, merge * 5);
}

TEST(SortComparison, List) {
    RandomSequenceGenerator gen;
    auto seq = gen.generateList(10000);
    auto copy1 = gen.generateList(0);
    auto copy2 = gen.generateList(0);

    for (int i = 0; i < seq.GetLength(); ++i) {
        copy1.Append(seq.Get(i));
        copy2.Append(seq.Get(i));
    }

    double quick = MeasureMs([&] { QuickSorter<int>().Sort(&copy1); });
    double merge = MeasureMs([&] { MergeSorter<int>().Sort(&copy2); });
    cout << "List QuickSort: " << quick << endl;
    cout << "List MergeSort: " << merge << endl;
    EXPECT_LT(merge, quick);
}