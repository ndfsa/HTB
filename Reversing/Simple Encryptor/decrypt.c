#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // data the program needs
  FILE *input;
  long payload_size;
  int seed;

  unsigned char *payload;
  unsigned char temp;
  unsigned char mask;
  int offset;

  int i;

  // open the file
  input = fopen("./flag.enc", "rb");

  // find the size of the stream
  fseek(input, 0, SEEK_END);
  payload_size = ftell(input);
  fseek(input, 0, SEEK_SET);

  // allocate space on the heap
  payload = malloc(payload_size + 1);

  // read the first 4 bytes and put it into seed
  fread(&seed, 1, 4, input);

  // read the rest, without 4 bytes
  fread(payload, 1, payload_size - 4, input);

  // seed is the time the program was first launched
  srand(seed);

  for (i = 0; i < payload_size - 4; ++i) {
    mask = rand();
    offset = rand() & 7;

    temp = *(payload + i);
    // first undo offset reordering
    temp = (temp >> offset) | (temp << (8 - offset));

    // undo xor mask
    temp = temp ^ mask;

    // store unencrypted byte
    *(payload + i) = temp;
  }

  // print final string
  printf("%s\n", payload);
  return 0;
}
