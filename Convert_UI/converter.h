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
    std::string m_imgPattern = "BMP|bitmap|DDS|GIF|JPEG|PDF|PNG|PSD|TGA|THM|TIF|TIFF|YUV";
    std::string m_audioPattern = "AIF|FLAC|IFF|M3U|M4A|MID|MP3|MPA|WAV|WMA";
    std::string m_vidPattern = "3G2|3GP|ASF|AVI|FLV|M4V|MOV|MP4|MPG|RM|SRT|SWF|VOB|WMV";
    std::string m_txtPattern = "DOC|DOCX|LOG|MSG|ODT|PAGES|RTF|TEX|TXT|WPD|WPS"; 
    const std::string m_fileCmd = "file "; 
    const std::string m_msgSuccess = "File was sucessfully converted!";
    const std::string m_msgFileNotExists = "The file does not exist!";
    const std::string m_msgFailure = "File can't be converted";
    const std::string m_msgNotFileType = "Input file has not the file type "; 
    const std::string m_exec_convert = "/usr/bin/convert";
    const std::string m_exec_ffmpeg = "/usr/bin/ffmpeg";
    const char* m_exec_unoconv = "/usr/bin/unoconv";

    bool fileExists(const std::string& filePath);
//std::string getFileExtension(const std::string& filePath); 

public:
    Converter();
    Converter(std::string iFileType, std::string oFileType);
    ~Converter();
    std::string getInputFlType();

    std::string getFileExtension(const std::string& filePath); 
    std::string convertImg(const std::string input, std::string output);
    std::string convertAudio(const std::string input, std::string output); 
    std::string convertVid(const std::string input, std::string output);
    std::string convertText(const std::string input, std::string output);
};

#endif // CONVERTER_H
