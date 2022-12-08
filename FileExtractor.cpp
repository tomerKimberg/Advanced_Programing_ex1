
#include "FileExtractor.h"

FileExtractor::FileExtractor(std::string path): path(path){}
std::string FileExtractor::getPath() {
    return std::string();
}
//implement
FileExtractor::~FileExtractor(){}
/**
 * create a new FileExtractor object on the Heap and returns it's address! must save pointer to delete later!
 * @return DataExtractor pointer
 */
DataExtractor* FileExtractor::copy() {
    return new FileExtractor(this->path);

}

void FileExtractor::setPath(std::string newPath) {
    this->path = newPath;
}
std::string FileExtractor::getData() {
    return "s";
}
bool FileExtractor::hasNext() {}




