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

void ULListStr:: push_back(const std:: string& val){
  if (size_ == 0){
    Item*firstitem = new Item;
    firstitem->last = 0;
    firstitem->first = 0;
    head_ = firstitem;
    tail_ = firstitem;
    tail_->val[tail_->first]=val;
    tail_->last++;
    itemsize++;
    size_++;
  }
  else{
  if(tail->last<ARRSIZE){
    tail->val[tail_->last] = val;
    tail_->last++;
  }
  else{
    Item*ntail =new Item;
    tail_->next = ntail;
    ntail-> prev = tail_;
    tail_ = ntail;
    tail_->first=0;
    tail_->last=0;
    tail_->val[tail_->first]=val;
    tail_->last++;
    itemsize++;
  }
  size_++;
  }
  return;
}

void ULListStr:: push_front(const std::string& val){
if (size_ == 0){
Item* firstitem = new Item;
firstitem->last = 0;
firstitem->first = 0;
head_ = firstitem;
tail_ = firstitem;
head_->val[head_->first]=val;
head_->last++;
itemsize++;
size_++;
}
else{
if(head_->first > 0){
head_->first--;
head_->val[head_->first]=val;
}
else{
Item* nhead = new Item;
nhead->next = head_;
head_->prev = nhead;
head_ = nhead;
head_->first = ARRSIZE-1;
head_->last = ARRSIZE;
head_->val[head_->first]=val;
itemsize++;
}
size_++;
}
return;
}




}

void ULListStr:: pop_back(){
  if(size_==0){
return;
}
else{
if(tail_->last - tail_->first == 1){
if(head_ == tail_){
delete tail_;
head_ = NULL;
tail_ = NULL;
}
else{
tail_ = tail_->prev;
delete tail_->next;
tail_->next = NULL;
}
size_--;
itemsize--;
}
else{
tail_->last--;
size_--;
}
}
return;
}

}

void ULListStr:: pop_front(){
if(size_==0){
return;
}
else{
if(head_->last - head_->first == 1){
if(head_ == tail_){
delete head_;
head_ = NULL;
tail_ = NULL;
}
else{
head_ = head_->next;
delete head_->prev;
head_->prev = NULL;
}
size_--;
itemsize--;
}
else{
head_->first++;
size_--;
}
}
return;
}
}

std::string const & ULListStr:: back() const{

  return tail_->val[tail_->last-1];

}

std::string const & ULListStr::front() const{
  
    return head_->val[head_->first];
    
  }

std::string* ULListStr:: getValAtLoc(size_t loc) const{
if(loc >= size_){
return NULL;
}
else{
Item *current = head_;
size_t count = 0;
while(count + current->last - current->first <= loc){
count = count + current->last - current->first;
current = current->next;
}
return &(current->val[loc - count + current->first]);
}
}

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
