
#include "FileExtractor.h"
#define FILE_EXTRACTOR_DEBUG 0


FileExtractor::FileExtractor(std::string filePath): path(filePath){
    //open a file with reading premmisions
    fileStream.open(path);
    if(FILE_EXTRACTOR_DEBUG) {
        std::cout << "after fileStream.open, stream.fail() is: " << fileStream.fail() << std::endl;
    }
}
std::string FileExtractor::getPath() {
    return std::string();
}
//implement
FileExtractor::~FileExtractor(){
    fileStream.close();
}
/**
 * create a new FileExtractor object on the Heap and returns it's address! must save pointer to delete later!
 * @return DataExtractor pointer
 */
DataExtractor* FileExtractor::copy() {
    //we can copy because we are opening the file in path with reading premmisions
    return new FileExtractor(this->path);

}

void FileExtractor::setPath(std::string newPath) {
    fileStream.close();
    this->path = newPath;
    fileStream.open(newPath);
}
std::string FileExtractor::getData() {
    std::string line = "";
    if(!this->hasNext()) {
        return line;
    }
    std::getline(fileStream, line);
    return line;
}
bool FileExtractor::hasNext() {
    fileStream.peek();
    return !fileStream.eof();
}
bool FileExtractor::fail() {
    return fileStream.fail();
}




