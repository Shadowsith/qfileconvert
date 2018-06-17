#include <iostream>
#include <unistd.h>
#include <string>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <regex>
#include "converter.h"

Converter::Converter() {}

Converter::Converter(std::string iFileType, std::string oFileType) {
    m_inputFlType = iFileType;
    m_outputFlType = oFileType;
}

Converter::~Converter() {
    //delete this;
}

std::string Converter::getInputFlType() {
    return m_inputFlType;
}

bool Converter::fileExists(const std::string& filePath) {
    struct stat buffer;
    return (stat (filePath.c_str(), &buffer) == 0); 
}

std::string Converter::getFileExtension(const std::string& filePath) {
    std::string cmd = m_fileCmd + filePath; 
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }
    return result;
}

std::string Converter::convertImg(const std::string input, std::string output) {
    std::regex re(m_imgPattern);
    if (fileExists(input)) {
        if(std::regex_search(getFileExtension(input), re)) {
            if (getFileExtension(input).find(m_inputFlType) != std::string::npos) {
                if (m_pid = fork()) {
                    waitpid(m_pid, &m_status, 0);
                } else {
                    if (output.empty() || output == "") {
                        std::string emptyOut = input.substr(0, input.rfind("/")+1) + "out." + m_outputFlType; 
                        execl(m_exec_convert, m_exec_convert, input.c_str(), emptyOut.c_str(), NULL);
                    } else {
                        execl(m_exec_convert, m_exec_convert, input.c_str(), output.c_str(), NULL);
                    }
                }
                return m_msgSuccess;
            } else {
                return m_msgNotFileType + m_inputFlType;
            }
        } else {
            return m_msgFailure;
        }
    } else { 
        return m_msgFileNotExists;
    }
}

std::string Converter::convertAudio(const std::string input, std::string output) {
   return ""; 
}

std::string Converter::convertVid(const std::string input, std::string output) {
    if (fileExists(input)) {
        if (m_pid == fork()) {
            waitpid(m_pid, &m_status, 0);
        } else {
            execl(m_exec_ffmpeg, m_exec_ffmpeg, input.c_str(), output.c_str(), NULL);
        }
        return m_msgSuccess;
    } else {
        return m_msgFileNotExists;
    }
}

std::string Converter::convertText(const std::string input, std::string output) {
    if (fileExists(input)) {
        if (m_pid == fork()) {
            waitpid(m_pid, &m_status, 0);
        } else {
            execl(m_exec_unoconv, m_exec_unoconv, input.c_str(), output.c_str(), NULL);
        }
        return m_msgSuccess;
    } else {
        return m_msgFileNotExists;
    }
}
