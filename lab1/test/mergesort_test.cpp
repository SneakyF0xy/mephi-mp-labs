#include <gtest/gtest.h>
#include <list>
#include "../src/sort/merge.h"
#include "../src/random_sequence.h"


template <typename T>
std::list<T> to_std_list(Sequence<T>& seq) {
    std::list<T> res;
    for (int i = 0; i < seq.GetLength(); ++i) {
        res.push_back(seq.Get(i));
    }
    return res;
}


template <typename SeqType>
void CheckMergeSorter(SeqType& seq) {
    std::list<int> stdlist = to_std_list(seq);
    stdlist.sort();

    MergeSorter<int> sorter;
    Sequence<int>* sortedSeq = sorter.Sort(&seq);

    auto it = stdlist.begin();
    for (int i = 0; i < sortedSeq->GetLength(); ++i, ++it) {
        EXPECT_EQ(*it, sortedSeq->Get(i));
    }

    delete sortedSeq;
}


TEST(MergeSorter, MergeOnList) {
    RandomSequenceGenerator gen;
    ListSequence<int> listSeq = gen.generateList(10000);
    CheckMergeSorter(listSeq);
}


TEST(MergeSorter, MergeOnArray) {
    RandomSequenceGenerator gen;
    ArraySequence<int> arrSeq = gen.generateArray(10000);
    CheckMergeSorter(arrSeq);
}