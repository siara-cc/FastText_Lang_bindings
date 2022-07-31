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
#include <string.h>
#include <string>
#include <sstream>

using namespace std;

fasttext::FastText ftext;

#ifndef FTEXT_SHARED_LIB
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
#endif

#ifdef FTEXT_SHARED_LIB
extern "C" __attribute__((__visibility__("default")))
#endif
void load_model(const char *filename) {
    ftext.loadModel(string(filename));
}

#ifdef FTEXT_SHARED_LIB
extern "C" __attribute__((__visibility__("default")))
#endif
void predict(const char *input, char *out) {
    int32_t k = 1;
    fasttext::real threshold = 0.0;
    stringstream ioss((std::string(input)));
    vector<pair<fasttext::real, string>> predictions;
    ftext.predictLine(ioss, predictions, k, threshold);
#ifndef FTEXT_SHARED_LIB
    printPredictions(predictions, true, true);
#endif
    for (const auto& prediction : predictions) {
      strcpy(out, prediction.second.c_str());
      break;
    }
}

#ifndef FTEXT_SHARED_LIB
int main(int argc, const char** argv)
{
    const char* const exeName = argv[0];
 
    if (argc<2) {
        fprintf(stderr, "wrong arguments\n");
        fprintf(stderr, "usage:\n");
        fprintf(stderr, "%s <str_to_predict>\n", exeName);
        return 1;
    }

    load_model("lid.176.bin");

    char lang_code[20];
    predict(argv[1], lang_code);
 
    return 0;
}
#endif
