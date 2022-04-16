// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T arr[10];
    int first;
    int last;

 public:
    TPQueue() :first(0), last(0) { }
    void push(T vivod) {
      int lastpp = last++;
      for (bool i = false; i != true; ) {
        if ((--lastpp >= first) && (arr[lastpp % size].prior < vivod.prior)) {
          arr[(lastpp + 1) % size] = arr[lastpp % size];
        } else {
            i = true;
          }
      }
      arr[(lastpp + 1) % size] = vivod;
    }
    T pop() {
      return arr[(first++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
