#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
    // 创建流对象
    ofstream ofs;
    //指定打开方式
    ofs.open("./test.txt", ios::out);
    // 写内容
    ofs << "hello world"
        << " jsdfhksjdhfkjskdcshbc"
        << endl;
    //关闭文件
    ofs.close();

    //读取test.txt
    ifstream ifs;
    ifs.open("./test.txt", ios::in);
    if( ! ifs.is_open()){
        cout << "文件打开失败！";
        return 0;
    } 
    char buf[1024] = {0};
    while(ifs >> buf){
        cout << buf << endl;
    }
    // ifs.getline(buf, cnt)
    // string buf;  getline(ifs, buf);
    ifs.close();
}
