#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
#include <regex>

enum FileType {
    IMAGE = 0,
    AUIDO,
    VIDEO,
    AUDIO_VIDEO,
    TEXT,
    DATA,
    PRESENTATION
};

class Converter {

private:
    int m_pid;
    int m_status;
    std::string m_fileExtension;
    std::string m_inputFlType;
    std::string m_outputFlType;
    std::string m_iEnd;
    // common file extensions
    std::string m_imgFileExt = "BMP|DDS|GIF|JPEG|PDF|PNG|PSD|TGA|TIF|TIFF";
    std::string m_audFileExt = "AIF|FLAC|M4A|MP3|MPA|WAV|WMA";

    // patterns search output form file command
    std::string m_imgPattern = "BMP|bitmap|DDS|GIF|JPEG|PDF|PNG|PSD|TGA|TIF|TIFF";
    //std::string m_audioPattern = "AIF|FLAC|M4A|MP3|MPA|WAV|WMA";
    std::string m_audioPattern = "AIF|ASF|FLAC|M4A|Audio file with ID3|MPEG|WAVE";
    std::string m_vidPattern = "3G2|3GP|ASF|AVI|FLV|M4V|MOV|MP4|MPG|RM|SRT|SWF|VOB|WMV";
    std::string m_txtPattern = "DOC|DOCX|ODT|PAGES|RTF|TXT|WPD|WPS|text"; 
    const std::string m_fileCmd = "file "; 
    const std::string m_msgSuccess = "File was sucessfully converted!";
    const std::string m_msgFileNotExists = "The file does not exist!";
    const std::string m_msgOutFileExists = "Output file does already exists!";
    const std::string m_msgFailure = "File can't be converted";
    const std::string m_msgNotFileType = "Input file has not the file type "; 
    std::string m_errMsg; 
    const std::string m_exec_convert = "/usr/bin/convert";
    const std::string m_exec_ffmpeg = "/usr/bin/ffmpeg";
    const std::string m_exec_unoconv = "/usr/bin/unoconv"; 

    bool fileExists(const std::string& filePath);
    bool checkFileExtension(const std::string& output, FileType type); 
    bool checkIOPaths(const std::string& input, const std::string& output, const std::regex& re); 
    //std::string getFileExtension(const std::string& filePath); 

public:
    Converter();
    Converter(std::string iFileType, std::string oFileType);
    ~Converter();
    std::string getInputFlType();
    bool checkProgram(const std::string cmd);
    
    std::string getFileType(const std::string& filePath); 
    std::string convertImg(const std::string input, std::string output);
    std::string convertAudio(const std::string input, std::string output); 
    std::string convertVid(const std::string input, std::string output);
    std::string convertText(const std::string input, std::string output);
};

#endif // CONVERTER_H
