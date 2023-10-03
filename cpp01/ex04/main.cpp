#include <iostream>
#include <string>
#include <fstream>

std::string replace(std::string line, std::string c1, std::string c2)
{
    std::string res = "";
    size_t i = 0, pos;

    while (i < line.length())
    {
        pos = line.find(c1, i);
        if (pos == std::string::npos)
            return res + line.substr(i);
        res += line.substr(i, pos - i) + c2;
        i = pos + c1.length();
    }
    return res;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Not arguments enough." << std::endl;
        return 1;
    }

    std::string filename(argv[1]);
    std::string c1(argv[2]);
    std::string c2(argv[3]);
    std::string line;

    std::ifstream fIn(filename);
    if (!fIn.is_open())
    {
        std::cout << "Could not open " << filename << std::endl;
        return 1;
    }

    std::ofstream fOut(filename + ".replace");
    if (!fOut.is_open())
    {
        std::cout << "Could not open " << filename << ".replace" << std::endl;
        return 1;
    }

    while (std::getline(fIn, line))
        fOut << replace(line, c1, c2) << std::endl;
    fIn.close();
    fOut.close();
    return 0;
}