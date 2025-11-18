#include <iostream>
#include <string>
using namespace std;

// XOR operation between two binary strings
string xorOperation(string a, string b) {
    string result = "";
    for (int i = 1; i < b.length(); i++)
        result += (a[i] == b[i] ? '0' : '1');
    return result;
}

// Perform CRC Division
string crcDivide(string data, string poly) {
    int polyLen = poly.length();
    string temp = data.substr(0, polyLen);

    int i = polyLen;
    while (i < data.length()) {
        if (temp[0] == '1')
            temp = xorOperation(temp, poly) + data[i];
        else
            temp = xorOperation(temp, string(polyLen, '0')) + data[i];
        i++;
    }

    // Final step
    if (temp[0] == '1')
        temp = xorOperation(temp, poly);
    else
        temp = xorOperation(temp, string(polyLen, '0'));

    return temp;  // remainder = CRC
}

int main() {
    string data, poly;

    cout << "Enter data to be transmitted: ";
    cin >> data;
    cout << "Enter divisor polynomial: ";
    cin >> poly;

    int polyLen = poly.length();

    // Append zeros to data
    string appendedData = data + string(polyLen - 1, '0');

    // Calculate CRC
    string crc = crcDivide(appendedData, poly);

    cout << "CRC value is: " << crc << endl;

    // Final transmitted data
    string transmitted = data + crc;
    cout << "Final data to be sent: " << transmitted << endl;

    // -------- Receiver Side --------
    string recv;
    cout << "\nEnter the received data: ";
    cin >> recv;

    string remainder = crcDivide(recv, poly);

    bool error = false;
    for (char c : remainder)
        if (c == '1') error = true;

    if (error)
        cout << "Error detected!" << endl;
    else
        cout << "No error detected." << endl;

    return 0;
}


O/p:
Enter data to be transmitted: 101010
Enter divisor polynomial: 1011
CRC value is: 001
Final data to be sent: 101010001

Enter the received data: 10010001
Error detected!
