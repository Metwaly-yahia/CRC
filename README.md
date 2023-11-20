# Cyclic Redundancy Check (CRC):
The CRC is a network method designed to detect errors in the data and information transmitted over the network. This is performed by performing a binary solution on the transmitted data at the sender’s side and verifying the same at the receiver’s side.
The term CRC is used to describe this method because Check represents the data verification, Redundancy refers to the recheck method and Cyclic points to the algorithmic formula.

## Working of CRC Method
![image](https://github.com/Metwaly-yahia/CRC/assets/81784667/b5e84272-f854-47b4-9b5f-4d7fe68908da)

To understand the working of the CRC method, we will divide the steps into two parts:

### Sender Side (CRC Generator and Modulo Division):
1. The first step is to add the no. of zeroes to the data to be sent, calculated using k-1 (k: is the number of bits of the divisor.)
2. Applying the Modulo Binary Division to the data bit by applying the XOR and obtaining the remainder from the division
3. The last step is to append the remainder to the end of the data bit and share it with the receiver.

### Receiver Side (Checking for errors in the received data):
To check the error, perform the Modulo division again and check whether the remainder is 0 or not, 
1. If the remainder is 0, the data bit received is correct, without any errors.
2. If the remainder is not 0, the data received is corrupted during transmission.
