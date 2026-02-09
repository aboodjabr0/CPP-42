#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(std::string str, const std::string& s1, const std::string& s2)
{
	std::string result;
	size_t pos = 0;
	size_t found;
	
	if (s1.empty())
		return str;
	
	while ((found = str.find(s1, pos)) != std::string::npos)
	{
		result.append(str, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(str, pos, str.length() - pos);
	
	return result;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Invalid number of arguments." << std::endl;
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty." << std::endl;
		return 1;
	}
	
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
		return 1;
	}
	
	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not create file '" << outputFilename << "'" << std::endl;
		inputFile.close();
		return 1;
	}
	
	std::string line;
	while (std::getline(inputFile, line))
	{
		outputFile << replaceAll(line, s1, s2);
		if (!inputFile.eof())
			outputFile << std::endl;
	}
	
	inputFile.close();
	outputFile.close();
	
	std::cout << "File processed successfully!" << std::endl;
	std::cout << "Output written to: " << outputFilename << std::endl;
	
	return 0;
}
