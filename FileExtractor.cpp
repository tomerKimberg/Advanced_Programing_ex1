
#include "FileExtractor.h"

FileExtractor::FileExtractor(std::string path): path(path){}
std::string FileExtractor::getPath() {
    return std::string();
}
//implement
FileExtractor::~FileExtractor(){}

void FileExtractor::setPath(std::string newPath) {
    this->path = newPath;
}
std::string FileExtractor::getData() {
    return "s";
}
bool FileExtractor::hasNext() {}




