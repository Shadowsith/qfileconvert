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
    // Image
    if (iFileType == "BMP") m_inputFlType = "bitmap";
    if (iFileType == "DDS") m_inputFlType = "DirectDraw Surface"; 
    if (iFileType == "PSD") m_inputFlType = "Adobe Photoshop Image"; 
    if (iFileType == "TGA") m_inputFlType = "Targa image data"; 
    if (iFileType == "TIF") m_inputFlType = "TIFF"; 

    // Audio
    if (iFileType == "MP3") m_inputFlType = "Audio file with ID3"; 
    if (iFileType == "MPA") m_inputFlType = "MPEG"; 
    if (iFileType == "WAV") m_inputFlType = "WAVE"; 
    if (iFileType == "WMA") m_inputFlType = "ASF"; 

    // Video

    // Text
    if (iFileType == "DOCX") m_inputFlType = "Microsoft Word";
    if (iFileType == "DOC") m_inputFlType = "Composite Document File"; 
    if (iFileType == "ODT") m_inputFlType = "OpenDocument Text";
    if (iFileType == "TXT") m_inputFlType = "text";

    m_outputFlType = oFileType; 
}

Converter::~Converter() {
    //delete this;
}

std::string Converter::getInputFlType() {
    return m_inputFlType;
}

bool Converter::checkProgram(const std::string cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd.c_str(),"r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }
    if(result == "" || (result.find("which: no") != std::string::npos)) {
        return false;
    } else {
        return true;
    }
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
                        execl(m_exec_convert.c_str(), m_exec_convert.c_str(), 
                                input.c_str(), emptyOut.c_str(), NULL);
                    } else {
                        execl(m_exec_convert.c_str(), m_exec_convert.c_str(), 
                                input.c_str(), output.c_str(), NULL);
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
    std::regex re(m_audioPattern);
    std::transform(m_audioPattern.begin(), m_audioPattern.end(),
            m_audioPattern.begin(), ::tolower); 
    std::regex re2(m_audioPattern);
    if (fileExists(input)) {
        if(!fileExists(output)) {
        if(std::regex_search(getFileExtension(input), re) ||
                std::regex_search(getFileExtension(input), re2)) {
            if (m_pid = fork()) {
                waitpid(m_pid, &m_status, 0);
            } else {
                const std::string ffmpeg = "ffmpeg -i"; 
                if (output.empty() || output == "") {
                    std::string emptyOut = input.substr(0, input.rfind("/")+1) + "out." + m_outputFlType; 
                    execl(m_exec_ffmpeg.c_str(), ffmpeg.c_str(), "-i", input.c_str(), emptyOut.c_str(), NULL);
                } else {
                    execl(m_exec_ffmpeg.c_str(), ffmpeg.c_str(), "-i", input.c_str(), output.c_str(), NULL);
                }
            }
            return m_msgSuccess;
        } else {
            return m_msgNotFileType + m_inputFlType; 
        }
        } else {
            return m_msgOutFileExists;
        }
        
    } else {
        return m_msgFileNotExists; 
    }
}

std::string Converter::convertVid(const std::string input, std::string output) {
    if (fileExists(input)) {
        if (m_pid == fork()) {
            waitpid(m_pid, &m_status, 0);
        } else {
            //execl(m_exec_ffmpeg, m_exec_ffmpeg, input.c_str(), output.c_str(), NULL);
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
            execl(m_exec_unoconv.c_str(), m_exec_unoconv.c_str(), input.c_str(), output.c_str(), NULL);
        }
        return m_msgSuccess;
    } else {
        return m_msgFileNotExists;
    }
}
