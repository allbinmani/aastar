/*
 * --------------------------------------------------------------------------
 * THE "BUY-ME-A-BEER LICENSE" (Revision 0.1):
 * <mattias@allbinary.se> wrote this code.  As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you 
 * think my work is worth it (or you think it's worth it anyway), you can buy
 * me a beer in return. I love beer.
 * --------------------------------------------------------------------------
 */
#ifndef __ASTAR_NODE_H__
#define __ASTAR_NODE_H__ 1

#include <NodeHeapNode.h>

class AstarNode : public NodeHeapNode {
public:
  AstarNode();
  AstarNode(const int x, const int y, const int id);
  void reset();
  unsigned int getPriority();
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
