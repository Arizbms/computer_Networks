# udp_server.py
import socket

# Step 1: Create UDP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Step 2: Bind it to an address
server_socket.bind(('localhost', 8081))
print("UDP Server is ready...")

while True:
    # Step 3: Receive filename from client
    filename, addr = server_socket.recvfrom(1024)
    filename = filename.decode()
    print(f"Requested file: {filename}")

    try:
        # Step 4: Read file and send data
        with open(filename, 'r') as f:
            data = f.read()
            server_socket.sendto(data.encode(), addr)
    except FileNotFoundError:
        server_socket.sendto(b"File not found on server.", addr)
