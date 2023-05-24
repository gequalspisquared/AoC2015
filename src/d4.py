import hashlib

# Part A
data = "ckczppom"
current = 0

while (True):
    current_try = data + str(current)
    current_hash = hashlib.md5(current_try.encode('utf-8')).hexdigest()

    if (str(current_hash)[0:5] == "0"*5):
        break
    else:
        current += 1

print(current_hash)
print(current)

# Part B
current = 0

while (True):
    current_try = data + str(current)
    current_hash = hashlib.md5(current_try.encode('utf-8')).hexdigest()

    if (str(current_hash)[0:6] == "0"*6):
        break
    else:
        current += 1

print(current_hash)
print(current)
