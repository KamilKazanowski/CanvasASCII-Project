//program pisałem i kompilowałem na Windows 11 w VS Code

#include <iostream>
#include "canvas.h"
#include "figure.h"
#include <fstream>
#include <string>
#include <vector>

int main (int argc, char *argv[]) {
    //przykładowy plik wejściowy załączyłem w pliku i nazwałem inputfile
	if (argc != 2){
		std::cerr<<"Nieprawidlowa ilosc argumentow!"<<std::endl;
		exit(-1);
	}

	std::ifstream plik(argv[1]);

    if (!plik){
        std::cerr << "Taki plik nie istnieje!" << std::endl;
        exit(-1);
    }

    std::string str, outputfileName;
    int canvasWidth = 0;
    int canvasHeight = 0;
    char blank = 0; 

    plik >> str;
    canvasWidth = stoi(str);
    str.clear();
    plik >> str;
    canvasHeight = stoi(str);
    str.clear();

    plik >> str;
    outputfileName = str;
    str.clear();

    plik >> str;    // aby znakiem nienależenia do pliku była spacja należy wpisać space
    if (str == "space") {
        blank = ' ';
    } else {
    blank = str[0];
    }
    str.clear();

    CanvasASCII canvas(canvasWidth, canvasHeight, blank);

    std::vector<std::string> vec;

    while (str != "rectangle" && str != "square" && str != "circle" && !plik.eof()){
        plik >> str;
    }

    while (!plik.eof()) {

        if (str == "rectangle"){
            plik >> str;
            while (str != "rectangle" && str != "square" && str != "circle" && !plik.eof()) {
                vec.push_back(str);
                plik >> str;
            }
            if (plik.eof()) {
                vec.push_back(str);
            }
            if (vec.size() < 5) {
                std::cerr << "Niewystarczająca ilość elementów do stworzenia obiektu Rectangle" << std::endl;\
                exit(-1);
            }
            Rectangle R(stoi(vec[0]), stoi(vec[1]), stoi(vec[2]), stoi(vec[3]), vec[4][0]);
            R.draw(canvas);
            vec.clear();
        }

        if (str == "square"){
            plik >> str;
            while (str != "rectangle" && str != "square" && str != "circle" && !plik.eof()) {
                vec.push_back(str);
                plik >> str;
            }
            if (plik.eof()) {
                vec.push_back(str);
            }
            if (vec.size() < 5) {
                std::cerr << "Niewystarczająca ilość elementów do stworzenia obiektu Rectangle" << std::endl;\
                exit(-1);
            }            
            Square S(stoi(vec[0]), stoi(vec[1]), stoi(vec[2]), vec[3][0]);
            S.draw(canvas);
            vec.clear();
        }

        if (str == "circle"){
            plik >> str;
            while (str != "rectangle" && str != "square" && str != "circle" && !plik.eof()) {
                vec.push_back(str);
                plik >> str;
            }
            if (plik.eof()) {
                vec.push_back(str);
            }
            if (vec.size() < 5) {
                std::cerr << "Niewystarczająca ilość elementów do stworzenia obiektu Rectangle" << std::endl;\
                exit(-1);
            }
            Circle S(stoi(vec[0]), stoi(vec[1]), stoi(vec[2]), vec[3][0]);
            S.draw(canvas);
            vec.clear();
        }
    }


    std::fstream outputfile;
    outputfile.open(outputfileName, std::ios::out | std::ios::trunc);

    for (int i = canvasHeight - 1; i >= 0; i--){
        if (i > 9) {
            outputfile << i << ": ";
        }
        else {
            outputfile << i << ":  ";
        }
        for (int j = 0; j < canvasWidth; j++){
            outputfile << canvas.getCanvasMem(i, j);
        }
        outputfile << '\n';
    }
    outputfile << "    ";
    for (int i = 0; i < canvasWidth && i < 13; i++) {
        outputfile << i;
    }

    plik.close();
    outputfile.close();
}