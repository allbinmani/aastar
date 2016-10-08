
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
