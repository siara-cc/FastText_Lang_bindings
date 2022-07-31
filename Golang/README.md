# Integrating fasttext library in your Go program

Compile shared object in CPP folder using `sh compile.sh` and it should produce a shared object/dll with name `fasttext_predict`.

Change folder to `Golang/src/fasttext_predict` and invoke `main.go` using `go run`.

Sample invocation and output:
```
go run main.go "Hello World"
__label__en
go run main.go "Bonjour"    
__label__fr
go run main.go "mi casa es tu casa"
__label__es
```
