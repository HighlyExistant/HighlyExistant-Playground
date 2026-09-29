#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

inline bool key_exists(std::unordered_map<std::string, int> &map, std::string &key) {
    return map.find(key) != map.end();
}

inline std::string new_name_appended(std::string name, int append) {
    name.append(std::to_string(append));
    return name;
}

// Input 
// The first line contains number n (1 ≤ n ≤ 105). The following 
// n lines contain the requests to the system. Each request is a 
// non-empty line, and consists of not more than 32 characters, 
// which are all lowercase Latin letters.
//
// Output
// Print n lines, which are system responses to the requests: OK in 
// case of successful registration, or a prompt with a new name, if 
// the requested name is already taken.
int main(int argc, char const *argv[])
{
    std::string OK_REQUEST = std::string("OK\n");
    std::unordered_map<std::string, int> map = {};
    std::vector<std::string> responses = {};
    int n;
    scanf("%d", &n);

    for (size_t i = 0; i < n; i++)
    {
        // Retrieve all registered names
        std::string obtain_input;
        std::cin >> obtain_input;
        if (key_exists(map, obtain_input))
        {
            // increment the repetition counter
            int &get = map[obtain_input];
            get += 1;
            std::string new_name = new_name_appended(obtain_input, get);
            // Create key to denote repetition in new name
            map[new_name] = 0;
            responses.push_back(new_name);
        } else {
            // Create key to denote repetition
            map[obtain_input] = 0;
            responses.push_back(std::string("OK"));
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        std::cout << responses[i] << '\n';
    }
    return 0;
}
