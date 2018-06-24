#ifndef STRING_H
#define STRING_H

#include <string>
#include <vector>

class String{

    public:

        // bool's
        static bool isEmpty(const std::string &str);
        static bool isEmptyOrWhiteSpace(const std::string &str);
        static bool compare(const std::string &str1, const std::string str2);
        static bool equals(const std::string &str1, const std::string &str2);

        // string formatting 
        static std::string concat(const std::string &str1, const std::string &str2);
        static std::string copy(const std::string &str);
        static std::string copyTo(const std::string &str);
        static int count(const std::string &str, std::string searchStr); 
        static std::vector<int> find(const std::string &str, std::string search);
        static inline std::vector<int> findAll(std::string &str, std::string search);
        static int findFirst(std::string &str, std::string find);
            static inline int indexOf(std::string &str, std::string find);
        static int findLast(std::string &str, std::string find);
            static inline int lastIndexOf(std::string &str, std::string find);
        static std::string format(std::string formatText, std::string &str);
        static std::string format(std::string formatText, std::string &str1, std::string &str2);
        static std::string format(std::string formatText, std::string &str1, std::string &str2, std::string &str3);
        static std::string format(std::string formatText, std::vector<std::string> &strArr);
        static std::string replace(std::string &str, std::string oldstr, std::string newstr);
        static std::string replaceFirst(std::string &str, std::string oldstr, std::string newstr);
        static std::string replaceLast(std::string &str, std::string oldstr, std::string newstr);
        static std::string replaceHead(std::string &str, int headsize, std::string newstr);
        static std::string replaceTail(std::string &str, int tailsize, std::string newstr);
        static std::string erase(std::string &str, std::string erasestr); 
        static std::string eraseFirst(std::string &str, std::string erasestr); 
        static std::string eraseLast(std::string &str, std::string erasestr); 
        static std::string eraseHead(std::string &str, int headsize); 
        static std::string eraseTail(std::string &str, int tailsize); 
        std::vector<std::string> split(std::string &str, const std::string delimiter);
        static std::vector<char> toCharArr(std::string &str);
        static std::string toUpper(std::string &str);
        static std::string toLower(std::string &str);
        static std::string trim(std::string &str);
        static std::string trimLeft(std::string &str);
        static std::string trimRight(std::string &str);
        static std::string fillLeft(std::string &str, int length, char fill);
            static inline std::string padLeft(std::string &str, int length, char fill);
        static std::string fillRight(std::string &str, int length, char fill);
            static inline std::string padRight(std::string &str, int length, char fill);
        static std::string normPathUnix(std::string &str);
        static std::string normPathWindows(std::string &str);

};

#endif
