def xor(dividend, divisor):
    result = []
    for i in range(len(divisor)):
        result.append(0 if dividend[i] == divisor[i] else 1)
    return result

def divide(data, generator):
    temp = data[:len(generator)]
    for i in range(len(generator), len(data)):
        if temp[0] == 1:
            temp = xor(temp, generator)
        else:
            temp = xor(temp, [0]*len(generator))
        temp.append(data[i])
        temp.pop(0)
    if temp[0] == 1:
        temp = xor(temp, generator)
    else:
        temp = xor(temp, [0]*len(generator))
    return temp

frame = list(map(int, input("Enter Frame (bits): ").strip()))
generator = list(map(int, input("Enter Generator (bits): ").strip()))

appended_data = frame + [0] * (len(generator) - 1)
print("Message after appending 0's:", appended_data)

remainder = divide(appended_data[:], generator)
print("CRC bits:", remainder)

transmitted_frame = frame + remainder
print("Transmitted Frame:", transmitted_frame)

# Receiver side
received = transmitted_frame[:]
print("Received Frame:", received)

check_remainder = divide(received, generator)
print("Remainder at receiver side:", check_remainder)

if all(bit == 0 for bit in check_remainder):
    print("Message is correct (No Error).")
else:
    print("Error detected in received message.")
