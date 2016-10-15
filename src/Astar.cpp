/*
 * --------------------------------------------------------------------------
 * THE "BUY-ME-A-BEER LICENSE" (Revision 0.1):
 * <mattias@allbinary.se> wrote this code.  As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you 
 * think my work is worth it (or you think it's worth it anyway), you can buy
 * me a beer in return. I love beer.
 * --------------------------------------------------------------------------
 */
#include <Astar.h>
#include <NodeHeap.h>
#include <string.h>
#ifdef DEBUG
#include <assert.h>
#endif
#include <debugcompat.h>

#define NODEI(i) ((AstarNode *)( grid) + i)
#define NODEXY(x,y) (NODEI((x%grid_size + (grid_size * y))))

unsigned char Astar::getSize() {
  return this->grid_size;
}

Astar::Astar(const unsigned int grid_size) {
  this->grid_size = grid_size;
  init();
}

Astar::~Astar() {
  if (grid) {
    delete[] grid;
  }
}

void Astar::markBlocked(const unsigned int x, const unsigned int y, const bool is_blocked) {
  NODEXY(x, y)->blocked = is_blocked;
}

bool Astar::findPath() {
  return findPath(this->start_node, this->end_node);
}

bool Astar::findPath(AstarNode *snode, AstarNode *enode) {
  // Basic heuristics 1: cannot move from and to same node
  if (snode->id == enode->id) {
    debugPrint("snode == enode!");
    return false;
  }
  // Basic heuristics 2: cannot move from or to a blocked node
  if (snode->blocked || enode->blocked) {
    debugPrint("start or end blocked!");
    return false;
  }

  static const char neighboursX[] = { -1, 0, 1,  1, 1, 0, -1, -1};   // TL, TM, TR, MR, BR, BM, BL, LM
  static const char neighboursY[] = { -1, -1, -1,  0, 1, 1,  1,  0};
  NodeHeap openSet(this->grid_size * this->grid_size);
  unsigned char closedSet[this->grid_size * this->grid_size];

  openSet.Add(snode);
  memset(&closedSet, 0, sizeof(closedSet));

#ifdef ARDUINO
#ifdef DEBUG
  debugPrintln("free ram before findPath loop:");
  debugPrintln((unsigned int)getFreeSram());
#endif
#endif

  while (openSet.Count() > 0) {
    AstarNode *current = (AstarNode *)(openSet.RemoveFirst());
#ifdef DEBUG
    if (!current) {
      debugPrintln("ERROR: Current node to process was NULL, bailing!");
      return false;
    }
#endif
    closedSet[current->id] = 1;

    if (current == enode) { // Path found?
      this->linkPath();
#ifdef DEBUG
      debugPrint("- path: ");
      AstarNode *c = this->start_node;
      while (c) {
        debugPrint((unsigned int)c->x);
        debugPrint(",");
        debugPrint((unsigned int)c->y);
        //debugPrint(",");
        //debugPrint(c->id);
        debugPrint(":");
        c = c->next;
      }
      debugPrintln("");
#endif
      return true; // Path found
    }

    unsigned short cx = current->x;
    unsigned short cy = current->y;

    AstarNode *neigh;

    for (unsigned int ni = 0; ni < sizeof(neighboursX); ni++) {
      short nx = cx + neighboursX[ni];
      short ny = cy + neighboursY[ni];
      if (nx < 0 || ny < 0 || nx >= this->grid_size || ny >= this->grid_size) {
        continue;
      }
      neigh = NODEXY(nx, ny);
#ifdef DEBUG
      assert(neigh->x == nx && neigh->y == ny);
#endif
      if (!neigh->blocked && closedSet[neigh->id] != 1) {
        unsigned int newG = neigh->getDistance(snode) + current->getG();
        if (newG < neigh->getG() || neigh->getG() == 0) {
          // Update neighbor
          neigh->updateG(newG);
          neigh->updateH(neigh->getDistance(enode));
          neigh->parent = current;

          if (!openSet.Contains(neigh)) {
            openSet.Add(neigh);
          }
        }
      }
    }
  }

  return false; // as far as we can get, or the end node
}

// Back-tracks from end_node and sets 'next' on all nodes in path, to allow forward-traversal
AstarNode* Astar::linkPath() {
  AstarNode *curr = this->end_node;
  AstarNode *parent = curr->parent;
  while (parent) {
    parent->next = curr;
    curr = parent;
    parent = curr->parent;
  }
  return curr; // first node, follow curr->next to traverse path
}

AstarNode* Astar::getStart() {
  return this->start_node;
}

AstarNode* Astar::getEnd() {
  return this->end_node;
}

void Astar::setStart(const int x, const int y) {
  this->start_node = NODEXY(x,y);
}

void Astar::setEnd(const int x, const int y) {
  this->end_node = NODEXY(x,y);
}

void Astar::init() {
  const int siz = this->grid_size * this->grid_size;
  grid = new AstarNode[siz];
  if (!grid) {
#ifdef DEBUG
    debugPrintln("could not allocate grid, most likely out of memory");
#endif
    return;
  }

  for(short i = 0; i < siz; i++) {
    AstarNode *node = NODEI(i);
    node->x = i%this->grid_size;
    node->y = i/this->grid_size;
    node->id =  i;
  }
}

void Astar::reset() {
  for (short i = 0; i < this->grid_size * this->grid_size; i++) {
    NODEI(i)->reset();
  }
}
