#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
   
{
        while (av[1])
       
{
            for (int i = 0; av[1][i]; i++)
                std::cout << (char)std::toupper(av[1][i]);
            av++;
        }
    }
    std::cout << std::endl;
    exit(0);
}