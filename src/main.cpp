#include <iostream>
#include <opencxx-cli/cli.h>
#include "../include/funcs.h"

using namespace std;
using namespace opencxx_cli;
using namespace light;

int main(int argc, char *argv[]) {
    opencxx_cli::CLI cli;
    std::vector<CLI::entryData> entries;
    cli.addEntry("--sync", "-s", funcs::sync, &entries);
    cli.addEntry("--fetch", "-f", funcs::fetch, &entries);

    cli.parse(entries, cli.vectorize(argc, argv));
    return 0;
}
