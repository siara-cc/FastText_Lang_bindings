path_to_shared_lib = "../CPP/fasttext_predict.so"
ccall( (:load_model, path_to_shared_lib), Cvoid, (Cstring,), "../CPP/lid.176.bin")
prediction = Vector{UInt8}(undef, 20)
ccall( (:predict, path_to_shared_lib), Cvoid, (Cstring,Ptr{UInt8}), Base.ARGS[1], prediction)
println("Prediction: ", unsafe_string(pointer(prediction)))
