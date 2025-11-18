# udp_client.py
import socket

# Step 1: Create UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ('localhost', 8081)
filename = input("Enter filename to request: ")

# Step 2: Send filename to server
client_socket.sendto(filename.encode(), server_address)

# Step 3: Receive response
data, _ = client_socket.recvfrom(4096)
print("\n--- File Content ---\n")
print(data.decode())

# Step 4: Close socket
client_socket.close()
