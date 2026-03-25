#include <gtest/gtest.h>
#include <list>
#include "../src/sort/quick.h"
#include "../src/random_sequence.h"

template <typename T>
std::list<T> to_std_list(const Sequence<T>& seq) {
    std::list<T> res;
    for (int i = 0; i < seq.GetLength(); ++i) {
        res.push_back(seq.Get(i));
    }
    return res;
}

template <typename SeqType>
void CheckQuickSorter(SeqType* seq) {
    std::list<int> stdlist = to_std_list(*seq);
    stdlist.sort();

    QuickSorter<int> sorter;
    Sequence<int>* sortedSeq = sorter.Sort(seq);

    auto it = stdlist.begin();
    for (int i = 0; i < sortedSeq->GetLength(); ++i, ++it) {
        EXPECT_EQ(*it, sortedSeq->Get(i));
    }
}

TEST(QuickSorter, QuickOnList) {
    RandomSequenceGenerator gen;
    ListSequence<int> listSeq = gen.generateList(10000);
    CheckQuickSorter(&listSeq);
}

TEST(QuickSorter, QuickOnArray) {
    RandomSequenceGenerator gen;
    ArraySequence<int> arrSeq = gen.generateArray(10000);
    CheckQuickSorter(&arrSeq);
}