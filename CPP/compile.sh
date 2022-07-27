DIRECTORY='fastText'
if [ ! -d "$DIRECTORY" ]; then
  git clone https://github.com/facebookresearch/fastText
fi
if [ ! -f "lid.176.bin" ]; then
  curl -o lid.176.bin https://dl.fbaipublicfiles.com/fasttext/supervised-models/lid.176.bin
fi
if [ ! -f "fastText/libfasttext.a" ]; then
  cd fastText
  make
  ar rcs libfasttext.a args.o autotune.o matrix.o dictionary.o loss.o productquantizer.o densematrix.o quantmatrix.o vector.o model.o utils.o meter.o fasttext.o 
  cd ..
fi
g++ -std=c++11 -O3 -o fasttext_predict -I./fastText/src fasttext_predict.cpp fastText/libfasttext.a
