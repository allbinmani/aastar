
#include <AstarNode.h>

int _abss(int _x) {
  if(_x < 0) {
    return -_x;
  }
  return _x;
}

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
