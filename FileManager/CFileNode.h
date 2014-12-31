//
//  CFileNode.h
//  LinuxProj
//
//  Created by MarK on 12/24/14.
//  Copyright (c) 2014 MarK. All rights reserved.
//

#ifndef CFILENODE_H
#define CFILENODE_H

#endif // CFILENODE_H

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

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

    //open the current path, use command sudo nautilus /path
    void openCurrent();

    // if the input string is contained in nodeName return ture, else return false
    bool containKeyWord(string str);

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

