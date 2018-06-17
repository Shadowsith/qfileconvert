#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>


class Converter {

private:
    int m_pid;
    int m_status;
    std::string m_fileExtension;
    std::string m_inputFlType;
    std::string m_outputFlType;
    std::string m_iEnd;
    const std::string m_imgPattern = "PNG|JPEG|PDF|GIF";
    const std::string m_vidPattern = "MP4|MKV|AVI";
    const std::string m_txtPattern = "DOC|DOCX|ODT|PDF"; 
    const std::string m_fileCmd = "file -b "; 
    const char* m_exec_convert = "/usr/bin/convert";
    const char* m_exec_ffmpeg = "/usr/bin/ffmpeg";
    const char* m_exec_libreoffice = "/usr/bin/libreoffice";

    bool fileExists(const std::string& filePath);
    //std::string getFileExtension(const std::string& filePath); 

public:
    Converter();
    Converter(std::string iFileType, std::string oFileType);
    ~Converter();

    std::string getFileExtension(const std::string& filePath); 
    int convertImg(const std::string& input, std::string& output);
    int convertVid(const std::string& input, std::string& output);
    int convertText(const std::string& input, std::string& output);
};

#endif // CONVERTER_H
