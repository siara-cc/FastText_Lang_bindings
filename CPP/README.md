# Integrating fasttext library in your C++ program

Compile this library using `sh compile.sh` and it should produce an executable `fasttext_predict`.

Although this is shown in the fasttext library, it has lot more clutter, so this is just a sample program to show how the predict function alone can be integrated in your C++ program.

```
./fasttext_predict "Hello World"
__label__en 0.325867
./fasttext_predict "Bonjour"    
__label__fr 0.962104
./fasttext_predict "mi casa es tu casa"
__label__es 0.600949
```
