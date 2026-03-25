#ifndef SORTER_H_
#define SORTER_H_

#include "../sequence.h"

template<typename T>
class ISorter {
 public:
    virtual Sequence<T>* Sort(Sequence<T>* seq) = 0;
    virtual ~ISorter() = default;
};

#endif