#arquivo de teste

#Prototipo em Python 
#Criado em 25-09-2024
# Revisão 1_25_09_2024

import os, io, subprocess, time, codecs, binascii 

from binascii import unhexlify

from io import BytesIO

#----------------------------------------------------------------Localização do arquivo
def get_doc_folder():#Localiza a pasta documentos do windows ou linux
    # toget user
    user=os.path.join(os.environ['USERPROFILE'])
    # to get documents
    path_doc=str(os.path.join(os.path.join(user), 'Documents'))
    
    return path_doc

# Baseado no path dado e no parametro 
# listará os arquivos dentro do local 
# e das subpastas

#----------------------------------------------------------------(96 operações)
#1ª opção:
#converter para string e gravar
#-->use para treinar o programa
def read_txt(path_txt):
    with open(path_txt, "r") as arquivo:
        print(arquivo.read())

def read_txt_2(path_txt):
    with open(path_txt, "rb") as arquivo:
        print(arquivo.read())

def create_txt():
    #será criado na pasta documentos do pc
    
    #96 operações para ula(mantido apenas para análise)
    '''
    5c3,9d4,73b,1ec,045,559,e30,11c,94e,06c,
    103,f69,a0f,fd3,b8a,43a,a47,354,aaa,130,
    2f4,e01,549,c01,b14,65d,ef3,4fb,d97,43f,
    3fd,07a,161,ea5,58e,187,888,d8b,80f,fd1,
    e00,ed4,a9c,fcd,c3e,d47,f7a,37b,535,207,
    027,cbb,18b,a8a,9b6,3c7,2ad,817,931,7ba,
    f4d,d21,104,1ed,019,71e,5ce,928,40d,f0a,
    6e1,6f8,91a,1dd,026,ca8,eb4,31d,b69,3dc,
    7b8,40b,ae8,a7b,0c0,37b,5cb,dc2,9e9,b74,
    a14,d2a,55b,1e9,1b0,6b9'''

    #Após transformar em uma string
    operations_96="5c39d473b1ec045559e3011c94e06c103f69a0ffd3b8a43aa47354aaa1302f4e01549c01b1465def34fbd9743f3fd07a161ea558e187888d8b80ffd1e00ed4a9cfcdc3ed47f7a37b535207027cbb18ba8a9b63c72ad8179317baf4dd211041ed01971e5ce92840df0a6e16f891a1dd026ca8eb431db693dc7b840bae8a7b0c037b5cbdc29e9b74a14d2a55b1e91b06b9"

    path_txt=get_doc_folder()+"\\ac_2_ep_04\\text.txt"

    if not os.path.exists(get_doc_folder()+"\\ac_2_ep_04"):
        os.makedirs(get_doc_folder()+"\\ac_2_ep_04")

    print("No caminho: ",path_txt)
    
    with open(path_txt, "w") as arquivo:
	    arquivo.write(operations_96)
    



#-->Caso não queira basta usar a função abaixo:

#gerar string de bits (96 operações x 12 bits(3 números de 4 bits)=1152 bits(aprox. 144 bytes))
def generate_96_op_12_bits():

    import random

    str_1152=""

    for i in range(1152):
        my_random_float = random.random()

        if my_random_float > .5:
            my_rand_int = 1
        else:
            my_rand_int = 0

        str_1152=str_1152+(str(my_rand_int))
    
    #Exibe string binaria
    print("String de 1152 bits:\n-->",str_1152)
    res = []
    strt = 0

    while strt <1152:
        res.append(str_1152[strt : strt + 8])
        strt += 8

    print("Strings after splitting : ")
    int_i=1

    #exibindo os pseudo-bytes
    for bit in res:
        print("%dº byte: %s\n"% (int_i,bit))
        int_i+=1 
    #criar função grave o arquivo espera-se que seja de 144 bytes

#Command to clear the terminal(Limpa o terminal)
os.system('cls' if os.name == 'nt' else 'clear')
#---------------------------------------------------------------------------Escrita hex to byte
def hex_to_byte_2():
    
    #Conversão para byte
    operations_96='5c39d473b1ec045559e3011c94e06c103f69a0ffd3b8a43aa47354aaa1302f4e01549c01b1465def34fbd9743f3fd07a161ea558e187888d8b80ffd1e00ed4a9cfcdc3ed47f7a37b535207027cbb18ba8a9b63c72ad8179317baf4dd211041ed01971e5ce92840df0a6e16f891a1dd026ca8eb431db693dc7b840bae8a7b0c037b5cbdc29e9b74a14d2a55b1e91b06b9'
    
    r=bytes.fromhex(operations_96)
    print()
    print(r)
    
    s=codecs.decode(operations_96,'hex_codec')
    print()
    print(s)

    write_byte = BytesIO(s)
    print()
    print(write_byte)
    

    t=unhexlify(operations_96)
    print()
    print(t)

    u=binascii.a2b_hex(operations_96)
    print()
    print(u)

    path_txt=get_doc_folder()+"\\ac_2_ep_04\\text.hex"
    #path_txt=get_doc_folder()+"\\ac_2_ep_04\\text.bin"

    if not os.path.exists(get_doc_folder()+"\\ac_2_ep_04"):
        os.makedirs(get_doc_folder()+"\\ac_2_ep_04")

    print("No caminho: ",path_txt)
       
    with open(path_txt, "wb") as arquivo:
    #with open(path_txt, "w") as arquivo:
	    
        arquivo.write(write_byte.getbuffer())

        
    #reversão de byte para string hexadecimal precisará ser feita no c++(dentro do programa do arduino)
#reversão

def revert_from_byte():
    
    operations_96='5c39d473b1ec045559e3011c94e06c103f69a0ffd3b8a43aa47354aaa1302f4e01549c01b1465def34fbd9743f3fd07a161ea558e187888d8b80ffd1e00ed4a9cfcdc3ed47f7a37b535207027cbb18ba8a9b63c72ad8179317baf4dd211041ed01971e5ce92840df0a6e16f891a1dd026ca8eb431db693dc7b840bae8a7b0c037b5cbdc29e9b74a14d2a55b1e91b06b9'

    #Conversão    
    r=bytes.fromhex(operations_96)

    s=b'\\9\xd4s\xb1\xec\x04UY\xe3\x01\x1c\x94\xe0l\x10?i\xa0\xff\xd3\xb8\xa4:\xa4sT\xaa\xa10/N\x01T\x9c\x01\xb1F]\xef4\xfb\xd9t??\xd0z\x16\x1e\xa5X\xe1\x87\x88\x8d\x8b\x80\xff\xd1\xe0\x0e\xd4\xa9\xcf\xcd\xc3\xedG\xf7\xa3{SR\x07\x02|\xbb\x18\xba\x8a\x9bc\xc7*\xd8\x17\x93\x17\xba\xf4\xdd!\x10A\xed\x01\x97\x1e\\\xe9(@\xdf\nn\x16\xf8\x91\xa1\xdd\x02l\xa8\xebC\x1d\xb6\x93\xdc{\x84\x0b\xae\x8a{\x0c\x03{\\\xbd\xc2\x9e\x9bt\xa1M*U\xb1\xe9\x1b\x06\xb9'
    
    #t=codecs.decode(s, 'utf-8')#erro de utf-8
    #print(operations_96)
    print()
    print(r)
    print()
    print(s)
    print()
    #print(t)#erro de utf-8
#---------------------------------------------------------------------------Call function(Testes)
def write_read_txt():
    try:
        print("Criando o arquivo")
        create_txt()
        print("Lendo o arquivo")
        read_txt(get_doc_folder()+"\\ac_2_ep_04\\text.txt")
    except Exception as errno:
        print("Erro was found")
        print(errno)

def write_read_txt_2():
    try:
        print("Criando o arquivo")
        hex_to_byte_2()
        print("Lendo o arquivo")
        read_txt_2(get_doc_folder()+"\\ac_2_ep_04\\text.hex")
    except Exception as errno:
        print("Erro was found")
        print(errno)
#write_read_txt_2()
revert_from_byte()