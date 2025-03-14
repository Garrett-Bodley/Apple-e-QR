// #include <stdint.h>

// #define TEXT_ON (uint8_t *)0xC051
// #define TEXT_OFF (uint8_t *)0xC050

// #define COLUMN_80_ON (uint8_t *)0xC00D
// #define COLUMN_80_OFF (uint8_t *)0xC00C

// #define DOUBLE_HIRES_ON (uint8_t *)0xC05E
// #define DOUBLE_HIRES_OFF (uint8_t *)0xC05F

// #define STORE_80_ON (uint8_t *)0xC001
// #define STORE_80_OFF (uint8_t *)0xC000

// #define PAGE_2_ON (uint8_t *)0xC055
// #define PAGE_2_OFF (uint8_t *)0xC054

// void apple_sleep(uint8_t seconds) {
//   volatile uint16_t i;
//   for (; seconds > 0; seconds--) {
//     for (i = 0; i < 30000; i++) {
//       // Empty loop for delay
//     }
//   }
// }