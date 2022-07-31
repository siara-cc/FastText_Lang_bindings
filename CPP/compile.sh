DIRECTORY='fastText'
if [ ! -d "$DIRECTORY" ]; then
  git clone https://github.com/facebookresearch/fastText
fi
if [ ! -f "lid.176.bin" ]; then
  curl -o lid.176.bin https://dl.fbaipublicfiles.com/fasttext/supervised-models/lid.176.bin
fi
if [ ! -f "fastText/libfasttext.a" ]; then
  cd fastText
  cmake .
  make fasttext-static
  cd ..
fi
g++ -std=c++11 -O3 -o fasttext_predict -I./fastText/src fasttext_predict.cpp fastText/libfasttext.a
g++ -std=c++11 -O3 -fPIC -DFTEXT_SHARED_LIB=1 -c -I./fastText/src fasttext_predict.cpp
g++ -fPIC -shared -DFTEXT_SHARED_LIB=1 -o fasttext_predict.so -fvisibility=hidden fasttext_predict.o fastText/libfasttext.a
