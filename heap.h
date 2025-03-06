#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(size_t m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T>    data_;  // vector data
  size_t            m_;     // m-ary heap
  PComparator       comp_; // comparator function



};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(size_t m, PComparator c)
  : m_(m), comp_(c)
{
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
  while(!empty())
  {
    pop();
  }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return data_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return data_.size();
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }

  std::swap(data_[0], data_[data_.size()-1]);
  data_.pop_back();

  // start at the root and trickle down the new root so heap property is maintained
  size_t current = 0;

  while(true)
  {
    size_t best = current;

    for(size_t i = 0; i < m_; i++)
    {
      size_t childIdx = m_ * current + 1 + i;

      if(childIdx < data_.size() && comp_(data_[childIdx], data_[best]))
      {
        best = childIdx;
      }
    }

    if(best == current)
      break;

    std::swap(data_[current], data_[best]);
    current = best;
  }

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  // push at the end and trickle up
  data_.push_back(item);

  size_t current = data_.size()-1;

  while(current > 0)
  {
    size_t parentIdx = (current - 1) / m_;

    if(comp_(data_[current], data_[parentIdx]))
    {
      std::swap(data_[current], data_[parentIdx]);
      current = parentIdx;
    }
    else
      break;
    
  }
}


#endif

