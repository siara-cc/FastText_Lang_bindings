/*
 * Copyright (c) Arundale Ramanathan, Siara Logics (cc)
 * All rights reserved.
 *
 * This source code is licensed under MIT License. Please see
 * LICENSE file in the root directory of this source tree).
 */
 
#include <stdio.h>     // fprintf
#include <stdlib.h>    // free
#include <fasttext.h>
#include <string>
#include <sstream>

using namespace std;

fasttext::FastText ftext;

void printPredictions(
    const vector<pair<fasttext::real, string>>& predictions,
    bool printProb,
    bool multiline) {
  bool first = true;
  for (const auto& prediction : predictions) {
    if (!first && !multiline) {
      cout << " ";
    }
    first = false;
    cout << prediction.second;
    if (printProb) {
      cout << " " << prediction.first;
    }
    if (multiline) {
      cout << endl;
    }
  }
  if (!multiline) {
    cout << endl;
  }
}

void predict(fasttext::FastText& m, std::string input) {
    int32_t k = 1;
    fasttext::real threshold = 0.0;
    stringstream ioss(input);
    vector<pair<fasttext::real, string>> predictions;
    m.predictLine(ioss, predictions, k, threshold);
    printPredictions(predictions, true, true);
}

int main(int argc, const char** argv)
{
    const char* const exeName = argv[0];
 
    if (argc<2) {
        fprintf(stderr, "wrong arguments\n");
        fprintf(stderr, "usage:\n");
        fprintf(stderr, "%s <str_to_predict>\n", exeName);
        return 1;
    }

    string in_str(argv[1]);

    ftext.loadModel(string("lid.176.bin"));
    predict(ftext, in_str);
 
    return 0;
}

