
#ifndef __ASTAR_NODE_H__
#define __ASTAR_NODE_H__ 1

#include <NodeHeapNode.h>

class AstarNode : public NodeHeapNode {
public:
  AstarNode();
  AstarNode(const int x, const int y, const int id);
  void reset();
  virtual unsigned int getPriority();
  unsigned int getG();
  void updateG(unsigned int newG);
  void updateH(unsigned int newH);
  virtual int getF() {
    return G + H;
  }

  unsigned int getDistance(AstarNode *other);

  bool blocked;
  short x;
  short y;
  unsigned short id;
  AstarNode *parent;
  AstarNode *next;
private:
  short G;
  short H;
};

#endif
