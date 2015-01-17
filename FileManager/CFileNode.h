//
//  CFileNode.h
//  LinuxProj
//
//  Created by MarK on 12/24/14.
//  Copyright (c) 2014 MarK. All rights reserved.
//

#ifndef LinuxProj_CFileNode_h
#define LinuxProj_CFileNode_h


#endif

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class CFileNode {

private:

    string nodeName;
    string nodePath;
    int nodeType; /*0 表示应用程序, 1 表示可用Vim打开的文本文件， 2 表示文件夹*/

public:

    CFileNode()
    {
        nodeName = "";
        nodePath = "";
        nodeType = -1;

    }

    CFileNode(string name, string path, int type)
    {
        nodeName = name;
        nodePath = path;
        nodeType = type;
    }

    //open the current path, use command sudo nautilus /path
    void openCurrent()
    {
        string command = "nautilus " + nodePath + nodeName;
        system(command.c_str());
    }

    // if the input string is contained in nodeName return ture, else return false
    bool containKeyWord(string str)
    {
        if (nodeName.find(str) != nodeName.npos) {
            return true;
        }
        else
        {
            int i = nodeName.find('.');
            string subStr = nodeName.substr(i+1, nodeName.length()-i-1);

            vector<string> acceptTypes;
            acceptTypes.push_back("vim");
            acceptTypes.push_back("c");
            acceptTypes.push_back("h");
            acceptTypes.push_back("txt");

            for (int i = 0; i < acceptTypes.size(); ++i) {
                if (subStr == acceptTypes[i]) {

                    string strInput = nodePath + nodeName;



                    ifstream f(strInput.c_str(), ios::in);
                    if(!f){
                        return false;
                    }

                    char c;
                    string strContent = "";
                    while((c=f.get())!=EOF)
                    {
                        strContent += c;
                    }

                    f.close();


                    if(strContent.find(str) == strContent.npos)
                    {
                        return false;
                    }
                    else{
                        return true;
                    }
                }
            }

            return false;
        }
    }

    void setNodeName(string name)
    {
        nodeName = name;
    }

    string getNodeName()
    {
        return nodeName;
    }

    void setNodePath(string path)
    {
        nodePath = path;
    }

    string getNodePath()
    {
        return nodePath;
    }

    void setNodeType(int type)
    {
        nodeType = type;
    }

    int getNodeType()
    {
        return nodeType;
    }


};
