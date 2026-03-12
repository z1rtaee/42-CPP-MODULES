#include <iostream>
#include <fstream>
#include <string>

std::string replaceOccurrences(const std::string& content, const std::string& s1, const std::string& s2)
{
    if (s1.empty())
        return content;
    
    std::string result;
    size_t pos = 0;
    size_t found;
    
    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        // Append the part before the found string
        result += content.substr(pos, found - pos);
        // Append the replacement string
        result += s2;
        // Move position past the found string
        pos = found + s1.length();
    }
    
    // Append the remaining part of the string
    result += content.substr(pos);
    
    return result;
}

std::string readFileContent(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "\e[1;35mError:\e[0m Could not open file '" << filename << "'" << std::endl;
        return "";
    }
    
    std::string content;
    std::string line;
    
    while (std::getline(file, line))
    {
        content += line;
        if (!file.eof())
            content += "\n";
    }
    
    file.close();
    return content;
}

bool writeFileContent(const std::string& filename, const std::string& content)
{
    std::ofstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "\e[1;35mError:\e[0m Could not create file '" << filename << "'" << std::endl;
        return false;
    }
    
    file << content;
    file.close();
    
    return true;
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "\e[1;35mUsage: \e[0m" << argv[0] << "\e[1;37m <filename> <s1> <s2>\e[1;37m" << std::endl;
        std::cerr << "\e[1;35m  filename: \e[0mfile to process" << std::endl;
        std::cerr << "\e[1;35m  s1: \e[0mstring to find" << std::endl; 
        std::cerr << "\e[1;35m  s2: \e[0mstring to replace with" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (filename.empty())
    {
        std::cerr << "\e[1;35mError:\e[0m Filename cannot be empty" << std::endl;
        return 1;
    }
    
    // Read the original file
    std::cout << "\e[1;35mReading file: \e[1;35m" << filename << std::endl;
    std::string content = readFileContent(filename);
    
    if (content.empty())
    {
        // Check if file exists but is empty vs file doesn't exist
        std::ifstream testFile(filename.c_str());
        if (!testFile.is_open())
        {
            return 1; // Error already printed by readFileContent
        }
        testFile.close();
        std::cout << "\e[1;35mWarning: \e[0mFile is empty" << std::endl;
    }
    
    // Perform replacement
    std::cout << "\e[1;35mReplacing \e[0m'" << s1 << "' \e[1;35mwith \e[1;35m'" << s2 << "'" << std::endl;
    std::string newContent = replaceOccurrences(content, s1, s2);
    
    // Create output filename
    std::string outputFilename = filename + ".replace";
    
    // Write the new file
    std::cout << "\e[1;35mWriting to: \e[0m" << outputFilename << std::endl;
    if (!writeFileContent(outputFilename, newContent))
    {
        return 1;
    }
    
    std::cout << "\e[1;35mFile replacement completed successfully!\e[1;35m" << std::endl;
    
    return 0;
}