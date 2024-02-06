#include <iostream>
#include <opencxx-cli/colors.h>

int main() {
    opencxx_cli::CLI cli;
    cli.printLnColor("Hello World. This is LIGHT", cli.fgBlue);
    return 0;
}