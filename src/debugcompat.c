#ifdef DEBUG
#include <stdio.h>

#ifdef ARDUINO

uint16_t getFreeSram() {
  uint8_t newVariable;
  // heap is empty, use bss as start memory address
  if ((uint16_t)__brkval == 0)
    return (((uint16_t)&newVariable) - ((uint16_t)&__bss_end));
  // use heap end as the start of the memory address
  else
    return (((uint16_t)&newVariable) - ((uint16_t)__brkval));
};
#define debugPrint(x) (Serial.print(x))
#define debugPrintln(x) (Serial.println(x))

#else


void debugPrint(const char *x) {
  fprintf(stderr, "%s", x);
}
void debugPrint(const float x) {
  fprintf(stderr, "%f", x);
}
void debugPrintln(const char *x) {
  fprintf(stderr, "%s\n", x);
}
void debugPrintln(const unsigned int x) {
  fprintf(stderr, "%d\n", x);
}
//void debugPrintln(const float x) {
//  fprintf(stderr, "%f\n", x);
//}


#endif

#endif
