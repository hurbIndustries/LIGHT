//  LIGHT
//  main.cpp
//  Copyright 2024 - hurbIndustries
//  JPD

#include <iostream>
#include <opencxx-cli/cli.h>
#include "../include/funcs.h"

using namespace std;
using namespace opencxx_cli;
using namespace light;

int main(int argc, char *argv[]) {
    opencxx_cli::CLI cli;
    std::vector<CLI::entryData> entries;
    cli.addEntry("--update", "-u", funcs::update, &entries, false, "Update repository information.");
    //cli.addEntry("--fetch", "-f", funcs::fetch, &entries, "Fetch and install from repository.");

    cli.parse(entries, cli.vectorize(argc, argv));
    return 0;
}
