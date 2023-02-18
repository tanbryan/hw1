#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::push_back(const std::string &val){
  if(empty()){ 
    Item* newhead = new Item();
    newhead->val[newhead->first] = val;
    newhead->last++;
    head_ = newhead;
    tail_ = head_;
    size_++;
  }
  else {
    Item* iterator = tail_;
    while(iterator->last == ARRSIZE){ 
      iterator = iterator->next;
        if(iterator == nullptr){ 
          Item* newitem = new Item();
          newitem->val[newitem->first] = val;
          newitem->last++;
          newitem->prev = tail_;
          tail_->next = newitem;
          tail_ = newitem;
          size_++;
          return;
        }
    }
    iterator->val[iterator->last] = val;
    iterator->last++;
    size_++;
  }
}




void ULListStr::push_front(const std::string &val) {
  if (empty()) {
    Item* newhead = new Item();
    newhead->val[ARRSIZE - 1] = val;
    newhead->first = ARRSIZE - 1;
    newhead->last = ARRSIZE;
    head_ = newhead;
    tail_ = head_;
    size_++;
  } else {
    Item* item = head_;
    while (item->first == 0 && item->next != nullptr) {
      item = item->next;
    }
    if (item->first == 0) {
      Item* newitem = new Item();
      newitem->val[ARRSIZE - 1] = val;
      newitem->first = ARRSIZE - 1;
      newitem->last = ARRSIZE;
      newitem->next = head_;
      head_->prev = newitem;
      head_ = newitem;
    } else {
      item->first--;
      item->val[item->first] = val;
    }
    size_++;
  }
}

void ULListStr::pop_back(){
  if(!empty()){ 
    Item* iterator = tail_;
    while(iterator->last - iterator->first == 1){ 
      if(head_ == tail_){ 
        delete tail_;
        tail_ = nullptr;
        head_ = tail_;
      }
      else{
        Item* temp = iterator->prev;
        temp->next = nullptr;
        delete temp->next;
        tail_ = temp;
      }
      size_--;
      return;
    }
    iterator->last--;
    size_--;
  }
}

void ULListStr::pop_front() {
  if (!empty()) {
    if (head_->last - 1 == head_->first) {
      if (head_ == tail_) {
        delete head_;
        head_ = nullptr;
        tail_ = head_;
        size_ = 0;
      } else {
        Item* temp = head_;
        head_ = head_->next;
        head_->prev = nullptr;
        delete temp;
        size_--;
    }
    } 
    else {
      head_->first++;
      size_--;
    }
  }
}



std::string const & ULListStr:: back() const{

  return tail_->val[tail_->last-1];

}

std::string const & ULListStr::front() const{
  
  return head_->val[head_->first];
    
}

std::string* ULListStr::getValAtLoc(size_t loc) const{ 
  if (loc >= size_) {
  return nullptr;
  }
  Item* iterator = head_;
  size_t itemSize = head_->first;
  size_t i = 0;
  while (i < loc) {
    if (itemSize == head_->last-1) {
      iterator = iterator->next;
      itemSize = iterator->first;
    } 
    else {
    itemSize++;
    }
    i++;
  }
return &iterator->val[itemSize];
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

