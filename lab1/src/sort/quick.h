#ifndef QUICK_H_
#define QUICK_H_

#include "sorter.h"

template<typename T>
class QuickSorter : public ISorter<T> {
public:
    Sequence<T>* Sort(Sequence<T>* seq) {
        if (seq->GetLength() <= 1) {
            return seq;
        }
        quickSort(seq, 0, seq->GetLength() - 1);
        return seq;
    }

private:
    void quickSort(Sequence<T>* arr, int left, int right) {
        if (left < right) {
            int pi = partition(arr, left, right);
            quickSort(arr, left, pi - 1);
            quickSort(arr, pi + 1, right);
        }
    }

    void swap(Sequence<T>* arr, int i, int j) {
        if (i == j) return;
        T temp = arr->Get(i);
        arr->Set(i, arr->Get(j));
        arr->Set(j, temp);
    }

    int partition(Sequence<T>* arr, int left, int right) {
        T pivot = arr->Get(right);
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (arr->Get(j) <= pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, right);
        return i + 1;
    }
};

#endif