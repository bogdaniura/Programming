if __name__ == "__main__":
    file1 = open("/home/kgbeast/Bogdan/Programming/python/laborator/in.txt", "r+")
    file2 = open("/home/kgbeast/Bogdan/Programming/python/laborator/in2.txt", "w")
    ###metoda1
    # txt = file1.read()
    # v = txt.split("\n")
    # print(v)
    # flag = False
    # for i in range(len(v)):
    #     if v[i].startswith("7") and not flag:
    #         v.insert(i, "insereaza aici")
    #         flag = True
    # print(v)
    # for e in v:
    #     file2.write(e)

    ###metoda2
    line = file1.readline()
    while line:
        flag = False
        if line.startswith("3") and not flag:
            file2.seek(file1.tell() - len(line))
            file2.write("insereaza\n")
            flag = True
        else:
            file2.write(line)
        line = file1.readline()
    file1.close()

    # v = file.read()
    # vector = v.split("\n")
    # for each in file:
    #     print(each)
    # print(file.tell())
    # file.seek(6)
    # file.readline()
    # print(file.tell())
    # print(v, "\n", vector)
    # write, seek, tell
