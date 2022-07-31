import 'dart:ffi';
import 'package:ffi/ffi.dart';

typedef LoadModelNative = Void Function(Pointer<Utf8> str);
typedef LoadModel = void Function(Pointer<Utf8> str);

typedef PredictNative = Void Function(Pointer<Utf8> str, Pointer<Utf8> output);
typedef Predict = void Function(Pointer<Utf8> str, Pointer<Utf8> output);

main(List<String> args) {
  if (args.length < 1) {
    print("Please provide input string for prediction");
    return;
  }

  final lib = DynamicLibrary.open('../CPP/fasttext_predict.so'); // Load library

  final load_model_fn = lib.lookupFunction<LoadModelNative, LoadModel>(
      'load_model'); // Lookup function in library

  final filenameUtf8 = "../CPP/lid.176.bin".toNativeUtf8();
  load_model_fn(filenameUtf8);
  calloc.free(filenameUtf8);

  final predict_fn = lib.lookupFunction<PredictNative, Predict>(
      'predict'); // Lookup function in library
  final inputUtf8 = args[0].toNativeUtf8();
  Pointer<Utf8> outputPrediction = calloc.allocate(20);
  predict_fn(inputUtf8, outputPrediction);
  print("Prediction:");
  print(outputPrediction.toDartString());
  calloc.free(inputUtf8);
  calloc.free(outputPrediction);
}
