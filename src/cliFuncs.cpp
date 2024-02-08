//  LIGHT
//  cliFuncs.cpp
//  Copyright 2024 - hurbIndustries
//  JPD

#include <iostream>
#include <opencxx-cli/cli.h>
#include "../include/funcs.h"

using namespace std;
using namespace light;

opencxx_cli::CLI cli;

int funcs::sync() {
    cli.info("sync() called");
}

int funcs::fetch() {
    cli.info("fetch() called");
}