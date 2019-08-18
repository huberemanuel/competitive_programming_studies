#include <iostream>
#include <queue>

// O(N)
std::string solve(std::string url)
{
    std::queue<char> buffer;

    for (size_t i = 0; i < url.size(); ++i) {
        if (url[i] == ' ') {
            buffer.push('%');
            buffer.push('2');
            buffer.push('0');
        }
        if (!buffer.empty()) {
            if (url[i] != ' ') {
                buffer.push(url[i]);
            }
            url[i] = buffer.front();
            buffer.pop();
        }
    }

    return url;
}

int main()
{
    std::string url;
    std::getline(std::cin, url);

    std::cout << solve(url) << std::endl;

    return 0;
}
