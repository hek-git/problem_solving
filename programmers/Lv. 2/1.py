while True:
    your_name = input('누구십니까?')
    if your_name == '도깨비':
        print('안녕하세요 도꺠비님')
    elif your_name == '저승사자':
        print('또 뵙넹 저승사자님ㄴ')
    elif your_name == 'pass':
        continue
    elif your_name == 'exit':
        break
    else:
        print(your_name, "님은 뉘신지")
    print()
print("안녕히계세요")