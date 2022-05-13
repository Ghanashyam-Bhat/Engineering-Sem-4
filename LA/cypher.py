def modInverse(a, m=26):
    for x in range(1, m):
        if (((a%m) * (x%m)) % m == 1):
            return x
    return -1

def encrypt(s,k):
    s = list(s)
    m = []
    result = []
    for i in range(0,len(s),2):
        x = []
        x.append(ord(s[i])-ord('A'))
        x.append(ord(s[i+1])-ord('A'))
        m.append(x)
        result.append([])
    
    for i in range(len(m)):
        result[i].append((k[0][0]*m[i][0]+k[0][1]*m[i][1])%26)
        result[i].append((k[1][0]*m[i][0]+k[1][1]*m[i][1])%26)

    en = []
    for i in range(len(result)):
        en.append(chr(result[i][0]+ord('A')))
        en.append(chr(result[i][1]+ord('A')))

    en_s = "".join(en)
    return en_s

def decrypt(s,k):
    #Finding Inverse
    det = (k[0][0]*k[1][1])-(k[0][1]*k[1][0])
    temp = k[0][0]
    det = modInverse(det)
    k[0][0] = det*((k[1][1])%26)
    k[1][1] = det*((temp)%26)
    k[0][1] = det*((k[0][1]*-1)%26)
    k[1][0] = det*(((k[1][0]*-1))%26)

    return encrypt(s,k)

s = "UTESXX"
k =  [[3,3],[2,5]] #Key : Invertible matrix with det!=2,13,26
x = encrypt(s,k)
print("Given text: " +s)
print("Encrypted text: "+x)
print("After decryption: "+decrypt(x,k))