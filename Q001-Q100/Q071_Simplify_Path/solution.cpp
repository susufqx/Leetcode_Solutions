#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string simplifyPath(string path) {
        int i;
        int count = 0;
        for (i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                count++;
            }
        }

        vector<string*> partsVector;
        vector<string> records(count);
        count = 0;
        for (i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (i != 0 && records[count] != "") {
                    partsVector.push_back(&records[count++]);
                }
                records[count] = "";
            } else {
                records[count] += path[i];
                if (i == path.size() - 1 && records[count] != "") {
                    partsVector.push_back(&records[count++]);
                }
            }
        }

        i = 0;
        while (i < partsVector.size()) {
            if (*partsVector[i] == ".") {
                partsVector[i] = NULL;
            } else if (*partsVector[i] == "..") {
                for (int j = i - 1; j >= 0; j--) {
                    if (partsVector[j] != NULL) {
                        partsVector[j] = NULL;
                        break;
                    }
                }

                partsVector[i] = NULL;
            }
            i++;
        }

        string tmpPath = "";
        for (i = 0; i < partsVector.size(); i++) {
            string* p = partsVector[i];
            if (p != NULL) {
                tmpPath += "/" + *p;
            }
        }

        if (tmpPath == "") {
            tmpPath = "/";
        }

        return tmpPath;
    }
};

int main(int argc, char** argv) {
    Solution solu;
    // cout << solu.simplifyPath("/../aa//////././././b/") << endl;
    cout << solu.simplifyPath("/../") << endl;
    cout << solu.simplifyPath("/////PO/../../FZ/ZQw/Ee/yAfy/zppA/OYajA/ZpX/./.")
         << endl;
    // cout << solu.simplifyPath("/a/../../b/../c//.//") << endl;
    // cout << solu.simplifyPath("/a//b////c/d//././/..") << endl;
    // cout << solu.simplifyPath("/a/../../b/../c//.//") << endl;
    // cout << solu.simplifyPath("/...") << endl;
    return 0;
}