
import socket

# Step 1: Create a TCP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Step 2: Bind it to an address and port
server_socket.bind(('localhost', 8080))

# Step 3: Listen for client connection
server_socket.listen(1)
print("Server is listening on port 8080...")

# Step 4: Accept client connection
conn, addr = server_socket.accept()
print("Connected by:", addr)

# Step 5: Receive file name from client
filename = conn.recv(1024).decode()

try:
    # Step 6: Open file and read contents
    with open(filename, 'r') as f:
        data = f.read()
        conn.send(data.encode())   # Send file contents

except FileNotFoundError:
    conn.send(b"File not found on server.")

# Step 7: Close connection
conn.close()
server_socket.close()
