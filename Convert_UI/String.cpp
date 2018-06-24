#include "String.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <regex>

// bool's
bool String::isEmpty(const std::string &str) {
    return str.empty();
}

bool String::isEmptyOrWhiteSpace(const std::string &str) {
    if(str.empty()){
    return true;
    }
    else{
        if(str.find_first_not_of(' ') != std::string::npos){
            return false;
        }
        return true;
    }
}

bool String::compare(const std::string &str1, const std::string str2) {
    if(str1.compare(str2) == 0)
        return true;
    else false;
}

bool String::equals(const std::string &str1, const std::string &str2) {
    if(str1.compare(str2) == 0)
        return true;
    else false;
}

// string formating 
std::string String::concat(const std::string &str1, const std::string &str2) {
    return str1 + str2; 
}

std::string String::copy(const std::string &str){}
std::string String::copyTo(const std::string &str){}

int String::count(const std::string &str, std::string searchStr) {
    std::vector<int> intArr = String::find(str, searchStr); 
    return intArr.size(); 
}

std::vector<int> String::find(const std::string &str, std::string search){
    std::vector<int> vec;

    std::size_t pos = str.find(search);
    while(pos != std::string::npos)
    {
        vec.push_back(pos);
        pos = str.find(search,pos+1);
    }
    return vec;
}

inline std::vector<int> String::findAll(std::string &str, std::string search){
    String::find(str, search);
}

int String::findFirst(std::string &str ,std::string find){
    std::size_t pos = str.find(find);
    if(pos != std::string::npos){
        int i = static_cast<int>(pos);
        return i;
    }
}

inline int indexOf(std::string &str, std::string find){
    String::findFirst(str, find);
}

int String::findLast(std::string &str, std::string find){
    std::size_t pos = str.rfind(find);
    if(pos != std::string::npos){
        int i = static_cast<int>(pos);
        return i;
    }
}
    
inline int String::lastIndexOf(std::string &str, std::string find){
    String::findLast(str, find);
}

std::string String::format(std::string formatText, std::string &str){
    formatText = String::replaceFirst(formatText, "{0}", str); 
    return formatText; 
}

std::string String::format(std::string formatText, std::string &str1, std::string &str2){
    formatText = String::replaceFirst(formatText, "{0}", str1); 
    formatText = String::replaceFirst(formatText, "{1}", str2); 
    return formatText; 
}

std::string String::format(std::string formatText, std::string &str1, std::string &str2, std::string &str3){
    formatText = String::replaceFirst(formatText, "{0}", str1); 
    formatText = String::replaceFirst(formatText, "{1}", str2); 
    formatText = String::replaceFirst(formatText, "{2}", str3); 
    return formatText; 
}

std::string String::format(std::string formatText, std::vector<std::string> &strArr) {
    try {
        std::vector<std::string> parameter; 
        std::regex re("\\{[0-9]{1,3}\\}");
        std::sregex_iterator iter(formatText.begin(), formatText.end(), re); 
        std::sregex_iterator end; 

        while (iter != end) {
            for (int i = 0; i < iter->size(); i++) {
                parameter.push_back((*iter)[i]);
            }
            iter++; 
        }
        for (int i = 0; i < parameter.size(); i++){
            if (i < strArr.size()) {
                formatText = String::replaceFirst(formatText, parameter[i], strArr[i]);
            }
            else {
                break;
            }
        }
        return formatText; 
    }
    catch (std::exception ex) {
        std::cout << ex.what() << std::endl;
    }
}

std::string String::replace(std::string &str, std::string oldstr, std::string newstr){
    std::size_t pos = str.find(oldstr);
    while(pos != std::string::npos)
    {
        str.replace(pos, oldstr.length(), newstr);
        pos = str.find(oldstr,pos+1);
    }
    return str;
}

std::string String::replaceFirst(std::string &str, std::string oldstr, std::string newstr){
    std::size_t pos = str.find(oldstr);
    if(pos != std::string::npos){
        str.replace(pos, oldstr.length(), newstr);
    }
    return str;
}

std::string String::replaceLast(std::string &str, std::string oldstr, std::string newstr){
    std::size_t pos = str.rfind(oldstr);
    if(pos != std::string::npos){
        str.replace(pos, oldstr.length(), newstr);
    }
    return str;
}

std::string String::replaceHead(std::string &str, int headsize, std::string newstr){
    str.erase(0,headsize);
    str = newstr + str;
    return str;
}

std::string String::replaceTail(std::string &str, int tailsize, std::string newstr){
    str.erase(str.end()-tailsize, str.end());
    str += newstr;
    return str;
}

std::string String::erase(std::string &str, std::string erasestr){
    std::string::size_type n = erasestr.length();
    for (std::string::size_type i = str.find(erasestr); i != std::string::npos; 
        i = str.find(erasestr)) 
    {
        str.erase(i, n);    
    }
    return str;
} 

std::string String::eraseFirst(std::string &str, std::string erasestr){
    std::size_t pos = str.find(erasestr);
    if(pos != std::string::npos){
        str.erase(pos, erasestr.length());
    }
    return str;
} 

std::string String::eraseLast(std::string &str, std::string erasestr){
    std::size_t pos = str.rfind(erasestr);
    if(pos != std::string::npos){
        str.erase(pos, erasestr.length());
    }
    return str;
} 

std::string String::eraseHead(std::string &str, int headsize){
    str.erase(0,headsize);
    return str;
}

std::string String::eraseTail(std::string &str, int tailsize){
    str.erase(str.end()-tailsize, str.end());
    return str;
} 

std::vector<std::string> String::split (std::string &str, const std::string delimiter){
    std::vector<std::string> parts;
    std::size_t pos = 0;
    std::string token;
    while((pos = str.find(delimiter)) != std::string::npos){
        token = str.substr(0,pos);
        parts.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    parts.push_back(str);
    return parts;
}

std::vector<char> String::toCharArr(std::string &str){}

std::string String::toUpper(std::string &str){
    std::locale loc;
    std::string upper;
    for(std::string::size_type i = 0; i < str.length(); ++i)
    {
        upper += std::toupper(str[i], loc);
    }
    str = upper;
    return str; 
}

std::string String::toLower(std::string &str){
    std::locale loc;
    std::string lower;
    for(std::string::size_type i = 0; i < str.length(); ++i)
    {
        lower += std::tolower(str[i], loc);
    }
   return str;
}

std::string String::trim(std::string &str){
    //trim left side
    std::string::size_type trimIt = 0;
    for(std::string::size_type i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ')
        {
            trimIt++;    
        }
        else break;
    }
    str.erase(0,trimIt);

    //trim right side
    trimIt = str.length();
    for(std::string::size_type i = str.length()-1; i > 0; i--)
    {
        if(str[i] == ' '){
            trimIt--;
        }
        else break;
    }
    str.erase(trimIt,str.length()-1);

    return str;
}

std::string String::trimLeft(std::string &str){
    std::string::size_type trimIt = 0;
    for(std::string::size_type i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ')
        {
            trimIt++;    
        }
        else break;
    }
    str.erase(0,trimIt);

    return str;
}

std::string String::trimRight(std::string &str){
    std::string::size_type trimIt = str.length();
    while(str.rfind(" ") == str.length()-1){
        if(str.length() == 1){
            str.erase(0);
            break;
        }
        str.erase(str.length()-1);
    }
    return str;
}

std::string String::fillLeft(std::string &str, int length, char fill){
    for(int i = 0; i < length; i++){
        str.insert(str.begin(), fill);
    }
    return str;
}

inline std::string String::padLeft(std::string &str, int length, char fill){
    String::fillLeft(str, length, fill);    
}

std::string String::fillRight(std::string &str, int length, char fill){
    for (int i = 0; i < length; i++) {
        str += fill;
    }
    return str;
}

inline std::string String::padRight(std::string &str, int length, char fill){
    String::fillRight(str, length, fill);
}

std::string String::normPathUnix(std::string &str){
    for(int i = 1; i < str.length(); i++){
        if(str.at(i) == str.at(i-1)){
            str.erase(i);
        }
    }
    return str;
}

std::string String::normPathWindows(std::string &str){
    for(int i = 1; i < str.length(); i++){
        if(str.at(i) == str.at(i-1)){
            str.erase(i);
        }
    }
    return str;
}

