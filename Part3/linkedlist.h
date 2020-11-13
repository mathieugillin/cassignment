#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <iostream>
#include <string>
#include <initializer_list>

using namespace std;
// TODO your code goes here:
template<typename T>
class LinkedList{
  private:
    int count;
    Node<T> *head;
    Node<T> *tail;
    NodeIterator<T> currentPointer;
public:
//
LinkedList(initializer_list<T> l): count(0),head(nullptr),tail(nullptr){
  for(const T &item:l){
      push_back(item);
  }
}

LinkedList()
    : count(0),head(nullptr),tail(nullptr){
}
//



//
NodeIterator<T> &insert(NodeIterator<T> &ittr,const T &elem){
    T oldElem = ittr.current->data;
    ittr.current->data = elem;
    Node<T> *newN = new Node<T>(oldElem);
    newN->next = ittr.current->next;
    newN->previous = ittr.current;
    if(tail==ittr.current){
        tail = newN;
    }else{
      ittr.current->next->previous = newN;
    }
    ++count;
    ittr.current->next = newN;
    return ittr;
}
//
NodeIterator<T> &erase( NodeIterator<T> &ittr){

  Node<T> *nodeToRemove = ittr.current;
  if(head==ittr.current){
    head = nodeToRemove->next;
    head->previous = nullptr;
  }else if(tail==ittr.current){
    tail = nodeToRemove->previous;
    tail->next = nullptr;
  }
  else{
    (nodeToRemove->next)->previous = nodeToRemove->previous;
    (nodeToRemove->previous)->next = nodeToRemove->next;
  }
    delete nodeToRemove;
    return ittr;
    ++ittr;
    --count;
    
    
}
//
T & front() const{
  return head->data;
}

//
void push_front(const T &ele){
  Node<T> *newN = new Node<T>(ele);
  if(count>0){
    newN->next = head;
    head->previous = newN;
  }else{
    tail = newN;
  }
  ++count;
  head = newN;
  
}
//
void push_back(const T &ele){
  Node<T> *newN = new Node<T>(ele);
  if(count>0){
    newN->previous = tail;
    tail->next = newN;
  }else{
    head = newN;
  }
  ++count;
  tail = newN;
}
//
//
 NodeIterator<T> &begin(){
  currentPointer.current = head;
  return currentPointer;
}
//
NodeIterator<T> &end(){
  currentPointer.current = tail->next;
  return currentPointer;
}

T & back() const{
  return tail->data;
}
//
int size() const{
  return count;
}

//

~LinkedList(){
  Node<T> *current = head;
  while( current != nullptr ) {
    current = next;

    Node<T> *next = current->next;
    
    delete current;
  }
  //
  head = nullptr;
}

void reverse()
    {
        
        currentPointer = head;
        Node *prev = NULL, *next = NULL;
 
        while (currentPointer != NULL) {
            next = currentPointer->next;
            currentPointer->next = prev;
            prev = currentPointer;
            currentPointer = next;
        }
        head = prev;
    }

};
// do not edit below this line

#endif
