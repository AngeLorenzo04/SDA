#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

typedef struct {
    unsigned p; // Peso
    unsigned a; // Altezza
    unsigned l; // Limite
} Cartone;

extern void TorreCartoni(const Cartone* c, size_t n);