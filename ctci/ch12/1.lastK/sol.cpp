#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    int k;
    std::cin >> k;

    std::string buffer;
    std::vector<std::string> lines;

    std::ifstream f("file.txt");

    if (f.is_open()) {
        while (!f.eof()) {
            getline(f, buffer);
            lines.push_back(buffer);
        }
    }

    for (int i = lines.size() - k - 1; i < lines.size(); ++i) {
        std::cout << lines[i] << std::endl;
    }

    f.close();

    return 0;
}
