/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:55:32 by fabet             #+#    #+#             */
/*   Updated: 2022/10/30 05:46:03 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>
# include <string>

void	error(std::string error)
{
	std::cerr << "Error! " << error << std::endl;
	exit(1);
}

int	main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		filename = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	char			ch;
	std::string		content = "";
	size_t			found;

	if (argc != 4)
		error("Invalid number of arguments.");

	ifs.open(argv[1], std::ifstream::in);
	if (!ifs.is_open())
		error("File does not exist.");
	ofs.open(filename + ".replace", std::ifstream::out);

	while (ifs.get(ch))
		content += ch;

	ifs.close();

	found = content.find(s1);
	while (found != std::string::npos)
	{
		content.erase(found, s1.length());
		content.insert(found, s2);
		found = content.find(s1);
	}
	ofs << content;
	ofs.close();
	return (0);
}
