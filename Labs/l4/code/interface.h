#ifndef INTERFACE_H
#define INTERFACE_H
#define STRING_MAX_LENGTH 100
#define _GNU_SOURCE
#include "api.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void user();
void cli(int argc,char *argv[]);
#endif