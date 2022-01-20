#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

size_t split(const std::string& txt, std::vector<std::string>& strs, char ch)
{
    size_t pos = txt.find(ch);
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while (pos != std::string::npos) {
        strs.push_back(txt.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;

        pos = txt.find(ch, initialPos);
    }

    // Add the last one
    strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

    return strs.size();
}

    int main()
    {
        std::vector<std::string> v;

        split("This  is a  test", v, ' ');
        dump(cout, v);

        return 0;
    }


    void dump(std::ostream& out, const std::vector<std::string>& v)
    {
        for (size_t i = 0; i < v.size(); ++i) {
            out << '\'' << v[i] << '\'' << ' ';
        }

        out << std::endl;
    }