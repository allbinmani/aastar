#include <Astar.h>

Astar astar(8);

void setup() {  
}

void loop() {
  astar.setStart(0,0);
  astar.setEnd(7,7);
  if ( astar->findPath() ) {
        AstarNode *node = astar->getStart();
    fprintf(stdout, "path:");
    while (node != NULL) {
      Serial.print("%d", node->x);
      Serial.print(":");
      Serial.print("%d", node->y);
      node = node->next;
      if (node != NULL) {
        Serial.print(",");
      }
    }
    Serial.print("\n");

  } else {
    Serial.println("Could not find a path");
  }

}


