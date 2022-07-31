# Integrating fasttext library in your Julia program

Compile shared object in CPP folder using `sh compile.sh` and it should produce a shared object/dll with name `fasttext_predict`.

Change folder to `Julia` folder and invoke `julia main.jl`.

Sample invocation and output:
```
julia main.jl "Hello World"
__label__en
julia main.jl "Bonjour"    
__label__fr
julia main.jl "mi casa es tu casa"
__label__es
```
