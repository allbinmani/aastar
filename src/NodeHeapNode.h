/*
 * --------------------------------------------------------------------------
 * THE "BUY-ME-A-BEER LICENSE" (Revision 0.1):
 * <mattias@allbinary.se> wrote this code.  As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you 
 * think my work is worth it (or you think it's worth it anyway), you can buy
 * me a beer in return. I love beer.
 * --------------------------------------------------------------------------
 */
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
