#include <iostream>
#include "array.h"
#include "list.h"
#include "sequence.h"
#include "sort/merge.h"
#include "sort/quick.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "Enter type of sequence (0 - Array, 1 - List): ";
    short type = 0;
    cin >> type;
    cout << endl;

    Sequence<int>* seq = nullptr;
    if (type == 0) {
        seq = new ArraySequence<int>();
    } else {
        seq = new ListSequence<int>();
    }

    cout << "Enter type of sorting algorithm (0 - merge, 1 - quick): ";
    short sortType = 0;
    cin >> sortType;
    cout << endl;

    ISorter<int>* sorter;
    if (sortType == 0) {
        sorter = new MergeSorter<int>();
    } else {
        sorter = new QuickSorter<int>();
    }

    cout << "Enter number of sequence items: ";
    int num;
    cin >> num;

    for (int k = 0; k < num; ++k) {
        int v;
        cin >> v;
        seq->Append(v);
    }
    cout << endl;

    Sequence<int>* sortedSeq = sorter->Sort(seq);

    cout << "Sorted items:\n";
    for (int i = 0; i < sortedSeq->GetLength(); ++i) {
        cout << sortedSeq->Get(i) << " ";
    }
    cout << endl;

    delete sorter;
    if (sortedSeq != seq) {
        delete sortedSeq;
    }
    delete seq;

    return 0;
}