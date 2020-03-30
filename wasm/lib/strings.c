#include <stdio.h>
#include <emscripten.h>

char * str = "my string variable";
char * getStr(){
  return str;
}

int getNumber(){
  int num = 22;
  if (num < 30) {
    emscripten_log(EM_LOG_WARN, "'num less than 30'");
  }
  // emscripten_debugger();
  return num;
}

int main(){
  printf("WASM Ready\n");
  return 1;
}
