#include <stdio.h>
#include <termios.h>
#include <unistd.h>

static struct termios original_termios;
static int raw_mode_enabled = 0;


void clear_terminal() {
  printf("\033[2J\033[H");
  fflush(stdout);
}

void set_terminal_raw_mode() {
  tcgetattr(STDIN_FILENO, &original_termios);

  struct termios raw = original_termios;
  raw.c_lflag &= ~(ICANON | ECHO);

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
  raw_mode_enabled = 1;
}

void set_terminal_buffer_mode() {
  if (raw_mode_enabled) {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios);
    raw_mode_enabled = 0;
  }
}

void terminal_hide_cursor(void) {
  printf("\033[?25l");
  fflush(stdout);
}

void terminal_show_cursor(void) {
  printf("\033[?25h");
  fflush(stdout);
}