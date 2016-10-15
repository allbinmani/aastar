/*
 * --------------------------------------------------------------------------
 * THE "BUY-ME-A-BEER LICENSE" (Revision 0.1):
 * <mattias@allbinary.se> wrote this code.  As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you 
 * think my work is worth it (or you think it's worth it anyway), you can buy
 * me a beer in return. I love beer.
 * --------------------------------------------------------------------------
 */
#ifndef __NODEHEAP_H__
#define __NODEHEAP_H__ 1

#include <NodeHeapNode.h>

class NodeHeap {
public:
  NodeHeap(const int maxSize);
  ~NodeHeap();
  void Add(NodeHeapNode *node);
  bool Contains(NodeHeapNode *node);
  NodeHeapNode* RemoveFirst();
  void Update(NodeHeapNode *node);
  unsigned int Count();

private:
  void SortUp(NodeHeapNode *node);
  void SortDown(NodeHeapNode *node);
  void Swap(NodeHeapNode *itemA, NodeHeapNode *itemB);
  unsigned int currentItemCount;
  NodeHeapNode **items;
};

#endif
