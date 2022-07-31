# Integrating fasttext library in your Dart program

Compile shared object in CPP folder using `sh compile.sh` and it should produce a shared object/dll with name `fasttext_predict`.

Change folder to `Dart` and invoke `main.dart` using `dart run`.

Sample invocation and output:
```
dart run main.dart "Hello World"
__label__en
dart run main.dart "Bonjour"    
__label__fr
dart run main.dart "mi casa es tu casa"
__label__es
```
