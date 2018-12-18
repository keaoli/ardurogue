// #include <stdio.h> // Only needed for printf
// #include <assert.h> // Only needed for assert

// Compile with `gcc -Os seaofbitsc` for smallest size
// Compile with `gcc -O3 seaofbitsc` for fastest execution
#ifndef bitwiseops.h
#define bitwiseops.h 

// The type we are going to store the map in
#define MAP_STORAGE unsigned char
// How many bits are in this type, sizeof returns chars, multiply by 8 should give bits
// This does depend on the architecture a little bit, but I'm sure its fine.
// Worst case, just type 32 in here.
#define MAP_BITWIDTH 8
// 32 bits can be indexed from 0 to 31, that is 5 bits to represent the value 31.
// 0x1F is the mask for that, in binary, 11111. Bitshift is the amount of bits it uses, 5.
#define MAP_BITMASK 0x7
#define MAP_BITSHIFT 3

// Dimensions of the map, you should be able to just change these and it'll work.
// Try keep them divisible by 8 or something. Because we need to make ints out of this
#define MAP_X 64
#define MAP_Y 64

// The amount of bits required to store the X and Y coords. 64, 0 to 63, fits in 6 bits.
#define MAP_X_BITWIDTH 6 // Not needed
#define MAP_Y_BITWIDTH 6

// The map. Its dimensions are 64 * 64 bits in this case.
// So we divide 64*64, by the amount of bits in our MAP_STORAGE type
// That is 8 for a char, and 32 for an int.
 

MAP_STORAGE dmap[(MAP_X * MAP_Y) / MAP_BITWIDTH];

// x and y should be between 0 and 63
// their values are not checked, for efficiency
// please do the checking elsewhere
// the output is undefined for invalid values
void setMapBit(const unsigned char x, const unsigned char y) {
    const unsigned short mapByte = (x << MAP_Y_BITWIDTH | y) >> MAP_BITSHIFT;
    const unsigned char mapBit = y & MAP_BITMASK;
    // printf("setting map int: %i, map bit: %i\n", mapByte, mapBit);
    dmap[mapByte] |= 1 << mapBit;
}

void clearMapBit(const unsigned char x, const unsigned char y) {
    const unsigned short mapByte = (x << MAP_Y_BITWIDTH | y) >> MAP_BITSHIFT;
    const unsigned char mapBit = y & MAP_BITMASK;
    // printf("unsetting map int: %i, map bit: %i\n", mapByte, mapBit);
    dmap[mapByte] &= ~(1 << mapBit);
}

int getMapBit(const unsigned char x, const unsigned char y) {
    const unsigned short mapByte = (x << MAP_Y_BITWIDTH | y) >> MAP_BITSHIFT;
    const unsigned char mapBit = y & MAP_BITMASK;
    // printf("checking map int: %i, map bit: %i\n", mapByte, mapBit);
    return dmap[mapByte] & (1 << mapBit);
}

#endif
