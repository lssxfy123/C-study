// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// C++ÎÄ¼þ¶ÁÈ¡
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "../include/print.hpp"
using namespace std;

#define CONFIG_FILE_NAME "..\\config\\config.ini"

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

int main(int argc, char* argv[])
{
    string ip = GetServerIP();
    cout << "ip " << ip << endl;

    Sleep(2000);
    ip = GetServerIP();
    cout << "ip " << ip << endl;

    Sleep(2000);
    ip = GetServerIP();
    cout << "ip " << ip << endl;
    return 0;
}
