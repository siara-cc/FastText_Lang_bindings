# Integrating fasttext library in your C# program

Compile shared object in CPP folder using `sh compile.sh` and it should produce a shared object/dll with name `fasttext_predict`.

Compile `Program.cs` using `csc Program.cs`. It should produce `Program.exe`.

Sample invocation and output:
```
Program.exe "Hello World"
__label__en
Program.exe "Bonjour"    
__label__fr
Program.exe "mi casa es tu casa"
__label__es
```
