#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
    OP_ADD,
    OP_CONSTANT,
    OP_DEFINE_GLOBAL,
    OP_DIVIDE,
    OP_EQUAL,
    OP_FALSE,
    OP_GET_GLOBAL,
    OP_GREATER,
    OP_LESS,
    OP_MULTIPLY,
    OP_NIL,
    OP_NEGATE,
    OP_NOT,
    OP_PRINT,
    OP_POP,
    OP_RETURN,
    OP_SET_GLOBAL,
    OP_SUBTRACT,
    OP_TRUE,
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    int* lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);

void writeChunk(Chunk* chunk, uint8_t byte, int line);

int addConstant(Chunk* chunk, Value value);

void freeChunk(Chunk* chunk);

#endif