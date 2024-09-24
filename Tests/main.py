#Codigo template para o Exercício Prático 4 de Arquitetura de Computadores II
#previsao de entrega 7 de Outubro de 2024

#Caso haja comentários, é pois esqueci de(não deu para) traduzir 

#Prototipo em Python 
#Criado em 19-09-2024
# Revisão 1_24_09_2024

import serial

import os, subprocess, serial, time
import serial.tools.list_ports


#----------------------------------------------------------------Teste inicial da porta
def prototype_4():
#Fonte: https://embarcados.com.br/python-e-arduino-comunicacao-serial/
    
    # Iniciando conexao serial
    #Linux
    comport = serial.Serial('/dev/ttyUSB0', 9600)
    #comport = serial.Serial('/dev/ttyUSB0', 9600, timeout=1) # Setando timeout 1s para a conexao
    
    #Windows
    #comport = serial.Serial('COM4', 9600)
    #comport = serial.Serial('COM4', 9600, timeout=1) # Setando timeout 1s para a conexao
    
    PARAM_CARACTER='t'
    PARAM_ASCII=str(chr(116))       # Equivalente 116 = t
    
    # Time entre a conexao serial e o tempo para escrever (enviar algo)
    time.sleep(1.8) # Entre 1.5s a 2s
    
    #comport.write(PARAM_CARACTER)
    comport.write(PARAM_ASCII)
    
    VALUE_SERIAL=comport.readline()
    
    print ('\nRetorno da serial: %s' % (VALUE_SERIAL))
    
    # Fechando conexao serial
    comport.close()


#----------------------------------------------------------------Classe para gerenciar o arduino ou Esp32
class MicroController_Board: 
    
    #Se Windows:
    if os.name=="nt":
        def __init__(self, SERIAL_PORT = 'COM4', SERIAL_RATE = 9600): #Windows
            try:
                self.board = serial.Serial(SERIAL_PORT, SERIAL_RATE,timeout=1)
                print("Microcontroller connected")
            except:
                print("No Microcontroller connected")
    else:
        #Caso seja Linux:
        def __init__(self, SERIAL_PORT = '/dev/ttyUSB0', SERIAL_RATE = 9600): #Linux
            try:
                self.board = serial.Serial(SERIAL_PORT, SERIAL_RATE,timeout=1)
                print("Microcontroller connected")
            except:
                print("No Microcontroller connected")
    #Conexão
    def connect(self):
        print("Start")
        try:
            self.board.flushInput()
            print("Connected")
        except:
            print("Connect Microcontroller")
   
    #Verificação da conexão como função
    def is_Open(self):
        
        if self.board.isOpen():
        
            return True
        
        else:
        
            return False

     #Envio de dados com feedback da porta   
    def send_command(self, message=0):
        print("Write/Read on serial")
        try:
            #check to see if the connection is open
            if self.board.isOpen():
                
                #if true, send message to receive the output from the microcontroller board
                self.board.write(str.encode(str(message)))
                
                #Feedback
                print("Data sent to Arduino")
                
                time.sleep(1) #wait some time to read

                #loop to print all the output lines
                while True:
                    #verify if exists input values on serial port
                    if self.board.in_waiting>0:
                        #read the output and store it in a variable
                        input_data = self.board.readline()
                        #Check to see if all the lines of the output are printed
                        if(len(input_data))>0:    
                            
                            #print("Readed: ",input_data.decode())
                            
                            print("Read: ",input_data.decode('utf-8').rstrip())
                        else:
                            break;
        
        except Exception as errno:
            print("Erro was found")
            print(errno)

    #Somente para escrever ns porta serial
    def only_write(self,cmd=0):
        print("Only write on serial")
        try:
            #check to see if the connection is open
            if self.board.isOpen():
                while True:
                    cmd=cmd+'\r'
                    self.board.write(cmd.encode())
        except Exception as errno:
            print("Erro was found")
            print(errno)

    #Somente para ler a porta serial
    def only_read(self):
        print("Only read on serial")
        try:
            #check to see if the connection is open
            if self.board.isOpen():
                
                time.sleep(1) #wait some time to read

                #loop to print all the output lines
                while True:
                    #verify if exists input values on serial port
                    if self.board.in_waiting>0:
                        #read the output and store it in a variable
                        input_data = self.board.readline()
                        #Check to see if all the lines of the output are printed
                        if(len(input_data))>0:    
                            
                            #print("Readed: ",input_data.decode())
                            
                            print("Read: ",input_data.decode('utf-8').rstrip())
                        else:
                            break;
        
        except Exception as errno:
            print("Erro was found")
            print(errno)

    #Fecha a conexão com a porta serial
    def close_connection(self):
        try:
            self.board.close()
            print("Done")
        except:
            print("Connect Microcontroller")




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
def list_files(path_f,pattern_f):
    
    from fnmatch import fnmatch

    root = path_f
    
    pattern = pattern_f

    find_files=[]

    #Leitura e adição em um vetor de caminhos
    for path, subdirs, files in os.walk(root):
        
        for name in files:
            
            if fnmatch(name, pattern):
                
                file_p=os.path.join(path, name)
                
                find_files.append(file_p)
    
    #Exibe cada caminho encontrado
    for file_x in find_files:
        
        print(file_x)          
    
    #Leitura do caminho escolhido
    with open(find_files[0], "r") as fp:
        
        #Leitura da primeira linha
        lines = fp.readline()
        
        #Checagem
        if(('inicio:' in lines)|('Inicio:' in lines)):

            lines = fp.readlines()#Leitura das demais linhas
            
            for i in lines:
                
                if ((i =="fim." )| (i =="Fim.")): #se chegar o fim
                    
                    break#interrompe
                else:
                    
                    print(i)#Exibe linha
        else:
            
            print("wrong command text")#feedback

def set_path_read():#Escolha do usuário para configurar o path do arquivo
    
    print("Set local to read:")
    print("1)--->Path")
    print("2)--->Users/Documents")
    result=input("Choose a option, please: ")
    if result==1:
        path_f=input("Set a path, please: ")
        list_files(path_f,"*.pdf")
    elif result==2:
        list_files(get_doc_folder(),"*.pdf")
    else:
        print ("not recognized")
        

#Analise do mnemonico enviado versão 2
def set_op_code_beta(mnemonic):
    
    dict_op_codes={
        'umL':'0',
        'AonB':'1',
        'copiaA':'2',
        'nAxnB':'3',
        'AeBn':'4',
        'nA':'5',
        'AenB':'6',
        'nAonB': '7',
        'AxB':'8',
        'zeroL':'9',
        'copiaB':'A',
        'AeB':'B',
        'nB':'C',
        'nAeBn':'D',
        'AoB':'E',
        'nAeB':'F'}
    if mnemonic in dict_op_codes:
        return dict_op_codes.get(mnemonic)
    else:
        print ("not recognized")
        return -1
    
#Analise do mnemonico enviado versão 1
def set_op_code_alpha(mnemonic):
    
    if mnemonic=='umL':
        return '0'
    elif mnemonic=='AonB':
        return '1'
    elif mnemonic=='copiaA':
        return '2'
    elif mnemonic=='nAxnB':
        return '3'
    elif mnemonic=='AeBn':
        return '4'
    elif mnemonic=='nA':
        return '5'
    elif mnemonic=='AenB':
        return '6'
    elif mnemonic=='nAonB':
        return '7'
    elif mnemonic=='AxB':
        return '8'
    elif mnemonic=='zeroL':
        return '9'
    elif mnemonic=='copiaB':
        return 'A'
    elif mnemonic=='AeB':
        return 'B'
    elif mnemonic=='nB':
        return 'C'
    elif mnemonic=='nAeBn':
        return 'D'
    elif mnemonic=='AoB':
        return 'E'
    elif mnemonic=='nAeB':
        return 'F'
    else:
        print ("not recognized")
        return -1

def check_result(mnemonic,result): 
    
    if result==-1:
        print(("A chave %s não possui o valor associado. "%(mnemonic)))
    else:
        print("O Dicionário possui a chave: %s"%(mnemonic))
        print("e a chave %s possui o valor: %s"%(mnemonic,result)) 

def show_mnemonic():#Teste das 2 versões
    #mnemonico v1:
    mnemonic= 'umL'
    print("mnemonico v1")
    print("O Dicionário possui a chave: %s ?"%(mnemonic))
    result=set_op_code_alpha(mnemonic)
    check_result(mnemonic,result)    
    print()
    #mnemonico v2:
    print("mnemonico v2")
    print("O Dicionário possui a chave: %s ?"%(mnemonic))
    result2=set_op_code_beta(mnemonic)
    check_result(mnemonic,result2)

#----------------------------------------------------------------Teste pratico da conexão com o Arduino/Esp32
def test_serial():
    
    #Create a variable
    controller = MicroController_Board()    
    # Connect to Arduino
    controller.connect()

    #Some command to Arduino
    message="Hello Arduino"

    # Send a command to Arduino
    controller.send_command(message)

    #Close the serial connection
    controller.close_connection()

#----------------------------------------------------------------(96 operações)
#1ª opção:
#converter para string e gravar
#-->use para treinar o programa
def read_txt(path_txt):
    with open(path_txt, "r") as arquivo:
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
    
def write_read_txt():
    try:
        print("Criando o arquivo")
        create_txt()
        print("Lendo o arquivo")
        read_txt(get_doc_folder()+"\\ac_2_ep_04\\text.txt")
    except Exception as errno:
        print("Erro was found")
        print(errno)


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

#---------------------------------------------------------------------------Call function(Testes)
#test_serial()  #Arduino

#Coloque qualquer arquivo .ula na pasta documentos para testar por favor
#list_files(get_doc_folder(),"*.ula") #Leitura do arquivo

#show_mnemonic() #Testes das funções de mnemonicos

#generate_96_op_12_bits() #String de bits

write_read_txt()#Criação e leitura do arquivo