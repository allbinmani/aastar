#ifdef EXAMPLE
#ifdef ARDUINO
#include <Arduino.h>
#define sleep(x) (delay(x*1000))
#else
#include <unistd.h> // for sleep()
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for memset()

//#define DEBUG 1


#ifndef micros
#include <sys/time.h>
// libc stand-in for arduinos micros()
unsigned long micros() {
  static struct timeval tv;
  if(gettimeofday(&tv, NULL) == 0) {
    return tv.tv_usec + tv.tv_sec * 1e6;
  }
  return 0L;
}
#endif
#endif

#define ASTAR_FIELD_SIZE 160

#include <Astar.h>
#include <debugcompat.h>


// Singleton instance of AStar class
Astar *astar;


void setup() {
#ifdef ARDUINO
  Serial.begin(115200);
  srand(micros());
#else
  srand(micros());
#endif
  astar = new Astar(ASTAR_FIELD_SIZE);
  #ifdef ARDUINO
  debugPrintln("free ram after init:");
  debugPrintln((unsigned int)getFreeSram());
  #endif
}

bool done = false;

void loop() {
  const unsigned int siz = astar->getSize();

  debugPrintln("------------ reset");
  astar->reset();

  // Random start
  unsigned int stx = 0,sty=0;//rand() % siz, sty = rand() % siz;
  astar->setStart(stx, sty);

  // Random end
  unsigned int enx = ASTAR_FIELD_SIZE-1;//stx;
  unsigned int eny = ASTAR_FIELD_SIZE-1;//sty;
  while(enx == stx && eny == sty) {
    enx = rand() % siz;
    eny = rand() % siz;
  }
  astar->setEnd(enx, eny);

  debugPrint("- start: ");
  debugPrint(stx);
  debugPrint(",");
  debugPrint(sty);
  //  astar->getStart()->x);
  //  debugPrint(",");
  //  debugPrintln(astar->getStart()->y);
  debugPrint("- end: ");
  debugPrint(enx);
  debugPrint(",");
  debugPrint(eny);
  //  debugPrint(astar->getEnd()->x);
  //  debugPrint(",");
  //  debugPrintln(astar->getEnd()->y);

  // Block some random grid items
  for (short i = 0; i < 1; i++) {
    short a = rand() % siz;
    short b = rand() % siz;
#ifdef DEBUG
    debugPrint("- blocked: ");
    debugPrint(a);
    debugPrint(",");
    debugPrintln((unsigned int)b);
#endif
    astar->markBlocked(a, b, true);
  }

#ifdef DEBUG
  unsigned long st = micros();
#endif
  if ( astar->findPath() ) {
#ifdef DEBUG
    unsigned long et = micros();
    debugPrint("Path found! (took ");
    debugPrint((et - st) / 1000.0f);
    debugPrintln("ms)");
#endif
    AstarNode *node = astar->getStart();
    fprintf(stdout, "path:");
    while (node != NULL) {
      fprintf(stdout,"%d", node->x);
      fprintf(stdout,":");
      fprintf(stdout,"%d", node->y);
      node = node->next;
      if (node != NULL) {
        fprintf(stdout,",");
      }
    }
    fprintf(stdout,"\n");
  } else {
#ifdef DEBUG
    debugPrint("Path not found! (took ");
    unsigned long et = micros();
    debugPrint((et - st) / 1000.0f);
    debugPrintln("ms)");
#endif
    fprintf(stdout, "no path found\n");
  }

  sleep(3);
}

#ifndef ARDUINO
int main(int argc, char **argv) {
  setup();
  //  while(true) {
    loop();
    //  }
    delete astar;
    return 0;
}
#endif
#endif
