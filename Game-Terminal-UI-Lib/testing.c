#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include "basic/basic_terminal.h"

void cleanup_and_exit(int sig) {
  clear_terminal();
  terminal_show_cursor();
  set_terminal_buffer_mode();
  exit(0);
}


int main() {
  signal(SIGINT, cleanup_and_exit);
  signal(SIGTERM, cleanup_and_exit);
  
  printf("Hello world\n");

  clear_terminal();
  printf("Terminal cleared!\n");

  set_terminal_raw_mode();
  printf("Raw mode!\n");

  terminal_hide_cursor();
  printf("Hidden cursor\n");

  terminal_show_cursor();
  printf("Show cursor\n");

  set_terminal_buffer_mode();
  printf("Buffer mode!\n");

  return 0;
}