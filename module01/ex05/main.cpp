#include "Harl.hpp"

int main()
{
    Harl harl;

    harl.complain("info");
    harl.complain("error");
    harl.complain("debug");
    harl.complain("warning");
    exit(0);
}