#include <iostream>
#include <fstream>

void	ft_replace(std::ifstream &infile, std::ofstream &outfile, std::string s1, std::string s2)
{
	std::string line;

	while (std::getline(infile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, std::string(s1).length());
			line.insert(pos, std::string(s2));
			pos += std::string(s2).length();
		}
		outfile << line;
		if (!infile.eof())
			outfile << std::endl;
	}
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		exit(1);
	}
	std::ifstream infile(av[1]);
	if (!infile.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		exit(1);
	}
	std::ofstream outfile((av[1] + std::string(".replace")).c_str());
	if (!outfile.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		exit(1);
	}
	ft_replace(infile, outfile, std::string(av[2]), std::string(av[3]));
	infile.close();
	outfile.close();
	exit(0);
}