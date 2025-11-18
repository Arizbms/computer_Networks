#include <iostream>
using namespace std;

int main() {
    int bucketSize, incoming, outgoing, stored = 0;

    cout << "Enter bucket size: ";
    cin >> bucketSize;

    cout << "Enter outgoing rate: ";
    cin >> outgoing;

    cout << "Enter number of incoming packets: ";
    cin >> incoming;

    int packets;

    while (incoming--) {
        cout << "\nEnter incoming packet size: ";
        cin >> packets;

        // If packet + stored exceeds bucket capacity → drop
        if (packets + stored > bucketSize) {
            cout << "Bucket overflow! " << (packets - (bucketSize - stored))
                 << " packet(s) dropped!\n";
            stored = bucketSize;  
        } else {
            stored += packets;
            cout << "Packet stored. Current bucket content: " << stored << endl;
        }

        // leak outgoing packets
        if (stored > outgoing) {
            stored -= outgoing;
        } else {
            stored = 0;
        }

        cout << "Packets left in bucket after leaking: " << stored << endl;
    }

    return 0;
}


O/p:
Enter bucket size: 5000
Enter outgoing rate: 2000
Enter number of incoming packets: 2

Enter incoming packet size: 3000
Packet stored. Current bucket content: 3000
Packets left in bucket after leaking: 1000

Enter incoming packet size: 1000
Packet stored. Current bucket content: 2000
Packets left in bucket after leaking: 0
