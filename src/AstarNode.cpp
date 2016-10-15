/*
 * --------------------------------------------------------------------------
 * THE "BUY-ME-A-BEER LICENSE" (Revision 0.1):
 * <mattias@allbinary.se> wrote this code.  As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you 
 * think my work is worth it (or you think it's worth it anyway), you can buy
 * me a beer in return. I love beer.
 * --------------------------------------------------------------------------
 */
#include <AstarNode.h>

#define _abss(_x) ((x < 0 ? -x : x))

AstarNode::AstarNode() {
  this->id = 0;
  this->x = 0;
  this->y = 0;
  reset();
}

AstarNode::AstarNode(const int x, const int y, const int id) {
  this->id = id;
  this->x = x;
  this->y = y;
  reset();
}

unsigned int AstarNode::getG() {
  return this->G;
}

void AstarNode::updateG(unsigned int newG) {
  this->G = newG;
}

void AstarNode::updateH(unsigned int newH) {
  this->H = newH;
}

void AstarNode::reset() {
  this->G = this->H = 0;
  this->parent = this->next = 0L;
  this->blocked = false;
}

unsigned int AstarNode::getPriority() {
  return this->getF();
}

unsigned int AstarNode::getDistance(AstarNode *other) {
  int dX = _abss(this->x - other->x);
  int dY = _abss(this->y - other->y);
  
  if (dX > dY) {
    return 14 * dY + 10 * (dX - dY);
  }
  return 14 * dX + 10 * (dY - dX);
}
