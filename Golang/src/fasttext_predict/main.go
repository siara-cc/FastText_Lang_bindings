// main.go
package main

/*
#cgo LDFLAGS: -ldl
 
#include <stdlib.h>
#include <dlfcn.h>
 
typedef void (*loadModel) (const char *filename);

void bridge_loadModel(loadModel f, const char *filename) {
    f(filename);
}

typedef void (*predict) (const char *input, char *output);

void bridge_predict(predict f, const char *input, char *output) {
    f(input, output);
}
*/
import "C"
import (
    "os"
	"fmt"
	"unsafe"
)

func main() {

    if (len(os.Args) < 2) {
        fmt.Println("Usage: go run main.go <string to predict>")
        return
    }
    libpath := C.CString("../../../CPP/fasttext_predict.so")
    defer C.free(unsafe.Pointer(libpath))
    ftpredict_lib := C.dlopen(libpath, C.RTLD_LAZY)
    if ftpredict_lib != nil {
        load_model_sym := C.CString("load_model")
        defer C.free(unsafe.Pointer(load_model_sym))
        fp := C.dlsym(ftpredict_lib, load_model_sym)
        if fp != nil {
            filename := C.CString("../../../CPP/lid.176.bin")
            defer C.free(unsafe.Pointer(filename))
            C.bridge_loadModel(C.loadModel(fp), filename)
        }
        predict_sym := C.CString("predict")
        defer C.free(unsafe.Pointer(predict_sym))
        fp = C.dlsym(ftpredict_lib, predict_sym)
        if fp != nil {
            input_str := C.CString(os.Args[1])
            defer C.free(unsafe.Pointer(input_str))
            ptr := C.malloc(C.sizeof_char * 20)
            defer C.free(unsafe.Pointer(ptr))
            C.bridge_predict(C.predict(fp), input_str, (*C.char) (ptr))
            prediction := C.GoString((*C.char)(ptr))
            fmt.Print("Prediction: ")
            fmt.Println(prediction)
            println()
        }
        C.dlclose(ftpredict_lib)
    }

}
