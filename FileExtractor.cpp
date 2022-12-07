
#include "FileExtractor.h"

FileExtractor::FileExtractor(std::string path) {}
std::string FileExtractor::getPath() {
    return std::string();
}
//implement
FileExtractor::~FileExtractor(){}

void FileExtractor::setPath(std::string newPath) {
    this->path = newPath;
}
std::string FileExtractor::getData() {}
bool FileExtractor::hasNext() {}




