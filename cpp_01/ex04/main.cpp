/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:55:32 by fabet             #+#    #+#             */
/*   Updated: 2022/10/30 06:37:38 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>
# include <string>

static void	error(std::string error)
{
	std::cerr << "Error! " << error << std::endl;
	exit(1);
}

static void readContent(char const **argv, std::string &content)
{
	std::ifstream	ifs;
	std::string		filename = argv[1];
	char			ch;

	ifs.open(filename, std::ifstream::in);
	if (!ifs.is_open())
		error("File does not exist.");
	while (ifs.get(ch))
		content += ch;
	ifs.close();
}


static void	writeNewContent(char const **argv, std::string &content)
{
	std::ofstream	ofs;
	std::string		filename = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	size_t			found;

	ofs.open(filename + ".replace", std::ifstream::out);
	if (!ofs.is_open())
		error("File does not exist.");
	found = content.find(s1);
	while (found != std::string::npos)
	{
		content.erase(found, s1.length());
		content.insert(found, s2);
		found = content.find(s1);
	}
	ofs << content;
	ofs.close();
}

int	main(int argc, char **argv)
{
	std::string		content = "";

	if (argc != 4)
		error("Invalid number of arguments.");
	readContent(argv, content);
	writeNewContent(argv, content);
	return (0);
}
