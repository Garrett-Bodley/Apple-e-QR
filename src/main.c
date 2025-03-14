#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define FIRST_SCREEN_THIRD (char *)0x400
#define SECOND_SCREEN_THIRD (char *)0x428
#define LAST_SCREEN_THIRD (char *)0x450
#define SCREEN_ROW_OFFSET 0x80
#define LEFT_PAD 8
#define TOP_PAD 1
#define MATRIX_SIZE 21
#define MATRIX_MEM_SIZE 441 // 21 * 21

extern uint8_t rom[];
extern size_t matrix_count;

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

void render_qr(uint8_t *qr) {
  int i;
  int row;
  char *row_pointer;

  clear_text_screen();
  row_pointer = (char *)FIRST_SCREEN_THIRD;
  for (i = 0; i < MATRIX_SIZE; i++) {
    row = i + TOP_PAD;
    if (row < 8) {
      row_pointer = FIRST_SCREEN_THIRD;
    } else if (row < 16) {
      row_pointer = SECOND_SCREEN_THIRD;
    } else {
      row_pointer = LAST_SCREEN_THIRD;
    }
    memcpy(row_pointer + (row % 8) * SCREEN_ROW_OFFSET + LEFT_PAD, &qr[i * 21],
           21);
  }
}

void apple_sleep(uint8_t interval){
  volatile uint16_t i;
  for (; interval > 0; interval--) {
      for (i = 0; i < 30000; i++) {
          // Empty loop for delay
      }
  }
}

int main(void) {
  int i = 0;
  while (true) {
    render_qr(&rom[i * MATRIX_MEM_SIZE]);
    apple_sleep(5);
    i += 1;
    i %= matrix_count;
  }
  return 0;
}