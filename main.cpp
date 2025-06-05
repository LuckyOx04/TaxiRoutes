#include "UserIO.h"

int main(int argc, char* argv[]) {
    controller::UserIO userIo;
    if (argc > 1) {
        int menuWidth = std::stoi(argv[1]);
        if (menuWidth < 85) {
            std::cout << "\033[93m";
            std::cout << "Disclaimer: menu width must be at least 85 characters!\n";
            std::cout << "Defaulting to 85 characters.\n";
            std::cout << "\033[0m\n";
            userIo.programInnit();
        } else {
            userIo.programInnit(menuWidth);
        }
    } else {
        userIo.programInnit();
    }
    return 0;
}
