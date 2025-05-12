#include <iostream>
#include <vector>
#include <bitset>
#include <sstream>
using namespace std;

string toBinary(int n)
{
    return bitset<8>(n).to_string();
}

vector<int> getSubnetMask(int prefixLength)
{
    vector<int> mask(4, 0);
    for (int i = 0; i < prefixLength; ++i)
    {
        mask[i / 8] |= (1 << (7 - (i % 8)));
    }
    return mask;
}

string formatIP(vector<int> ip)
{
    stringstream ss;
    for (size_t i = 0; i < ip.size(); ++i)
    {
        ss << ip[i];
        if (i < ip.size() - 1)
        {
            ss << ".";
        }
    }
    return ss.str();
}

int main()
{
    string ip;
    int prefixLength;

    cout << "Enter an IP address (e.g., 192.168.1.1): ";
    cin >> ip;
    cout << "Enter the subnet prefix length (e.g., 24): ";
    cin >> prefixLength;

    vector<int> ipParts(4);
    sscanf(ip.c_str(), "%d.%d.%d.%d", &ipParts[0], &ipParts[1], &ipParts[2], &ipParts[3]);

    vector<int> subnetMask = getSubnetMask(prefixLength);

    cout << "Subnet Mask: " << formatIP(subnetMask) << endl;

    cout << "Subnet Mask in Binary: ";
    for (int part : subnetMask)
    {
        cout << toBinary(part) << " ";
    }
    cout << endl;

    return 0;
}
