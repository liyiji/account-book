
#include "md5.h"

int main(int argc, char* argv[]) {
    //cout << MD5("abc").toString() << endl;
    //cout << MD5(ifstream("D:\\test.txt")).toString() << endl;
    //cout << MD5(ifstream("D:\\test.exe", ios::binary)).toString() << endl;
    //cout << FileDigest("D:\\test.exe") << endl;
    MD5 md5;
    md5.update("");
    PrintMD5("", md5);
    md5.update("a");
    PrintMD5("a", md5);
    md5.update("bc");
    PrintMD5("abc", md5);
    md5.update("defghijklmnopqrstuvwxyz");
    PrintMD5("abcdefghijklmnopqrstuvwxyz", md5);
    md5.reset();
    md5.update("message digest");
    PrintMD5("message digest", md5);
    //md5.reset();
    //md5.update(ifstream("D:\\test.txt"));
    //PrintMD5("D:\\test.txt", md5);
    return 0;
}
