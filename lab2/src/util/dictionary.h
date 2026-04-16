#ifndef UTIL_DICTIONARY_H_
#define UTIL_DICTIONARY_H_

template <typename K, typename V> class IDictionary {
public:
  virtual ~IDictionary() = default;
  virtual int GetCount() const = 0;
  virtual int GetCapacity() const = 0;
  virtual V At(const K &key) const = 0;
  virtual bool ContainsKey(const K &key) const = 0;
  virtual void Insert(const K &key, const V &element) = 0;
  virtual void Remove(const K &key) = 0;
};

#endif