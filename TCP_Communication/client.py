# tcp_client.py
import socket

# Step 1: Create a TCP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Step 2: Connect to the server
client_socket.connect(('localhost', 8080))

# Step 3: Send filename
filename = input("Enter filename to request: ")
client_socket.send(filename.encode())

# Step 4: Receive file content
data = client_socket.recv(4096).decode()
print("\n--- File Content ---\n")
print(data)

# Step 5: Close connection
client_socket.close()
