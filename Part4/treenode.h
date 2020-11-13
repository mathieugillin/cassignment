#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

// TODO your code for the TreeNode class goes here:
template<typename T>
class TreeNode{
	
public:
	T data;
	unique_ptr<TreeNode<T>> leftChild;
	unique_ptr<TreeNode<T>> rightChild;
	TreeNode<T> * parent;
	
	TreeNode(const T value):data(value),parent(nullptr){
		
	}

	void setLeftChild(TreeNode *child){
		leftChild.reset(child);
		leftChild->parent=this;	
	}
	
	void setRightChild(TreeNode *child){
		rightChild.reset(child);
		rightChild->parent=this;	
	}
	
	void write(ostream & o)const{
    if(leftChild){
      leftChild->write(o);}
    o<< " " << data << " " ;
    if(rightChild){
      rightChild->write(o);}
    }	
};
// do not edit below this line

#endif
