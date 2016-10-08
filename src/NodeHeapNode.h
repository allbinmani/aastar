

#ifndef __NODEHEAPNODE_H__
#define __NODEHEAPNODE_H__ 1

class NodeHeapNode {
public:
  NodeHeapNode() {heapIndex=0;};
  virtual ~NodeHeapNode() {};
  virtual unsigned int getPriority() = 0;
  unsigned int heapIndex;
};

#endif
