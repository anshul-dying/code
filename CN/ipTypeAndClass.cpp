#include <iostream>
using namespace std;

char findClass(int firstOctet) {
    if (firstOctet >= 1 && firstOctet <= 127)
        return 'A';
    else if (firstOctet >= 128 && firstOctet <= 191)
        return 'B';
    else if (firstOctet >= 192 && firstOctet <= 223)
        return 'C';
    else if (firstOctet >= 224 && firstOctet <= 239)
        return 'D';
    else if (firstOctet >= 240 && firstOctet <= 255)
        return 'E';
    return 'X';
}

string findType(int firstOctet, int secondOctet) {
    if ((firstOctet == 10) ||
        (firstOctet == 172 && (secondOctet >= 16 && secondOctet <= 31)) ||
        (firstOctet == 192 && secondOctet == 168))
        return "Private";
    return "Public";
}

void processIP() {
    int octets[4] = {0}; 
    char dot;           

    cout << "Enter the IP address (format: x.x.x.x): ";
    cin >> octets[0] >> dot >> octets[1] >> dot >> octets[2] >> dot >> octets[3];

    for (int i = 0; i < 4; i++) {
        if (octets[i] < 0 || octets[i] > 255) {
            cout << "Invalid IP address!" << endl;
            return;
        }
    }

    char ipClass = findClass(octets[0]);
    string ipType = findType(octets[0], octets[1]);

    if (ipClass == 'X') {
        cout << "Invalid IP address class!" << endl;
    } else {
        cout << "Class: " << ipClass << endl;
        cout << "Type: " << ipType << endl;
    }
}

int main() {
    processIP();
    return 0;
}
