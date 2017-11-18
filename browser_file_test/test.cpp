// 遍历文件夹下的所有文件
#include <cstdlib>
#include "direct.h"
#include <string>
#include <corecrt_io.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define CONFIG_FILE_NAME "..\\config\\config.ini"

bool IsStudentStateFileExist(string user_id)
{
    string file_name = "..\\cache\\" + user_id + ".txt";
    ifstream in;
    in.open(file_name.c_str());
    if (!in)
    {
        return false;
    }
    in.close();
    return true;
}

string GetServerIP()
{

    cout << "read config file " << CONFIG_FILE_NAME << endl;;

    string server_ip = "";
    ifstream in;
    in.open(CONFIG_FILE_NAME);
    if (!in)
    {
        cout << "read config file " << CONFIG_FILE_NAME << " failed" << endl;;
        return server_ip;
    }

    std::string buffer;
    getline(in, buffer);
    while (getline(in, buffer))
    {
        if (buffer.length() > 0)
        {
            string::size_type const idx = buffer.find('=');
            if (idx != string::npos)
            {
                string key = buffer.substr(0, idx);
                string value = buffer.substr(idx + 1);

                if (key.compare("SERVERIP") == 0)
                {
                    server_ip = value;
                    break;
                }
            }
        }
    }

    in.close();
    return server_ip;
}

bool BrowseDir(const char *dir, const char *filespec)
{
    char init_dir[_MAX_PATH] = { 0 };

    //先把dir转换为绝对路径
    if (_fullpath(init_dir, dir, _MAX_PATH) == NULL)
    {
        cout << "目录不存在1" << endl;
        return false;
    }

    //判断目录是否存在
    if (_chdir(init_dir) != 0)
    {
        cout << "目录不存在2" << endl;
        return false;
    }

    //如果目录的最后一个字母不是'\',则在最后加上一个'\'
    int length = strlen(init_dir);
    if (init_dir[length - 1] != '\\')
        strcat(init_dir, "\\");

    _chdir(init_dir);

    //首先查找dir中符合要求的文件  
    long file_handle;
    _finddata_t file_info;
    if ((file_handle = _findfirst(filespec, &file_info)) != -1)
    {
        do
        {
            cout << "file info name " << file_info.name << endl;
            //检查是不是目录
            //如果不是,则进行处理
            if (!(file_info.attrib & _A_SUBDIR))
            {
                char file_name[_MAX_PATH];
                strcpy(file_name, init_dir);
                strcat(file_name, file_info.name);
                cout << file_name << endl;

                ifstream in;
                in.open(file_name);
                if (!in)
                {
                    return false;
                }
                std::stringstream buffer;
                buffer << in.rdbuf();
                string content(buffer.str());
                cout << content << endl;
            }
        } while (_findnext(file_handle, &file_info) == 0);
        _findclose(file_handle);
    }
    return true;
}



void main()
{
    string ip = GetServerIP();
    cout << "ip " << ip << endl;

    char back_up[_MAX_PATH] = { 0 };
    _getcwd(back_up, _MAX_PATH);

    //获取目录名
    string buf = "..\\cache\\test\\student\\";

    //开始遍历  
    BrowseDir(buf.c_str(), "*.*");
    _chdir(back_up);

    IsStudentStateFileExist("1");

    BrowseDir(buf.c_str(), "*.*");

    _chdir(back_up);
    string ip1 = GetServerIP();
    cout << "ip1 " << ip1 << endl;
}
