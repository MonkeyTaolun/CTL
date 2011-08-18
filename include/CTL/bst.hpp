#ifndef __CTL_BST_HPP__
#define __CTL_BST_HPP__

#include <CTL/collection.hpp>

namespace CTL {

template <class T>
struct TreeNode {
  T   item;
  TreeNode<T>   * left;
  TreeNode<T>   * right;
  TreeNode<T>   * parent;
  TreeNode(const T item) 
    : item(item), left(NULL), right(NULL), parent(NULL) {}
}; 

template <class T>
class BST : public Collection<T> {
public:
  // @overload
  bool    contains(const T element) const;
  // @overload
  bool    isEmpty() const;
  // @overload
  T     * toArray() const;
  // @overload
  size_t  getSize() const;
  // @overload 
  bool    push(const T element);
  // @overload
  bool    pop();
  // @overload
  void    clear();


  T       getMax()  const;
  T       getMin()  const;
  bool    remove(const T element);
  void    inorderTravel() const;
  void    perorderTravel() const;
  void    posorderTravel() const;

  void    printByLevel()  const;
  void    join(BST<T> other);
  
  BST();
  BST(const T * const array, size_t size);

  ~BST();

private:
  void copy2Array(const T * array, const TreeNode<T> * node, size_t &index) const; 
  void removeNode(TreeNode<T> * node);
  
  TreeNode<T> * root;
  size_t        size;
};

} // end of CTL namespace
#endif
