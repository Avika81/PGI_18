def asm_to_string_array(file):
    lis = open(file)
    c = 0
    for line in lis:
        c+=1
    lis = open(file)
    lines = []
    for i in range(c):
        lines.append(lis.readline().split())
    lis = []
    for i in range(len(lines)):
        for j in range(len(lines[i])):
            lis.append(lines[i][j])
        lis.append("\n")
    return lis


def string_to_int(string):
    num = 0
    for c in string:
        num = (num * 256) + ord(c)
    return num
myFile = open("datasets.txt","wb")
for i in range (1,11):
    name =  str(i) + ".cpp"
    for j in range(len(asm_to_string_array(name))):
        myFile.write(asm_to_string_array(name)[j]+" ")


