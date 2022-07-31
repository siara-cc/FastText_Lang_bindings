using System;
using System.Text;
using System.Runtime.InteropServices;

class Program
{

    [DllImport("../CPP/fasttext_predict.so", EntryPoint = "load_model")]
    public extern static void load_model(byte[] filename);

    [DllImport("../CPP/fasttext_predict.so", EntryPoint = "predict")]
    public extern static void predict(byte[] input, byte[] output);

    static void Main(string[] args)
    {
        if (args.Length < 1) {
            Console.WriteLine("Please pass the string to predict");
            return;
        }
        byte[] output = new byte[100];
        load_model(Encoding.UTF8.GetBytes("../CPP/lid.176.bin"));
        predict(Encoding.UTF8.GetBytes(args[0]), output);
        Console.WriteLine(Encoding.UTF8.GetString(output));
    }

}
