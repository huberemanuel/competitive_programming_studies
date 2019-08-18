#include <iostream>
#include <map>

std::map<char, int> make_letters_count(std::string a)
{
    std::map<char, int> a_letters;
    for (char c : a) {
        if (a_letters.find(c) == a_letters.end()) {
            a_letters[c] = 1;
        }
        else {
            ++a_letters[c];
        }
    }
    return a_letters;
}

// O(n*log n)
bool solve1(std::string a, std::string b)
{
    if (a.size() != b.size()) return false;
    auto a_letters = make_letters_count(a);
    auto b_letters = make_letters_count(b);
    if (a.size() != b.size()) return false;

    for (auto it = a_letters.begin(); it != a_letters.end(); ++it) {
        if (b_letters.find(it->first) == b_letters.end() ||
            it->second != b_letters[it->first]) {
            return false;
        }
    }

    return true;
}

// O(n)
bool solve2(std::string a, std::string b)
{
    if (a.size() != b.size()) return false;

    int ascii_chars[128] = {0};

    for (char c : a) {
        ++ascii_chars[c];
    }

    for (char c : b) {
        --ascii_chars[c];
        if (ascii_chars[c] < 0) {
            return false;
        }
    }

    return true;
}

int main() {

    std::string a, b;

    std::cin >> a >> b;

    if (solve2(a, b)) {
        std::cout << "Yes\n";
    }
    else {
        std::cout << "No\n";
    }

    return 0;
}
