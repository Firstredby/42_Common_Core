#include <iostream>
#include <fstream>

int	main(int ac, char** av)
{
	if (ac != 4)
		return 0;
	std::string checkstr;
	std::string finalstring;
	std::string filename = av[1];
	std::string dest = av[2];
	std::string src = av[3];
	std::ifstream oldFile(filename.data());
	size_t pos;

	while (std::getline(oldFile, checkstr))
	{
		pos = checkstr.find(dest);
		while (pos != std::string::npos)
		{
			checkstr.erase(pos, dest.size());
			checkstr.insert(pos, src);
			pos = checkstr.find(dest, pos + src.size());
		}
		finalstring.append(checkstr + "\n");
	}
	if (finalstring.empty())
		return 0;
	finalstring.erase(finalstring.size() - 1);
	filename.append(".replace");
	std::ofstream newFile(filename.data());
	newFile << finalstring;
	newFile.close();
}