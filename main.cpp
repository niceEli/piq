#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

int main(const int argc, char *argv[argc]) {
  std::vector<std::string> args;

  if (argc > 1) {
    for (int i = 1; i < argc; ++i) {
      args.emplace_back(argv[i]);
    }
  } else {
    std::string line;
    while (std::getline(std::cin, line)) {
      args.emplace_back(line);
    }
  }

  for (const auto &arg: args) {
    if (!std::filesystem::exists(arg)) {
      std::cerr << "Error: File does not exist - " << arg << std::endl;
      continue;
    }
    if (std::ifstream file(arg); file.good()) {
      std::string sLine;
      getline(file, sLine);
      std::cout << sLine << '\n';
    }
  }
}