#include <CTL/bst.hpp>

namespace CTL {

template <class T>
bool BST<T>::contains(const T element) const {
  TreeNode * temp = this->head;
  while(NULL != temp){
    if(element  == temp->item){
      return true; 
    }
    else if(element  > temp->item){
      temp  = temp->right;
    }
    else temp = temp->left;
  }
  return false;
}


template <class T>
bool BST<T>::isEmpty() const {
  return this->root == NULL;
}

template <class T>
void BST<T>::copy2Array(const T * array, 
  const TreeNode<T> * node,
  size_t  &index) const
{
  if(NULL ==  node) return;
  this->copy2Array(array, node->left, index);
  array[index++]  = node->item;
  this->copy2Array(array, node->right, index);
}

template <class T>
T * BST<T>::toArray() const {
  if(!this-root) return NULL;
  T * array = new T[this->size];
  this->copy2Array(array, this->root, 0);
  return array;
}

template <class T>
size_t BST<T>::getSize() const {
  return this->size;
}

template <class T>
bool  BST<T>::push(const T element){
  if(!this->root) {
    this->root  = new TreeNode(element);
    return true;
  }
  if(element  ==  this->root->item) return false;
  /*
  TreeNode * temp_p = this->root;
  TreeNode * temp   = this->root->value > element ? 
    this->root->right : this->root->left;
  while(temp) {
    temp_p  = temp;
    if(element  ==  temp->item) return false;
    temp    = element > temp->item ? temp->right : temp->left;
  }
  if(element > temp_p->item) {
    temp_p->right = new TreeNode<T>(element);
    temp_p->right->parent = temp_p;
  }
  else {
    temp_p->left  = new TreeNode<T>(element);
    temp_p->left->parent  = temp_p;
  }
  */
  TreeNode * temp   =  this->root;
  while(temp) {
    if(element == temp->item) return false;
    if(element > temp->item) {
      if(temp->right) temp  = temp->right;
      else {
        temp->right = new TreeNode<T>(element);
        temp->right->parent = temp;
      }
    }
    else {
      if(temp->left) temp   = temp->left;
      else {
        temp->left  = new TreeNode<T> (element);
        temp->left->parent  = temp;
      }
    }
  }
  return true;
}

template <class T>
bool BST<T>::pop(){
  if(!this->root) return false;
  return remove(this->root->item);
}

template <class T>
void BST<T>::removeNode(TreeNode<T> * node){
  if(!node) return;
  this->removeNode(node->left);
  this->removeNode(node->right);
  delete node;
  node  = NULL;
}

template <class T>
bool BST<T>::clear(){ 
  this->removeNode(this->root);
}

// need to be discuss
template <class T>
T BST<T>::getMax() const {
  TreeNode<T> * temp  = this->root;
  while(temp){
    if(temp->right) temp  = temp->right;
    else return temp; 
  }
  return NULL;
}

template <class T>
T BST<T>::getMin() const {
  TreeNode<T> * temp  = this->root;
  while(temp) {
    if(temp->left) temp = temp->left;
    else return temp;
  }
  return NULL;
}

}
