

#ifndef __NODEHEAPNODE_H__
#define __NODEHEAPNODE_H__ 1

class NodeHeapNode {
public:
  NodeHeapNode() {heapIndex=0;};
  ~NodeHeapNode() {};
  inline virtual unsigned int getPriority() { return 0; };
  unsigned int heapIndex;
};

#endif
