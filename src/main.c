#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define FIRST_SCREEN_THIRD (char *)0x400
#define SECOND_SCREEN_THIRD (char *)0x428
#define LAST_SCREEN_THIRD (char *)0x450
#define SCREEN_ROW_OFFSET 0x80

extern uint8_t rom[];
extern size_t matrix_width;
extern size_t matrix_height;

void clear_text_screen() {
  char *one = (char *)0x400;
  char *two = (char *)0x480;
  char *three = (char *)0x500;
  char *four = (char *)0x580;
  char *five = (char *)0x600;
  char *six = (char *)0x680;
  char *seven = (char *)0x700;
  char *eight = (char *)0x780;

  memset(one, 0x20, 120);
  memset(two, 0x20, 120);
  memset(three, 0x20, 120);
  memset(four, 0x20, 120);
  memset(five, 0x20, 120);
  memset(six, 0x20, 120);
  memset(seven, 0x20, 120);
  memset(eight, 0x20, 120);
}

int main(void) {
  int i;
  char *row_pointer;

  clear_text_screen();
  row_pointer = (char *)FIRST_SCREEN_THIRD;
  for (i = 0; i < matrix_height; i++) {
    if (i < 8) {
      row_pointer = FIRST_SCREEN_THIRD;
    } else if (i < 16) {
      row_pointer = SECOND_SCREEN_THIRD;
    } else {
      row_pointer = LAST_SCREEN_THIRD;
    }
    memcpy(row_pointer + (i % 8) * SCREEN_ROW_OFFSET, &rom[i * matrix_width],
           matrix_width);
  }
  while (true)
    ;
  return 0;
}