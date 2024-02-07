#include <iostream>
#include <opencxx-cli/colors.h>
#include <opencxx-cli/cli.h>

int main() {
    opencxx_cli::colors cliColor;
    opencxx_cli::CLI cli;
    cliColor.printLnColor("Hello World. This is LIGHT", cliColor.fgBlue);
    struct opencxx_cli::CLI::handler handler;
    handler.name = "Hello World";
    cli.help(handler);
    return 0;
}
