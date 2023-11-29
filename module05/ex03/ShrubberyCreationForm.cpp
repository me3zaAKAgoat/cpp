#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",  145, 137), target("default")
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : AForm(src), target(src.target)
{
	*this = src;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if (this != &rhs)
	{
		this->target = rhs.target;
	}
	return *this;
}

void		ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::NotSignedException();
	else
	{
		std::ofstream outfile(this->target + "_shrubbery");
		outfile << "            ░░░░░░░░░░░░                                ░░░░░░░░░░░░                                ░░░░░░░░                          ░░░░░░░░▒▒░░░░  " << std::endl;
		outfile << "            ░░░░░░░░░░░░░░                              ░░░░░░░░░░░░                              ░░░░░░░░▒▒░░                      ░░░░░░░░░░░░░░░░░░" << std::endl;
		outfile << "            ░░░░░░░░░░░░░░░░                          ░░░░░░░░░░░░░░░░                            ░░░░░░░░░░░░                      ░░░░░░░░░░░░░░░░░░" << std::endl;
		outfile << "            ░░░░░░░░░░░░░░░░░░                        ░░░░░░▒▒▒▒░░░░░░                          ▒▒░░░░▒▒▒▒░░░░░░                    ░░░░░░▒▒▒▒▒▒░░░░░░" << std::endl;
		outfile << "            ░░░░░░░░▒▒░░░░░░░░                        ░░░░░░▒▒▒▒▒▒▒▒░░                        ░░░░░░▒▒▒▒▒▒▒▒░░░░░░                  ░░░░▒▒▒▒░░▒▒▒▒▒▒░░" << std::endl;
		outfile << "        ░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒░░░░                    ░░░░░░▒▒▒▒▒▒▒▒▒▒░░░░                    ░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░                ░░░░▒▒▒▒▒▒▒▒▒▒▒▒░░" << std::endl;
		outfile << "      ░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒                ░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░                ░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒              ░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░" << std::endl;
		outfile << "    ░░▒▒░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒              ░░▒▒░░▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░              ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒              ░░▒▒▒▒▒▒▒▒▒▒▒▒░░░░" << std::endl;
		outfile << "  ░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒          ░░▒▒▒▒░░▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒            ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒              ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << std::endl;
		outfile << "    ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░                ▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒              ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒              ░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << std::endl;
		outfile << "      ▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░                  ▒▒▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒                ░░▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒░░░░▒▒              ▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒" << std::endl;
		outfile << "        ░░▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒░░                      ▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒                    ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒                ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << std::endl;
		outfile << "        ░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░                          ▒▒▒▒▒▒▒▒▒▒▒▒                          ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒                  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒  " << std::endl;
		outfile << "            ░░▒▒▓▓  ▓▓░░                                      ▓▓                                ▒▒▒▒▒▒▒▒▒▒▒▒░░░░▒▒                          ▓▓        " << std::endl;
		outfile << "              ░░▓▓  ▓▓                                        ▓▓                                ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░                          ▓▓        " << std::endl;
		outfile << "                ▓▓▓▓▓▓                                        ▓▓                                    ▒▒▓▓▓▓▒▒                                ▓▓        " << std::endl;
		outfile << "                ▓▓▓▓                                          ▓▓                                      ▓▓▓▓                                  ▓▓        " << std::endl;
		outfile << "                ▓▓                                            ▓▓                                      ▓▓▓▓                                  ▓▓        " << std::endl;
		outfile << "                ▓▓                                            ▓▓                                      ▓▓▓▓                                  ▓▓        " << std::endl;
		outfile << "            ░░▓▓▓▓▓▓                                      ░░▓▓▓▓▓▓                                  ▓▓▓▓██▓▓                              ▓▓▓▓▓▓      " << std::endl;
		outfile << "                ░░                                                                                                                                    " << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm",  145, 137), target(target)
{
}
