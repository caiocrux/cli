#include "logger.hpp"
#include "cli.hpp"

int main(int argc, char* argv[]) {
    cli::init_logger();
    return cli::handle_cli(argc, argv);
}

