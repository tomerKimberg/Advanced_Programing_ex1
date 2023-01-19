//
// Created by tomer on 19/01/2023.
//

#include "Command1.h"
#define UPLOAD_TRAIN_CSV  "Please upload your local train CSV file.\n"

Command1::Command1(std::string description, DefaultIO io,
                   Context context) : Command(description, io, context) {
}
void Command1::execute() {
    this->io.write(UPLOAD_TRAIN_CSV);
    std::string valid  = this->io.read();
    if(valid == "invalid Path"){

    }
    else{

    }

}