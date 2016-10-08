
#include <NodeHeap.h>
#include <stdlib.h>

NodeHeap::NodeHeap(const int maxSize) {
  items = (NodeHeapNode **)(malloc(maxSize * sizeof(NodeHeapNode*)));
  currentItemCount = 0;
}

NodeHeap::~NodeHeap() {
  if (items) {
    free(items);
    items = 0L;
  }
}

unsigned int NodeHeap::Count() {
  return currentItemCount;
}

void NodeHeap::Update(NodeHeapNode *node) {
  SortUp(node);
  SortDown(node);
}

bool NodeHeap::Contains(NodeHeapNode *node) {
  return currentItemCount > node->heapIndex &&
    node == items[node->heapIndex];
}

void NodeHeap::Add(NodeHeapNode *node) {
  node->heapIndex = currentItemCount;
  items[currentItemCount] = node;
  SortUp(node);
  currentItemCount++;
}

NodeHeapNode* NodeHeap::RemoveFirst() {
  NodeHeapNode* first = items[0];
  currentItemCount--;
  items[0] = items[currentItemCount];
  items[0]->heapIndex = 0;
  SortDown(items[0]);
  return first;
}

void NodeHeap::SortDown(NodeHeapNode *node) {
  while (true) {
    unsigned int childLeft = node->heapIndex * 2 + 1;
    unsigned int childRight = node->heapIndex * 2 + 2;
    unsigned int swapIndex;
    if (childLeft < currentItemCount) {
      swapIndex = childLeft;
      if (childRight < currentItemCount) {
        if (items[childLeft]->getPriority() < items[childRight]->getPriority()) {
          swapIndex = childRight;
        }
      }
      if (node->getPriority() < items[swapIndex]->getPriority()) {
        Swap(node, items[swapIndex]);
      } else {
        break;
      }
    } else {
      break;
    }
  }
}

void NodeHeap::SortUp(NodeHeapNode *node) {
  int parentIndex = (node->heapIndex - 1) / 2;
  while (node->heapIndex != 0) {
    NodeHeapNode *parentItem = items[parentIndex];
    if (parentItem->getPriority() < node->getPriority() ) {
      Swap(node, parentItem);
    }
    else {
      break;
    }
    parentIndex = (node->heapIndex - 1) / 2;
  }
}

inline void NodeHeap::Swap(NodeHeapNode *itemA, NodeHeapNode *itemB) {
  items[itemA->heapIndex] = itemB;
  items[itemB->heapIndex] = itemA;
  int tmp = itemA->heapIndex;
  itemA->heapIndex = itemB->heapIndex;
  itemB->heapIndex = tmp;
}
