#include <stdio.h>
#include <emscripten.h>

// Declare a reusable JS function
EM_JS(void, jsFunction, (int n),{
  console.log("Call from EM_JS: " + n);
});

int main(){
  printf("WASM Ready\n");

  // Call a JS function (eval)
  emscripten_run_script("console.log('Hello from C!')");

  // Call a JS function ASYNC (eval)
  emscripten_async_run_script("console.log('Hello from C - ASYNC!')", 2000);

  // Get return valuer from JS function
  int jsVal = emscripten_run_script_int("getNum()");

  // Get return valuer from JS function
  char * jsValStr = emscripten_run_script_string("getStr()");

  printf("Val from getNum(): %d\n", jsVal);
    printf("Val from getStr(): %s\n", jsValStr);

  // Execute EM_JS jsFunction

  jsFunction(144);

  return 1;
}
