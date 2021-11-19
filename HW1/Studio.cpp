#include "Studio.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

 using namespace std;


    Studio:: Studio() {
    }


    Studio:: Studio(const string &configFilePath){
        ifstream studioFile(configFilePath);
        string line;
        vector<string> text_of_file;
        vector<string> capacities;
        while (!studioFile.eof()){
            getline(studioFile,line);
            if (line[0]=='#' ||line.empty()){
                continue;
            }
            else {
                text_of_file.push_back(line);
            }
        }

        for (int i = 0; i < text_of_file.size(); ++i) {
            if (i == 0){
                stringstream my_num( text_of_file[0]);
                my_num >> numOfTrainers;
            }
            if (i==1){
                string cap = text_of_file[1];
                for (int j = 0; j < numOfTrainers; ++j) {
                text_of_file[1].find(",");



//
                }
            }
        }


//                    studioFile.getline(line, 256);
//            if (line[0] == '#' or line[0] == '\0') {
//                continue;
//
//    string lineContents;
//    while (!studioFile.eof()){
//        getline(studioFile,lineContents);
//
//    }}}



        //
//    ifstream inFile;
//        while (file) {

//            }
//        }
//        while (file){
//            file.getline(line,256)
//            int num_of_trainers =    }
};




