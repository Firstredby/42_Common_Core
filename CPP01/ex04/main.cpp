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
	int pos;

	while (getline(oldFile, checkstr))
	{
		pos = checkstr.find(dest);
		while (pos >= 0)
		{
			checkstr.erase(pos, dest.size());
			checkstr.insert(pos, src);
			pos = checkstr.find(dest);
		}
		finalstring.append(checkstr);
	}
	if (finalstring.empty())
		return 0;
	filename.append(".replace");
	std::ofstream newFile(filename.data());
	newFile << finalstring;
	newFile.close();
}