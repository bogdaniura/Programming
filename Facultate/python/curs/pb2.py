def validare_pb2(n, vec):
    if n % 2 != 0 or n < 1 or n > 100:
        return 0
    else:
        for i in range(n):
            if vec[i] != int(vec[i]) or int(vec[i]) > 1000000000:
                return 0
    return 1



def pb2():
    n = int(input())
    vec, vec3 = [], []
    for i in range(n):
        vec.append(int(input()))
    if validare_pb2(n, vec):
        print("datele introduse corespund cerintei")
        vec1 = sorted(vec[:n//2], reverse = False)  #indicii merg de la 0 la n-1
        vec2 = sorted(vec[n//2:], reverse = True)
        vec3.append(vec1)
        vec3.append(vec2)
        print(vec3)            
        
    else:
        print("datele introduse nu corespund cerintei")


if __name__ == "__main__":
    # pb1()
    pb2()
    # pb3()