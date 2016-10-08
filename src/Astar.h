

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
