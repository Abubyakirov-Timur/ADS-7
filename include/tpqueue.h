// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
struct ITEM {
     T value;
     ITEM* next;
  };
  ITEM* first, * last;
}
  
  public:
  TPQueue() :head(nullptr), tail(nullptr) {}
  T pop() {
    if (head) {
      ITEM* temp = head;
      head = head->next;
      return temp->data;
    }
    T tmp;
    tmp.prior = 0;
    tmp.ch = ' ';
    return tmp;
  }
  void push(T value) {
    ITEM* tmp = nullptr;
    ITEM* it = create(value);
    ITEM* temp = head;
    if (head && tail) {
       while (temp && (temp->data).prior >= value.prior) {
         tmp = temp;
         temp = temp->next;
       }
       if (temp == head && ((head->data).prior == (it->data).prior)) {
         it->next = head->next;
         head->next = it;
       } else if (temp == head && ((head->data).prior >= (it->data).prior)) {
         it->next = head->next;
         head->next = it;
       } else if (temp == head && ((head->data).prior < (it->data).prior)) {
         it->next = head;
         head = it;
       } else if (!temp) {
         tail->next = it;
         tail = it;
       } else {
         tmp->next = it;
         it->next = temp;
       }
    } else {
      head = create(value);
      tail = head;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
