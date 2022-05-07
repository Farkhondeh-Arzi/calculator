#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "calculator.h"
#include <fstream>

/*
 * Read inputs from a file and put the output in the output file
 * Get result of the operation of Calculator class
 */

class Evaluator {

private:

    //Store the number of lines
    int number;

    /*
     * Pass every line to calculator to calculate the operation
     * Print the result in output file
     */
    void evaluate(ofstream &, string);

public:

    /*
     * Open the input file and the output file
     * Get lines of the input file
     */
    void run();

};

void Evaluator::evaluate(ofstream &fout, string line) {

    Calculator calculator(line);

    fout << calculator.getResult() << endl;

}

void Evaluator::run() {

    ifstream fin("input.txt");

    ofstream fout;
    fout.open("output.txt");

    string line;

    getline(fin, line);
    number = (int) (line[0]) - 48;

    for (int i = 0; i < number; ++i) {

        getline(fin, line);
        evaluate(fout, line);
    }

    fin.close();
    fout.close();

}

#endif
