/*
 * --------------------------------------------------------------------------
 * THE "BUY-ME-A-BEER LICENSE" (Revision 0.1):
 * <mattias@allbinary.se> wrote this code.  As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you 
 * think my work is worth it (or you think it's worth it anyway), you can buy
 * me a beer in return. I love beer.
 * --------------------------------------------------------------------------
 */
#ifndef __ASTAR_H__
#define __ASTAR_H__ 1

#include <AstarNode.h>

class Astar {
public:
  Astar(const unsigned int grid_size);
  ~Astar();
  void markBlocked(const unsigned int x, const unsigned int y, const bool is_blocked);
  void setStart(const int x, const int y);
  void setEnd(const int x, const int y);
  AstarNode* getStart();
  AstarNode* getEnd();
  bool findPath();
  bool findPath(AstarNode * start_node, AstarNode * end_node);
  void reset();
  unsigned char getSize();
private:
  AstarNode *linkPath();
  void init();
  unsigned char grid_size;
  AstarNode  *grid;
  AstarNode  *start_node;
  AstarNode  *end_node;
};

#endif
