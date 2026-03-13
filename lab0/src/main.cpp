#include <cassert>
#include <iostream>
#include <string>

#include "array.h"
#include "list.h"

using std::cout;
using std::endl;
using std::string;

int main() {
  ArraySequence<string> s;
  s.Append("НИЯУ");
  s.Append("МИФИ");
  s.Append("МЯУ");
  s.Append("ХИХИ");

  ListSequence<string> l;
  l.Append("НИЯУ");
  l.Append("МИФИ");
  l.Append("МЯУ");
  l.Append("ХИХИ");

  assert(s.GetLength() == 4);
  cout << l.GetLength() << endl;
  cout << l.Get(0) << endl;
  assert(l.GetLength() == 4);

  for (int i = 0; i < 4; i++) {
    assert(s.Get(i) == l.Get(i));
  }

  cout << "check up" << endl;
  return 0;
}
